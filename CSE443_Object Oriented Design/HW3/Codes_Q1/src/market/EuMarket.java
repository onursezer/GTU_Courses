package market;

public class EuMarket implements PhoneComponentFactory {

	private String marketName = "EU";

	@Override
	public String createCpuRam() {
		return "4 cores ";
	}

	@Override
	public String createDisplay() {
		return "24 bit ";
	}

	@Override
	public String createBattery() {
		return "Lithium-Ion ";
	}

	@Override
	public String createStorage() {
		return "Max 64 GB ";
	}

	@Override
	public String createCamera() {
		return "Opt. zoom x3 ";
	}

	@Override
	public String createCase() {
		return "Waterproof up to 1m ";
	}
	@Override
	public String getMarketName() {
		return marketName;
	}
	
}
