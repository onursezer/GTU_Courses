package observerPattern;

import java.util.ArrayList;
import java.util.List;

import trafficLight.TrafficLight;

public class HiTech implements ISubject
{
	List<TrafficLight> observerList = new ArrayList<TrafficLight>();
	private boolean flag = false;
	
	public boolean getFlag() {
		return flag;
	}
	public void setFlag(boolean flag) {
		this.flag = flag;
	}
	
	public void changeDetected(boolean flag){
		this.setFlag(flag);
		notifyObservers();
	}
	
	@Override
	public void register(TrafficLight o) {
		observerList.add(o);
	}
	
	@Override
	public void unregister(TrafficLight o) {
		observerList.remove(o);
	}
	
	@Override
	public void notifyObservers() {
		for(int i=0;i<observerList.size();i++)
		{
			observerList.get(i).update(getFlag());
		}
		
	}
}