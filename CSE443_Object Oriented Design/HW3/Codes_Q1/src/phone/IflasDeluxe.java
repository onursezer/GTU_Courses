package phone;

import component.*;
import market.PhoneComponentFactory;

public class IflasDeluxe extends SmartPhone{

	private IflasDeluxeCpuRam cpu = new IflasDeluxeCpuRam();
	private IflasDeluxeDisplay display = new IflasDeluxeDisplay();
	private IflasDeluxeBattery battery = new IflasDeluxeBattery();
	private IflasDeluxeStorage storage = new IflasDeluxeStorage();
	private IflasDeluxeCamera camera = new IflasDeluxeCamera();
	private IflasDeluxeCase mcase = new IflasDeluxeCase(); 
	
	public IflasDeluxe(PhoneComponentFactory factory) {
		super(factory);
		setName("IflasDeluxe");
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
