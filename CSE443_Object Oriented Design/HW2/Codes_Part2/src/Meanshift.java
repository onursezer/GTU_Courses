import java.util.LinkedList;
import java.util.List;

public class Meanshift extends Clustering{

	private int radius;
	@Override
	protected void initialize(int radius) {
		this.radius = radius;
	}

	@Override
	protected void show() {
		System.out.print("For meanshift we have found " +  centers.size() + " clusters:");
		for (int i = 0; i < centers.size(); i++) {
			if(i == centers.size() - 1)
				System.out.print(centers.get(i));
			else
				System.out.print(centers.get(i) + ", ");
		}		
		System.out.println("\n");
	}

	@Override
	protected void performClustering() {
		
		for (int i = 0; i < points.size(); ++i) {
			
		
			Point p = points.get(i);
			Point temp = points.get(i);
			do{
				p = findGroups(p);
				System.out.println(p);
				int st = 0;
				if(p.equals(temp))
				{
					for(Point c : centers)
					{
						if(p.equals(c))
							st = 1;
					}
					if(st == 0){
						centers.add(p);
					}
					break;
				}
				temp = p;
			}while(true);
		}
	}
	private Point findGroups(Point p)
	{
		List<Point> circle = new LinkedList<Point>();
		List<Point> rCircle = new LinkedList<Point>();
		int xCenter = p.getX(), yCenter = p.getY(),zCenter = p.getZ();
		int x,y,z,xSym,ySym,zSym;
		if(xCenter - radius < 0)
			x = 0;
		else
			x = xCenter - radius;
		if(yCenter - radius < 0)
			y = 0;
		else
			y = yCenter - radius;
		if(zCenter - radius < 0)
			z = 0;
		else
			z = zCenter - radius;
		for ( ; x <= xCenter; x++)
		{
		    for ( ; y <= yCenter; y++)
		    {
		    	for ( ; z <= zCenter; z++)
			    {
			        if ((x - xCenter)*(x - xCenter) + (y - yCenter)*(y - yCenter) + 
			        		(z - zCenter)*(z - zCenter) <= radius*radius*radius) 
			        {
			        	xSym = xCenter - (x - xCenter);
			            ySym = yCenter - (y - yCenter);
			            zSym = zCenter - (z - zCenter);
			            circle.add(new Point(xSym, ySym, zSym));
			        }
			    }
		    }
		}

		for(Point point : points)
			if(circle.contains(point))
				rCircle.add(point);
		
		x = 0;y=0;z=0;
		for (Point sp : rCircle) {
			x += sp.getX();
			y += sp.getY();
			z += sp.getZ();
		}
		return new Point(x/(rCircle.size()+1), y/(rCircle.size()+1), z/(rCircle.size()+1));
	}
}
