package view;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.TextArea;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class ConsoleView {
	
	private JFrame frame;
	private JPanel modePanel;
	private JPanel speedPanel;
	private JPanel consolePanel;
	JTextArea console;
	
	public ConsoleView() {
		createView();
	}

	private void createView() {
		frame = new JFrame("Smart Radar - Console");
		frame.setLayout(new BorderLayout());
		frame.setSize(1200, 800);
		frame.setResizable(true);
		frame.setVisible(true);
		
		modePanel = new JPanel(new GridLayout(3, 1));
		JButton singleButton = new JButton("SINGLE");
		JButton manualButton = new JButton("MANUAL");
		JButton autoButton = new JButton("AUTO");
		modePanel.add(singleButton);
		modePanel.add(manualButton);
		modePanel.add(autoButton);
		
		speedPanel = new JPanel(new GridLayout(4, 1));
		JButton usButton = new JButton("ULTRA SLOW");
		JButton sButton = new JButton("SLOW");
		JButton fButton = new JButton("FAST");
		JButton ufButton = new JButton("ULTRA FAST");
		speedPanel.add(usButton);
		speedPanel.add(sButton);
		speedPanel.add(fButton);
		speedPanel.add(ufButton);
		
		consolePanel = new JPanel();
		console = new JTextArea();
		consolePanel.add(console);
		
		frame.add(modePanel, BorderLayout.WEST);
		frame.add(speedPanel, BorderLayout.EAST);
		frame.add(consolePanel, BorderLayout.SOUTH);
		
	}
	
	public void addText(final String testo) {
		console.append(testo);
	}
}
