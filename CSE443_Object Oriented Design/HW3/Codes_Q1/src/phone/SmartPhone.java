package phone;


import market.PhoneComponentFactory;

public abstract class SmartPhone {
	
	PhoneComponentFactory factory = null;
	
	private String name = null;
	
	
	public abstract String attachCpuRam();
	public abstract String attachDisplay();
	public abstract String attachBattery();
	public abstract String attachStorage();
	public abstract String attachCamera();
	public abstract String attachCase();
	
	
	public SmartPhone(){}
	public SmartPhone(PhoneComponentFactory factory) {
		this.factory = factory;
	}
	
	public void buildPhone()
	{
		System.out.println("Telefon ismi : " + getName());
		System.out.println("Üretim yeri : " + factory.getMarketName());
		System.out.println(attachCpuRam() + "eklendi");
		System.out.println(attachDisplay() + "eklendi");
		System.out.println(attachBattery() + "eklendi");
		System.out.println(attachStorage() + "eklendi");
		System.out.println(attachCamera() + "eklendi");
		System.out.println(attachCase() + "oluþturuldu");
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	
}
	