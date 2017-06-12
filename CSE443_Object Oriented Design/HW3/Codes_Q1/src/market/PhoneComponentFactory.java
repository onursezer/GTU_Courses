package market;


public interface PhoneComponentFactory {
	
	public String createCpuRam();
	public String createDisplay();
	public String createBattery();
	public String createStorage();
	public String createCamera();
	public String  createCase();
	public String getMarketName();
	
}
