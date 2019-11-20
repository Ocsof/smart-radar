package application;

public enum MessageType {
	
	AUTO("1"),
	
	MANUAL("2"),
	
	SINGLE("3"),
	
	ULTRASLOW("4"),
	
	SLOW("5"),
	
	NORMAL("6"),
	
	FAST("7"),
	
	RIGHT("8"),
	
	LEFT("9");
	
	private final String name;
    
    MessageType(final String name) {
        this.name = name;
    }
    
    public String toString() {
        return name;
    }
}
