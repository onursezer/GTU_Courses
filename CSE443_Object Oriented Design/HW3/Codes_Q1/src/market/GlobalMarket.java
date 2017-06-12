package market;

public class GlobalMarket implements PhoneComponentFactory {

	private String marketName = "Global";

	@Override
	public String createCpuRam() {
		return "2 cores ";
	}

	@Override
	public String createDisplay() {
		return "24 bit  ";
	}

	@Override
	public String createBattery() {
		return "Lithium-Cobalt ";
	}

	@Override
	public String createStorage() {
		return "Max 32 GB ";
	}

	@Override
	public String createCamera() {
		return "Opt. zoom x2 ";
	}

	@Override
	public String createCase() {
		return "Waterproof up to 50cm ";
	}
	@Override
	public String getMarketName() {
		return marketName;
	}

}
