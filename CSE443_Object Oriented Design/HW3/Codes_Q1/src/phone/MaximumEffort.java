package phone;

import component.MaximumEffortBattery;
import component.MaximumEffortCamera;
import component.MaximumEffortCase;
import component.MaximumEffortCpuRam;
import component.MaximumEffortDisplay;
import component.MaximumEffortStorage;
import market.PhoneComponentFactory;

public class MaximumEffort extends SmartPhone{

	private MaximumEffortCpuRam cpu = new MaximumEffortCpuRam();
	private MaximumEffortDisplay display = new MaximumEffortDisplay();
	private MaximumEffortBattery battery = new MaximumEffortBattery();
	private MaximumEffortStorage storage = new MaximumEffortStorage();
	private MaximumEffortCamera camera = new MaximumEffortCamera();
	private MaximumEffortCase mcase = new MaximumEffortCase(); 
	
	public MaximumEffort(PhoneComponentFactory factory) {
		super(factory);
		setName("MaximumEffort");
	}
	
	@Override
	public String attachCpuRam() {
		
		return cpu + factory.createCpuRam();
	}

	@Override
	public String attachDisplay() {
		
		return display + factory.createDisplay();
	}

	@Override
	public String attachBattery() {
		
		return battery + factory.createBattery();
	}

	@Override
	public String attachStorage() {
		
		return storage + factory.createStorage();
	}

	@Override
	public String attachCamera() {
		
		return camera + factory.createCamera();
	}

	@Override
	public String attachCase() {
		
		return mcase + factory.createCase();
	}

}
