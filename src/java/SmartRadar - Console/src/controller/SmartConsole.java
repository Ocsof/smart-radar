package controller;

public class SmartConsole {
	CommChannel channel = new SerialCommChannel("COM1",9600);
	KeyboardListener kl = new KeyboardListener(this);
	int a = 0;
	
	public SmartConsole() throws InterruptedException {
		communicating();
	}
		
	public void communicating() throws InterruptedException {
//		System.out.println("Waiting Arduino for rebooting...");		
//		Thread.sleep(4000);
//		System.out.println("Ready.");		
//
//
//		System.out.println("Sending ping");
//		channel.sendMsg("ping");
//		String msg = channel.receiveMsg();
//		System.out.println("Received: "+msg);		
//		Thread.sleep(500);
//		channel.close();		
		Thread thread = new Thread(){
		    public void run(){
		    	while(true) {
					System.out.println("loop" + a);
					try {
						Thread.sleep(500);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
					a++;
				}
		    }
		  };
		  thread.start();
		
		
	}
	
	public void keyPressed(String msg) {		
		System.out.println("key pressed");
		//channel.sendMsg(msg);
	}
		
}
