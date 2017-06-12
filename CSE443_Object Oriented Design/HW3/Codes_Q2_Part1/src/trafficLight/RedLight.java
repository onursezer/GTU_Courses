package trafficLight;

public class RedLight extends AbstTrafficLight{

	@Override
	public void change(TrafficLight state) {
		state.setState(new GreenLight());
		System.out.println("I am RedLight. Going to be GreenLight after " + getRed() + " seconds");
	}

}
