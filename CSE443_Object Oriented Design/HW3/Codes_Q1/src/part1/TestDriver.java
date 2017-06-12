package part1;

import market.EuMarket;
import market.GlobalMarket;
import market.PhoneComponentFactory;
import market.TurkeyMarket;
import phone.IIAmanIflas;
import phone.MaximumEffort;
import phone.SmartPhone;

public class TestDriver {

	public static void main(String[] args) {
		
		PhoneComponentFactory factory = new TurkeyMarket();
		SmartPhone phone = new MaximumEffort(factory);
		phone.buildPhone();
		
		System.out.println("");
		factory = new EuMarket();
		phone = new MaximumEffort(factory);
		phone.buildPhone();
		
		System.out.println("");
		factory = new GlobalMarket();
		phone = new MaximumEffort(factory);
		phone.buildPhone();
		
		System.out.println("");
		factory = new GlobalMarket();
		phone = new IIAmanIflas(factory);
		phone.buildPhone();
		
		
	}

}
