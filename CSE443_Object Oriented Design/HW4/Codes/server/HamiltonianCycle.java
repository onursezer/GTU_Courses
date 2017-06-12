package server;
import java.util.ArrayList;
import java.util.List;

import client.Graph;
import client.Vertex;

/**
 * Created by Onur on 30.12.2016.
 */
public class HamiltonianCycle<T> {
	
	private int vertexNum = 0;
	private int[][] graphMatrix;
	private int path[];
	private ArrayList<Vertex<T>> nodes;


	private void set(Graph g)
	{
		nodes = g.getVertices();

		vertexNum = nodes.size();
		graphMatrix = new int[nodes.size()][nodes.size()];

		for (int i = 0; i < graphMatrix.length; i++) { // matrix graph arrayi icin ilk basta tum elemanlar -1
													   // ile initialize edilir
			
			for (int j = 0; j < graphMatrix.length; j++) {
				graphMatrix[i][j] = -1;
			}
		}

		
		for (int i = 0; i < nodes.size(); i++) { // vertex ler cekilir

			for (int j = 0; j < nodes.get(i).neighbours.size(); j++) {// vertex in komsulari alinir

				for (int n = 0; n < nodes.size(); ++n) { // vertex in komsulari 1 ile tutulur
					if (nodes.get(n).getValue().equals(nodes.get(i).neighbours.get(j).getValue())) {
						graphMatrix[i][n] = 1;
						graphMatrix[n][i] = 1;
						break;
					}
				}
			}
			for (int m = 0; m < graphMatrix.length; m++) { // vertex in komsusu olmayanlar 0 ile tutulur
				if (graphMatrix[i][m] == -1)
					graphMatrix[i][m] = 0;
			}	
		}
		
	}
		
	public String hamCycle(Graph g) {
		set(g);
		path = new int[vertexNum];
		
		for (int i = 0; i < vertexNum; i++)
			path[i] = -1;

		path[0] = 0;
		if (hamCycleUtil(path, 1) == false) {
			return null;
		}

		List<Vertex<T>> list = listSolution();
		StringBuilder build = null;
		List<String> list2 = new ArrayList<>();
		for(Vertex<T> t : list)	
			list2.add((String) t.getValue());
		return list2.toString();
	}
	private boolean isSafe(int v, int path[], int pos) {
		if (graphMatrix[path[pos - 1]][v] == 0)
			return false;

		for (int i = 0; i < pos; i++)
			if (path[i] == v)
				return false;

		return true;
	}

	private boolean hamCycleUtil(int path[], int pos) {
		if (pos == vertexNum) {
			if (graphMatrix[path[pos - 1]][path[0]] == 1)
				return true;
			else
				return false;
		}
		for (int v = 1; v < vertexNum; v++) {
			if (isSafe(v, path, pos)) {
				path[pos] = v;

				if (hamCycleUtil(path, pos + 1) == true)
					return true;
				path[pos] = -1;
			}
		}
		return false;
	}

	private List<Vertex<T>> listSolution() {
		List<Vertex<T>> list = new ArrayList<>();
		for (int i = 0; i < vertexNum; i++)
			list.add(nodes.get(path[i]));
		
		list.add(nodes.get(path[0]));
		return list;
	}
}