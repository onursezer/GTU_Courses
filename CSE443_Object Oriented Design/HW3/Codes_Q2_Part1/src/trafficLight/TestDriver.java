package trafficLight;

public class TestDriver {

	public static void main(String[] args) {

		System.out.println("	***State Pattern Demo***\n");

		AbstTrafficLight initialState = new RedLight();
		TrafficLight light = new TrafficLight(initialState);
		
		light.changeLight();
		light.changeLight();
		light.changeLight();
		
	}

}
