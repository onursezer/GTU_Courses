package server;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.ArrayList;

import client.Edge;
import client.Graph;
import client.Vertex;

/**
 * Created by Onur on 30.12.2016.
 */
public interface IRmiServer extends Remote {

    public String hamiltonianCycle(Graph g, String id) throws RemoteException;
    public <T> String dijkstra(ArrayList<Vertex<T>> v, ArrayList<Edge<T>> e, String start, String end, String id) throws RemoteException;
    public boolean register(String id, int credit) throws RemoteException;
    public boolean loadCredit(String id, int credit) throws RemoteException;
    public int getCredit(String id) throws RemoteException;
}