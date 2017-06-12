import java.util.*;

public class Kmeans extends Clustering{

	@Override
	protected void initialize(int numOfGroup) {
		int x=-1,y=-1,z=-1;
		Random rand = new Random();
		for (int i = 0; i < numOfGroup; i++) {
			rand = new Random();
			for (int j = 0; j < 3; j++) {
				if(j == 0)
					x = rand.nextInt(250);
				else if(j == 1)
					y = rand.nextInt(250);
				else if(j == 2)
					z = rand.nextInt(250);
			}
			centers.add(new Point(x,y,z));
		}
	}
	@Override
	protected void show() {
		System.out.println("For kmeans the clusters are : ");
		for (int i = 0; i < centers.size(); i++) {
			if(i == centers.size() - 1)
				System.out.println(centers.get(i));
			else
				System.out.println(centers.get(i) + ", ");
		}		
	}
	@Override
	protected void performClustering() {
		
		List<Point> temp = new ArrayList<Point>();
		for(Point p : centers)
			temp.add(new Point(p.getX(), p.getY(), p.getZ()));
		do{
			findGroups();
			int count = 0;
			for (int i = 0; i < centers.size(); i++) 
				if(centers.get(i).equals(temp.get(i)))
					count++;
			if(count == centers.size())
				break;
			temp.clear();	
			for(Point p : centers)
				temp.add(new Point(p.getX(), p.getY(), p.getZ()));
		}while(true);
		
	}
	private double getDistance(Point p1, Point p2) {
	    return Math.sqrt( Math.pow(p1.getX() - p2.getX(), 2) + 
	    				  Math.pow(p1.getY() - p2.getY(), 2) +
	    				  Math.pow(p1.getZ() - p2.getZ(), 2));
	}
	private void findGroups()
	{
		for (int i = 0; i < points.size(); i++) {
			double minDistance = getDistance( points.get(i), centers.get(0) );
			points.get(i).setGroup(0);
			for (int j = 1; j < centers.size(); j++) {
				double dis = getDistance( points.get(i), centers.get(j) );
				if ( dis < minDistance ) {
                         minDistance = dis;
                         points.get(i).setGroup(j);
				}
			}
		}
		for (int j = 0; j < centers.size(); j++) {
			int x = 0, y = 0, z = 0, count = 1;
			for (int i = 0; i < points.size(); i++) {
				if(points.get(i).getGroup() == j){
					x += points.get(i).getX();
					y += points.get(i).getY();
					z += points.get(i).getZ();
					count++;
				}
			}
			centers.get(j).setX(x / count);
			centers.get(j).setY(y / count);
			centers.get(j).setZ(z / count);
			count = 1;
		}	
	}

	
}
