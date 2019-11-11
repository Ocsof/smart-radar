package controller;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class KeyboardListener implements KeyListener {
	
	private SmartConsole sc;
	
	public KeyboardListener(SmartConsole sc) {
		this.sc = sc;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void keyPressed(KeyEvent e) {
		switch (e.getKeyCode()) {
		
		case KeyEvent.VK_LEFT:
			sc.keyPressed("l");
			break;
		case KeyEvent.VK_RIGHT:
			sc.keyPressed("r");
			break;
		case KeyEvent.VK_A:
			sc.keyPressed("a");
			break;
		case KeyEvent.VK_S:
			sc.keyPressed("s");
			break;
		case KeyEvent.VK_M:
			sc.keyPressed("m");
			break;
		default:
			break; 
		}
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void keyReleased(KeyEvent arg0) {
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void keyTyped(KeyEvent arg0) {
	}
	
	
}
