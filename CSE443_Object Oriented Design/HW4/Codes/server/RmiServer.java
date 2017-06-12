package server;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.List;

import client.Edge;
import client.Graph;
import client.Vertex; 


/**
 * Created by Onur on 30.12.2016.
 */
public class RmiServer extends UnicastRemoteObject implements IRmiServer {
    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;


	private HashMap<String, Integer> myMap = new HashMap<String, Integer>();

	public RmiServer() throws RemoteException {
		super(0);    
	}


	@Override
	public String hamiltonianCycle(Graph g, String id) throws RemoteException {

		System.out.println("\n********************************");
    	// 2 kredi azalir
    	if(myMap.get(id) >= 2) {
			System.out.println(id + " hesabından 2 kredi azaldi");
			myMap.replace(id, myMap.get(id), myMap.get(id) - 2);
		}
    	else
    		return "Kredi yetmiyor !! ";

		long startTime = System.currentTimeMillis();

		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();
		System.out.print(dateFormat.format(cal.getTime()));

		long endTime = System.currentTimeMillis();

		System.out.print(" zamaninda hamiltonianCycle methodu cagrildi. ");
		System.out.println( (endTime - startTime) + " millisaniye surdu." );
		HamiltonianCycle ham = new HamiltonianCycle();
		return  ham.hamCycle(g);
	}

	@Override
	public <T> String dijkstra(ArrayList<Vertex<T>> v, ArrayList<Edge<T>> e, String start, String end, String id) throws RemoteException {

		System.out.println("\n********************************");
		// 3 kredi azalir
		if(myMap.get(id) >= 3) {
			System.out.println(id + " hesabından 3 kredi azaldi");
			myMap.replace(id, myMap.get(id), myMap.get(id) - 3);
		}
		else
			return "Kredi yetmiyor !! ";

		List<String> path = null;
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();

		try{
			long startTime = System.currentTimeMillis();

			System.out.print(dateFormat.format(cal.getTime()));
			System.out.print(" zamaninda dijkstra methodu cagrildi. ");
			Dijkstra dij = new Dijkstra(v,e);
			path = dij.getPath(start, end);

			long endTime = System.currentTimeMillis();

			System.out.println( (endTime - startTime) + " millisaniye surdu." );
		}catch (Exception ex)
		{
			ex.printStackTrace();
		}

		StringBuilder build = new StringBuilder();
		for (String each : path)
			build.append(each + "\n");
		return build.toString();


	}

	@Override
	public boolean register(String id, int credit) {

		System.out.println("\n********************************");
		if(myMap.containsKey(id))
		{
			return  false;
		}
		DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
		Calendar cal = Calendar.getInstance();

		myMap.put(id,credit);
		System.out.println(id + " isimli account olusturuldu.\n" + credit + " kredi hesaba yuklendi.");
		System.out.print(dateFormat.format(cal.getTime()));
		return true;
	}

	@Override
	public boolean loadCredit(String id, int credit) {
		System.out.println("\n********************************");
		if(myMap.containsKey(id))
		{
			System.out.println("gelen kredi : " + credit);
			System.out.println("sistemdeki : "  + myMap.get(id));
			myMap.replace(id,myMap.get(id), (myMap.get(id) + credit));
			System.out.println(id + " hesabına " + credit + " kredi yuklendi.");
			DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
			Calendar cal = Calendar.getInstance();
			System.out.print(dateFormat.format(cal.getTime()));
			return  true;
		}
		return false;
	}
	@Override
	public int getCredit(String id) {
		System.out.println("\n********************************");
		if(myMap.containsKey(id)) {
			System.out.println(id + " hesabındaki kredi miktari gonderildi.");
			DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
			Calendar cal = Calendar.getInstance();
			System.out.print(dateFormat.format(cal.getTime()));
			return myMap.get(id);
		}
		return 0;
	}

}