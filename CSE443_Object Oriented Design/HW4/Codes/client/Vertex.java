package client;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Onur on 30.12.2016.
 */
public class Vertex<T> implements Comparable<Vertex>, java.io.Serializable
{
    private T value;
    public Vertex<T> previous = null;
    public int minDistance = Integer.MAX_VALUE;
    public List<Vertex<T>> neighbours;


    public Vertex(T value)
    {
        this.value = value;
        neighbours = new ArrayList<>();
    }

    public T getValue() {
		return value;
	}

	public void setValue(T value) {
		this.value = value;
	}

    @Override
    public int compareTo(Vertex other)
    {
        return Integer.compare(minDistance, other.minDistance);
    }

    public void addNeighbours(Vertex vert)
    {
    	neighbours.add(vert);
    }

    @Override
    public String toString()
    {
        String retval = "";
        retval += "Vertex: " + value + " : ";
        retval += " Ne: ";
        for (Vertex each : neighbours) retval+= each.value + " ";
        return retval;
    }
}