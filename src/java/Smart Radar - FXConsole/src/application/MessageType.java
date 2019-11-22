package application;

public enum MessageType {
	
	AUTO("13"),
	
	MANUAL("12"),
	
	SINGLE("11"),
	
	ULTRASLOW("21"),
	
	SLOW("22"),
	
	NORMAL("23"),
	
	FAST("24"),
	
	RIGHT("2"),
	
	LEFT("1");
	
	private final String name;
    
    MessageType(final String name) {
        this.name = name;
    }
    
    public String toString() {
        return name;
    }
}
