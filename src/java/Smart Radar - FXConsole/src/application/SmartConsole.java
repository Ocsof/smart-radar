package application;

public class SmartConsole {
	private final CommChannel channel = new SerialCommChannel("COM10",9600);
	SampleController controller;
	
	public SmartConsole(SampleController contr) throws InterruptedException {
		controller = contr;
		communicating();
	}
		
	public void communicating() throws InterruptedException {
		Thread thread = new Thread(){
			public void run(){
				while(true) {
					try {
						Thread.sleep(1000);
						controller.setText("Ready");
						while(true) {
							if(channel.isMsgAvailable()) {								
								String msg = channel.receiveMsg();
								if(msg.equals("on")) {
									controller.setAlarm(true);
								} else if(msg.equals("off")) {
									controller.setAlarm(false);
								} else {
									controller.setText("Received:  " + msg);	
								}
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
		
	public CommChannel getChannel() {
		return this.channel;
	}
}

