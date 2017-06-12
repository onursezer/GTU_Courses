package observerPattern;

import trafficLight.TrafficLight;

public interface ISubject
{
	void register(TrafficLight o);
	void unregister( TrafficLight o);
	void notifyObservers();
}