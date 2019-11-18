package controller;

import view.ConsoleView;

public class SmartConsole {
	private final CommChannel channel = new SerialCommChannel("COM1",9600);
	private final KeyboardListener kl = new KeyboardListener(this);
	private final ConsoleView view = new ConsoleView();
	
	
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
					try {
						Thread.sleep(1000);
					} catch (InterruptedException e) {
						e.printStackTrace();
					}
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
