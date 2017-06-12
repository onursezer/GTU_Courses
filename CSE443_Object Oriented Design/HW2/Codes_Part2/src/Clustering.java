import java.util.*;

public abstract class Clustering {

	protected List<Point> points = new ArrayList<Point>();
	protected List<Point> centers = new ArrayList<Point>();
	
	protected abstract void initialize(int num);
	protected abstract void show();
	protected abstract void performClustering();

	protected void loadFromFile()
	{
		points = ReadFile.readFile("data");
	}
	public final void clustering(int num)
	{
		loadFromFile();
		initialize(num);
		performClustering();
		show();
	}
}
