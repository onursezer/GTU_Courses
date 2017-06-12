package trafficLight;

public class TrafficLight {

	private AbstTrafficLight state;
	private int timeout = 60;
	
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
		state.setGreen(timeout);
	}
	public void update(boolean change)
	{
		if(change == false)
			timeout_X(60);
		else
			timeout_X(90);
	}
	private void timeout_X(int min)
	{
		timeout = min;
	}
}

