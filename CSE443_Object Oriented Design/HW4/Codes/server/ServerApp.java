package server;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

/**
 * Created by Onur on 30.12.2016.
 */
public class ServerApp{
	 public static void main(String args[]) throws Exception {
	        System.out.println("RMI server started");

	        try { 
	            LocateRegistry.createRegistry(1099); 
	            System.out.println("java RMI registry created.");
	        } catch (RemoteException e) {
	            System.out.println("java RMI registry already exists.");
	        }
	           
	        IRmiServer obj = new RmiServer();
	        Naming.rebind("//localhost/RmiServer", obj);
	    }
}