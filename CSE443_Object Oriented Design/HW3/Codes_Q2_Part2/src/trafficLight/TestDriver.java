package trafficLight;

import observerPattern.HiTech;

public class TestDriver {

	public static void main(String[] args) {

		System.out.println("	***Observer & State Pattern Demo***\n");

		AbstTrafficLight initialState = new RedLight();
		
		TrafficLight light = new TrafficLight(initialState);
		TrafficLight light2 = new TrafficLight(initialState);
		TrafficLight light3 = new TrafficLight(initialState);
		
		HiTech hiTech = new HiTech();
		
		hiTech.register(light);
		hiTech.register(light2);
		hiTech.register(light3);
		System.out.println("light registered to HiTech");
		System.out.println("light2 registered to HiTech");
		System.out.println("light3 registered to HiTech");
		
		hiTech.changeDetected(true);
		System.out.println("\nTrafiðin sýkýþýk olduðu farkedildi.Yeþil ýþýklar 90 sn yapildi.");
		
		System.out.println("\n light");
		light.changeLight();
		light.changeLight();
		light.changeLight();
		
		System.out.println("\n light2");
		light2.changeLight();
		light2.changeLight();
		light2.changeLight();
		
		System.out.println("\n light3");
		light3.changeLight();
		light3.changeLight();
		light3.changeLight();
		
		
		hiTech.changeDetected(false);
		System.out.println("\nTrafiðin normal olduðu farkedildi.Yeþil ýþýk eski haline getirildi.");
		
		System.out.println("\n light");
		light.changeLight();
		light.changeLight();
		light.changeLight();
		
		System.out.println("\n light2");
		light2.changeLight();
		light2.changeLight();
		light2.changeLight();
		
		System.out.println("\n light3");
		light3.changeLight();
		light3.changeLight();
		light3.changeLight();
	}

}
