package trafficLight;



public class YellowLight extends AbstTrafficLight{

	@Override
	public void change(TrafficLight state) {
		state.setState(new RedLight());
		System.out.println("I am YellowLight. Going to be RedLight after " + getYellow() + " seconds");
	}


}
