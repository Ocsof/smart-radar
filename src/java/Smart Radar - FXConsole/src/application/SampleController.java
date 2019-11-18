package application;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.input.KeyEvent;

public class SampleController {
	
	private SmartConsole console;
	@FXML
	private TextArea myConsole;
	
	public SampleController() throws InterruptedException {
		console = new SmartConsole(this);
	}
	
	public void singleClicked() {
		console.getChannel().sendMsg(MessageType.SINGLE.toString());
		myConsole.appendText("\n" + "Mode changed to: SINGLE");
	}
	
	public void manualClicked() {
		console.getChannel().sendMsg(MessageType.MANUAL.toString());
		myConsole.appendText("\n" + "Mode changed to: MANUAL");
	}
	
	public void autoClicked() {
		console.getChannel().sendMsg(MessageType.AUTO.toString());
		myConsole.appendText("\n" + "Mode changed to: AUTO");
	}

	public void ultraslowClicked() {
		console.getChannel().sendMsg(MessageType.ULTRASLOW.toString());
		myConsole.appendText("\n" + "Speed set to: ULTRASLOW");
	}

	public void slowClicked() {
		console.getChannel().sendMsg(MessageType.SLOW.toString());
		myConsole.appendText("\n" + "Speed set to: SLOW");
	}

	public void normalClicked() {
		console.getChannel().sendMsg(MessageType.NORMAL.toString());
		myConsole.appendText("\n" + "Speed set to: NORMAL");
	}
	
	public void fastClicked() {
		console.getChannel().sendMsg(MessageType.FAST.toString());
		myConsole.appendText("\n" + "Speed set to: FAST");
	}
	
	public void handleKeyPressed(KeyEvent ke){
		switch(ke.getCode()) {		
			case LEFT:
				console.getChannel().sendMsg("LEFT");
				myConsole.appendText("\n" + "Rotating Sonar to LEFT");
			case RIGHT:
				console.getChannel().sendMsg("RIGHT");
				myConsole.appendText("\n" + "Rotating Sonar to RIGHT");
			default:
			break;
		}
		 //System.out.println("Key Pressed: " + ke.getCode());
	}
	
	public void setText(String msg) {
		myConsole.appendText("\n" + msg);
	}
}
