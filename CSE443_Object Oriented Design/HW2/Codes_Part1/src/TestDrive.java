package src;


public class TestDrive {

	public static void main(String[] args) {


		PersonalAddress p1 = new PersonalAddress("Onur", "Sezer", "onursezer@gmail.com");
		PersonalAddress p2 = new PersonalAddress("Recep", "Sivri", "recepsivri@out.com");
		PersonalAddress p3 = new PersonalAddress("Hasan", "Bilgin", "hasanbilgin@gmail.com");
		PersonalAddress p4 = new PersonalAddress("Veysel", "Sezer", "veyselsezer@gmail.com");
		PersonalAddress p5 = new PersonalAddress("Semih", "Kaya", "semihkaya@gmail.com");
		PersonalAddress p6 = new PersonalAddress("Emre", "Dulundu", "emredulundu@klm.com");
		PersonalAddress p7 = new PersonalAddress("Ercan", "Ulusoy", "ercanulusoy@abc.com");
		PersonalAddress p8 = new PersonalAddress("Abdil", "Sezer", "abdilsezer@abc.com");
		PersonalAddress p9 = new PersonalAddress("Zeynep", "Narmanli", "zeynepnarmanli@abc.com");

		GroupAddress g1 = new GroupAddress("galatasaylilar", "goups@galatasaray.com");
		g1.add(p1);
		g1.add(p4);
		g1.add(p5);
		
		GroupAddress g2 = new GroupAddress("fenerbahceliler", "goups@fenerbahce.com");
		g2.add(p2);
		g2.add(p3);
		g2.add(p4);
		g2.add(p6);
		g2.add(p7);
		
		GroupAddress g3 = new GroupAddress("istanbullular", "goups@istanbul.com");
		g3.add(g1);
		g3.add(g2);
		g3.add(p8);
		g3.add(p9);
		
		Client client = new Client(g3);
		client.printAdress();
		
	}

}
