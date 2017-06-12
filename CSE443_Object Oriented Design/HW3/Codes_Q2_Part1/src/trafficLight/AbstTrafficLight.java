package trafficLight;

public abstract class AbstTrafficLight {
	
	private int waitTimeForGreen = 60;
	private int waitTimeForYellow = 3;
	private int waitTimeForRed = 15;
	
	public abstract void change(TrafficLight light);
	
	public int getGreen() {
		return waitTimeForGreen;
	}

	public int getYellow() {
		return waitTimeForYellow;
	}

	public int getRed() {
		return waitTimeForRed;
	}
 
	  
	
}
