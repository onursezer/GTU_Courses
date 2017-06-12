package client;

import java.util.*;

/**
 * Created by Onur on 30.12.2016.
 */
public class Graph<T extends Comparable<T>>  implements java.io.Serializable
{

    private static final long serialVersionUID = -910957234865388235L;
    public ArrayList<Vertex<T>> vertices;
    public ArrayList<Edge<T>> edges;

    public Graph()
    {
        vertices = new ArrayList<>();
        edges = new ArrayList<>();
    }

    public void add(T v1, T v2, int cost)
    {
        Edge<T> temp = findEdge(v1, v2);
        if (temp != null)
        {
            System.out.println("Edge " + v1 + "," + v2 + " already exists. Changing cost.");
            temp.cost = cost;
        }
        else
        {
        	
        	Vertex<T> from = findVertex(v1);
            if (from == null)
            {
                from = new Vertex<T>(v1);
                vertices.add(from);
            }
            Vertex<T> to = findVertex(v2);
            if (to == null)
            {
                to = new Vertex<T>(v2);
                vertices.add(to);
            }

            from.addNeighbours(to);
        	
            Edge<T> e = new Edge<>(from, to, cost);
            edges.add(e);
        }
    }

    public Vertex<T> findVertex(T v)
    {
        for (Vertex<T> each : vertices)
        {
            if (((Comparable<T>) each.getValue()).compareTo(v)==0)
                return each;
        }
        return null;
    }

    private Edge<T> findEdge(T from, T to)
    {
        for (Edge<T> each : edges)
        {
            if (each.from.getValue().equals(from) && each.to.getValue().equals(to))
            {
                return each;
            }
        }
        return null;
    }

    @Override
    public String toString()
    {
        String retval = "";
        for (Vertex each : vertices)
        {
            retval += each.toString() + "\n";
        }
        return retval;
    }
    public ArrayList<Vertex<T>> getVertices() {
        return vertices;
    }

    public ArrayList<Edge<T>> getEdges() {
        return edges;
    }

}