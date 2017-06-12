package client;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.rmi.Naming;
import server.IRmiServer;

/**
 * Created by Onur on 30.12.2016.
 */
public class Client {

	public static void main(String[] args)  {

		BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
		String id = null;

        Graph graph2 = new Graph<>();
		Graph graph = new Graph<>();

        graph2.add("SAMSUN", "KONYA", 7);
        graph2.add("SAMSUN", "RIZE", 12);
        graph2.add("KONYA", "ANTALYA", 9);
        graph2.add("KONYA", "RIZE", 2);
        graph2.add("KONYA", "SIVAS", 7);
        graph2.add("ANTALYA", "SIVAS", 6);
        graph2.add("RIZE", "SIVAS", 15);
		System.out.println("Default Graph olusturuldu.");

		try {
			String start = null;
			String end = null;
			IRmiServer m = (IRmiServer) Naming.lookup("//localhost/RmiServer");
			System.out.println("\nSERVER'a BAGLANDI...\n");

			boolean statuas = false;
			do {
				System.out.println("Kullanici ismi girin...");
				id = bufferRead.readLine();
				System.out.println("Hesabiniza yuklenecek kredi tutarini girin...");
				int credit = Integer.parseInt(bufferRead.readLine());
				statuas =  m.register(id, credit);
				if(statuas == false)
					System.out.println("Kullanici ismi daha once olusturulmus!! Tekrar girin!!");
			}while(!statuas);
			String choice;
			do {
				System.out.println("\n1- Default Graph'i kullan.");
				System.out.println("2- Kendi Graph'ini olustur.\n");

				System.out.println("Secimini yap! (1 - 2)");
				String s = bufferRead.readLine();

				if(s.equals("1")) {
					graph = graph2;
					for (int i = 0; i < graph.getEdges().size(); i++) {
						System.out.println(graph.getEdges().get(i));
					}
				}
				else if(s.equals("2")) {
					graph = new Graph<>();
					/*
					("a", "b", 7),
					("a", "d", 12),
					("b", "c", 9),
					("b", "d", 2),
					("b", "e", 7),
					("c", "e", 6),
					("d", "e", 15),
					*/
					String node1 = null, node2 = null, st = null;
					int cost = 0;
					System.out.println("Edge girin...(EX -> \"a b 12\")");
					int ct = 0;
					do {
						if (ct != 0)
							System.out.println("Edge girin...");
						ct++;
						node1 = bufferRead.readLine();
						node2 = bufferRead.readLine();
						cost = Integer.parseInt(bufferRead.readLine());
						System.out.println(node1 + " " + node2 + " " + cost);
						graph.add(node1, node2, cost);
						System.out.println("Cikmak icin 'q' ya, Devam etmek icin 'c' ye basin...");
						st = bufferRead.readLine();
					} while (!st.equals("q"));

					System.out.println("Graph olusturuldu.");

					System.out.println(graph.getVertices());
				}


				System.out.println("\na- Dijkstra (Shortest Path)");
				System.out.println("b- TSP (Hamiltonian Cycle)");
				System.out.println("c- Hesabina kredi yukle");
				System.out.println("d- Hesabindaki krediyi ogren");
				System.out.println("q- Cikis \n");

				System.out.println("Secimini yap! (a - b - c -d - q)");
				choice = bufferRead.readLine();
				if (choice.equals("a")) {
					System.out.println("\nStart ve End Node' lari gir!");
					start = bufferRead.readLine();
					end = bufferRead.readLine();

					System.out.println(start.toUpperCase() + " to " + end.toUpperCase());
					String path = m.dijkstra(graph.getVertices(), graph.getEdges(), start.toUpperCase(), end.toUpperCase(), id);
					System.out.println(path);
				} else if (choice.equals("b")) {
					System.out.println("\nTSP : ");
					System.out.println(m.hamiltonianCycle(graph, id));
				}
				else if (choice.equals("c")) {
					System.out.println("Yuklenicek miktar girin...");
					int value = Integer.parseInt(bufferRead.readLine());
					m.loadCredit(id,value);
				}
				else if(choice.equals("d"))
				{
					System.out.println("Hesabınızdaki kredi : " + m.getCredit(id));
				}

			}while (!choice.equals("q"));
			
		} catch (Exception e) {
			System.out.println();
			System.out.println("Exception: " + e.toString());
		}
	}

}