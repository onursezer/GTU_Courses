package trafficLight;

public class TrafficLight {

	private AbstTrafficLight state;
	
	AbstTrafficLight getState()
	{
		return state;
	}
	public void setState(AbstTrafficLight state)
	{
		this.state = state;
	}
	public TrafficLight(AbstTrafficLight state)
	{
		this.state=state;
	}
	public void changeLight()
	{
		state.change(this);
	}

}
