package application;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

import jssc.*;

public class SerialCommChannel implements CommChannel, SerialPortEventListener {

	private SerialPort serialPort;
	private BlockingQueue<String> queue;
	private StringBuffer currentMsg = new StringBuffer("");
	
	public SerialCommChannel(final String port,final int baudrate) {
		this.queue = new ArrayBlockingQueue<String>(100);
		this.serialPort = new SerialPort(port);
		
		try {
			serialPort.openPort();
			serialPort.setParams(baudrate, SerialPort.DATABITS_8, SerialPort.STOPBITS_1, SerialPort.PARITY_NONE);
			serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN | SerialPort.FLOWCONTROL_RTSCTS_OUT);
			serialPort.addEventListener(this);
		} catch(SerialPortException ex) {
			System.out.println("Error writing to the port: " + ex);
		}
	}
	
	@Override
	public void sendMsg(String msg) {
		//char[] array = (msg+"\n").toCharArray();
		int num = Integer.parseInt(msg);
		int[] array = {num};
		byte[] bytes = new byte[array.length];
		for (int i = 0; i < array.length; i++){
			bytes[i] = (byte) array[i];
		}

		try {
			synchronized (serialPort) {
				serialPort.writeBytes(bytes);
			}
		} catch(Exception ex){
			System.out.println("Error sending bytes to the port.");
			ex.printStackTrace();
		}
	}

	@Override
	public String receiveMsg() throws InterruptedException {
		return queue.take();
	}

	@Override
	public boolean isMsgAvailable() {
		return !queue.isEmpty();
	}

	@Override
	public void serialEvent(SerialPortEvent event) {
		/* if there are bytes received in the input buffer */
		if (event.isRXCHAR()) {
			try {
				String msg = serialPort.readString(event.getEventValue());
				msg = msg.replaceAll("\r", "");
				currentMsg.append(msg);
				boolean goAhead = true;
				while(goAhead) {
					String msg2 = currentMsg.toString();
					int index = msg2.indexOf("\n");
					if (index >= 0) {
						queue.put(msg2.substring(0, index));
						currentMsg = new StringBuffer("");
						if (index + 1 < msg2.length()) {
							currentMsg.append(msg2.substring(index + 1));
						}
					} else {
						goAhead = false;
					}
				}
			} catch (Exception ex) {
				ex.printStackTrace();
				System.out.println("Error in receiving string from COM-port: " + ex);
			}
		}
	}
	
	/**
	 * This should be called when you stop using the port.
	 */
	@Override
	public void close() {
		try {
			if (serialPort != null) {
				serialPort.removeEventListener();
				serialPort.closePort();
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		}
	}
}
