package application;

import javafx.scene.control.TextArea;

public class SampleController {
	
	private SmartConsole console;
	public TextArea myConsole;
	
	public SampleController() {
		try {
			console = new SmartConsole(myConsole);
			
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	public void singleClicked() {
		console.getChannel().sendMsg(MessageType.SINGLE.toString());
	}
	
	public void manualClicked() {
		console.getChannel().sendMsg(MessageType.MANUAL.toString());
	}
	
	public void autoClicked() {
		console.getChannel().sendMsg(MessageType.AUTO.toString());
	}

	public void ultraslowClicked() {
		console.getChannel().sendMsg(MessageType.ULTRASLOW.toString());
	}

	public void slowClicked() {
		console.getChannel().sendMsg(MessageType.SLOW.toString());
	}

	public void normalClicked() {
		console.getChannel().sendMsg(MessageType.NORMAL.toString());
	}
	
	public void fastClicked() {
		console.getChannel().sendMsg(MessageType.FAST.toString());
	}
}
