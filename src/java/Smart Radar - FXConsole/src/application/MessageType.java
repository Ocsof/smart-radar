package application;

public enum MessageType {
	
	AUTO("1"),
	
	MANUAL("2"),
	
	SINGLE("3"),
	
	ULTRASLOW("4"),
	
	SLOW("5"),
	
	NORMAL("6"),
	
	FAST("7");
	
	private final String name;
    /**
     * Construct a {@code MainMenuOption}.
     * @param name of main menu option
     */
    MessageType(final String name) {
        this.name = name;
    }
    /**
     * To string method.
     * @return name associate to each MainMenuOption
     */
    public String toString() {
        return name;
    }
}
