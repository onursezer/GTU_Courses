package server;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;

import client.Edge;
import client.Vertex;

/**
 * Created by Onur on 30.12.2016.
 */
public class Dijkstra<T> {


    private ArrayList<Vertex<T>> vertices;
    private ArrayList<Edge<T>> edges;


	public Dijkstra(ArrayList<Vertex<T>> v, ArrayList<Edge<T>> e)
    {
        vertices = new ArrayList<>();
        edges = new ArrayList<>();

        for(Vertex<T> t : v)
            vertices.add(t);

        for(Edge<T> t2 : e)
            edges.add(t2);

    }

    private boolean Dijkstra(T v1)
    {
        if (vertices.isEmpty()) return false;

        resetDistances();

        Vertex<T> source = findVertex(v1);
        if (source==null) return false;

        source.minDistance = 0;
        PriorityQueue<Vertex<T>> pq = new PriorityQueue<>();
        pq.add(source);

        while (!pq.isEmpty())
        {
            Vertex<T> u = pq.poll();

            for (Vertex<T> v : u.neighbours)
            {
                Edge<T> e = findEdge(u, v);
                if (e==null) return false;
                int totalDistance = u.minDistance + e.getCost();
                if (totalDistance < v.minDistance)
                {
                    pq.remove(v);
                    v.minDistance = totalDistance;
                    v.previous = u;
                    pq.add(v);
                }
            }
        }
        return true;
    }


    private List<String> getShortestPath(Vertex<T> target)
    {
        List<String> path = new ArrayList<String>();

        if (target.minDistance==Integer.MAX_VALUE)
        {
            path.add("No path found");
            return path;
        }

        for (Vertex<T> v = target; v !=null; v = v.previous)
        {
            path.add(v.getValue() + " : cost : " + v.minDistance);
        }

        Collections.reverse(path);
        return path;
    }

    private void resetDistances()
    {
        for (Vertex<T> each : vertices)
        {
            each.minDistance = Integer.MAX_VALUE;
            each.previous = null;
        }
    }

    public List<String> getPath(T from, T to)
    {
        boolean test = Dijkstra(from);
        if (test==false) return null;
        List<String> path = getShortestPath(findVertex(to));
        return path;
    }
    
    private Vertex<T> findVertex(T v)
    {
        for (Vertex<T> each : vertices)
        {
            if (((Comparable<T>) each.getValue()).compareTo(v)==0)
                return each;
        }
        return null;
    }

    private Edge<T> findEdge(Vertex<T> v1, Vertex<T> v2)
    {
        for (Edge<T> each : edges)
        {
            if (each.getFrom().equals(v1) && each.getTo().equals(v2))
            {
                return each;
            }
        }
        return null;
    }
}
