package application;

import javafx.scene.control.TextArea;

public class SmartConsole {
	private final CommChannel channel = new SerialCommChannel("COM1",9600);
	private TextArea myConsole;
	
	public SmartConsole(final TextArea ta) throws InterruptedException {
		myConsole = ta;
		communicating();
	}
		
	public void communicating() throws InterruptedException {
		Thread thread = new Thread(){
			public void run(){
				while(true) {
					try {
						myConsole.appendText("Arduino");
						System.out.println("Waiting Arduino for rebooting...");		
						Thread.sleep(4000);
						System.out.println("Ready.");
						
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
				}
			}
		};
		thread.start();
	}
	
//	public void keyPressed(String msg) {		
//		System.out.println("key pressed");
//		channel.sendMsg(msg);
//	}
		
	public CommChannel getChannel() {
		return this.channel;
	}
}


//		System.out.println("Sending ping");
//		channel.sendMsg("ping");
//		String msg = channel.receiveMsg();
//		System.out.println("Received: "+msg);		
//		Thread.sleep(500);
//		channel.close();
