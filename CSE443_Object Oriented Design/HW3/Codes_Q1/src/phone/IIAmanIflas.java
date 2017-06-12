package phone;

import component.*;
import market.PhoneComponentFactory;

public class IIAmanIflas extends SmartPhone{

	private IIAmanIflasCpuRam cpu = new IIAmanIflasCpuRam();
	private IIAmanIflasDisplay display = new IIAmanIflasDisplay();
	private IIAmanIflasBattery battery = new IIAmanIflasBattery();
	private IIAmanIflasStorage storage = new IIAmanIflasStorage();
	private IIAmanIflasCamera camera = new IIAmanIflasCamera();
	private IIAmanIflasCase mcase = new IIAmanIflasCase(); 
	
	public IIAmanIflas(PhoneComponentFactory factory) {
		super(factory);
		setName("IIAmanIflas");
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
