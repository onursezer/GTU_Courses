package market;


public class TurkeyMarket implements PhoneComponentFactory{
	
	private String marketName = "Turkey";

	@Override
	public String createCpuRam() {
		return "8 cores ";
	}

	@Override
	public String createDisplay() {
		return "32 bit ";
	}

	@Override
	public String createBattery() {
		return "Lithium-Boron ";
	}

	@Override
	public String createStorage() {
		return "Max 128 GB  ";
	}

	@Override
	public String createCamera() {
		return "Opt. zoom x4 ";
	}

	@Override
	public String createCase() {
		return "Waterp,roof up to 2m ";
	}
	@Override
	public String getMarketName() {
		return marketName;
	}

}
