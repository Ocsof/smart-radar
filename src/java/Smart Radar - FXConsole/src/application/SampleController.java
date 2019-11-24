package application;

import javafx.fxml.FXML;
import javafx.geometry.Insets;
import javafx.scene.control.TextArea;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.paint.Color;

public class SampleController {
	
	private SmartConsole console;
	@FXML
	private TextArea myConsole;
	private boolean alarm;
	private int counter;
	
	public SampleController() throws InterruptedException {
		console = new SmartConsole(this);
		this.alarm = false;
		this.counter = 0;
	}
	
	public void singleClicked() {
		console.getChannel().sendMsg(MessageType.SINGLE.toString());
		this.setText("Mode changed to: SINGLE");
	}
	
	public void manualClicked() {
		console.getChannel().sendMsg(MessageType.MANUAL.toString());
		this.setText("Mode changed to: MANUAL");
	}
	
	public void autoClicked() {
		console.getChannel().sendMsg(MessageType.AUTO.toString());
		this.setText("Mode changed to: AUTO");
	}

	public void ultraslowClicked() {
		console.getChannel().sendMsg(MessageType.ULTRASLOW.toString());
		this.setText("Speed set to: ULTRASLOW");
	}

	public void slowClicked() {
		console.getChannel().sendMsg(MessageType.SLOW.toString());
		this.setText("Speed set to: SLOW");
	}

	public void normalClicked() {
		console.getChannel().sendMsg(MessageType.NORMAL.toString());
		this.setText("Speed set to: NORMAL");
	}
	
	public void fastClicked() {
		console.getChannel().sendMsg(MessageType.FAST.toString());
		this.setText("Speed set to: FAST");
	}
	
	public void handleKeyPressed(KeyEvent ke){
		switch(ke.getCode()) {		
			case LEFT:
				console.getChannel().sendMsg(MessageType.LEFT.toString());
				this.setText("Rotating Sonar to LEFT");
				break;
			case RIGHT:
				console.getChannel().sendMsg(MessageType.RIGHT.toString());
				this.setText("Rotating Sonar to RIGHT");
				break;
			default:
			break;
		}
	}
	
	public void setAlarm(boolean isOn) {
		if(isOn && isOn != this.alarm) {
			myConsole.setBackground(new Background(new BackgroundFill(Color.RED, CornerRadii.EMPTY, Insets.EMPTY)));
			this.setText("---------ALLARME--------");
			this.alarm = isOn;
		} 
		if(!isOn && isOn != this.alarm) {
			myConsole.setBackground(new Background(new BackgroundFill(Color.BLACK, CornerRadii.EMPTY, Insets.EMPTY)));
			this.setText("---------fine allarme :) --------");
			this.alarm = isOn;
		}
	}
	
	public void setText(String msg) {
		if(this.counter == 300) {
			myConsole.setText(msg);
			this.counter = 0;
		}else {
			myConsole.appendText("\n" + msg);
			this.counter++;
		}
		
		
	}
}
