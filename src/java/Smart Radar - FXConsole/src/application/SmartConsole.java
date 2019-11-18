package application;

public class SmartConsole {
	private final CommChannel channel = new SerialCommChannel("COM3",9600);
	SampleController controller;
	
	public SmartConsole(final SampleController contr) throws InterruptedException {
		controller = contr;
		communicating();
	}
		
	public void communicating() throws InterruptedException {
		Thread thread = new Thread(){
			public void run(){
				while(true) {
					try {		
						controller.setText("Waiting Arduino to connect..");
						Thread.sleep(3000);
						controller.setText("Ready");
						while(true) {
							if(channel.isMsgAvailable()) {								
								String msg = channel.receiveMsg();
								controller.setText("Received: " + msg);		
							}
						}
					} catch (InterruptedException e) {
						channel.close();
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
//		Thread.sleep(500);
//		channel.close();
