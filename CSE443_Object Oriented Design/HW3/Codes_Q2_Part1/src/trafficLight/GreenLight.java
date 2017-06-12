package trafficLight;

public class GreenLight extends AbstTrafficLight{

	@Override
	public void change(TrafficLight state) {
		state.setState(new YellowLight());
		System.out.println("I am GreenLight. Going to be YellowLight after " + getGreen() + " seconds");
	}

}
