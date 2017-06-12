package client;

/**
 * Created by Onur on 30.12.2016.
 */
public class Edge<T> implements java.io.Serializable{
	Vertex<T> from;
	Vertex<T> to;
	int cost;

	public Vertex<T> getFrom() {
		return from;
	}

	public Vertex<T> getTo() {
		return to;
	}

	public int getCost() {
		return cost;
	}

	public void setFrom(Vertex<T> from) {
		this.from = from;
	}

	public void setTo(Vertex<T> to) {
		this.to = to;
	}

	public void setCost(int cost) {
		this.cost = cost;
	}

	public Edge(Vertex<T> v1, Vertex<T> v2, int cost) {
		this.cost = cost;
		this.from = v1;
		this.to = v2;
	}

	@Override
	public String toString() {
		return "Edge From: " + from.getValue() + " to: " + to.getValue() + " cost: " + cost;
	}
}