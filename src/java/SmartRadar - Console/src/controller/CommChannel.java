package controller;

public interface CommChannel {
	
	/**
	 * Send a message represented by a string (without new line).
	 * @param msg
	 */
	void sendMsg(String msg);
	
	/**
	 * To receive a message.
	 */
	String receiveMsg() throws InterruptedException;

	/**
	 * To check if a message is available.
	 * 
	 * @return
	 */
	boolean isMsgAvailable();
	
	/**
	 * Close the port.
	 */
	void close();

}
