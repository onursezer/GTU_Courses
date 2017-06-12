package hw1;

import vpt.Image;
import vpt.algorithms.display.Display2D;
import vpt.algorithms.io.Load;
import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		IFilter filter = null;
		for(;;)
		{
			try{
				System.out.println("Enter a Filter Type(1 or 2)");
				System.out.println("1 -> Smoothing, 2 -> EdgeDetection");
				
				String c = in.nextLine();
				
				if(c.equals("1"))
				{
					Image img = Load.invoke("lennaGray.png");
					
					System.out.println("Enter a  SmoothingFilter Type(1 or 2)");
					System.out.println("1 -> AverageFilter, 2 -> MedianFilter");
					
					String s = in.nextLine(); 
					if(s.equals("1"))
					{
						filter = new SmoothingFilter(new AverageFilter());
						Display2D.invoke(filter.doFilter(img));
					}
					else if(s.equals("2"))
					{
						filter = new SmoothingFilter(new MedianFilter());
						Display2D.invoke(filter.doFilter(img));
					}
					else
						break;
				}
				else if(c.equals("2"))
				{
					Image img = Load.invoke("lennaGray.png");
					System.out.println("Enter a  EdgeDetection Type(1 or 2)");
					System.out.println("1 -> MorpholntFilter, 2 -> MorphoExtFiter");
					
					String s = in.nextLine(); 
					if(s.equals("1"))
					{
						filter = new EdgeDetection(new MorpholntFilter());
						Display2D.invoke(filter.doFilter(img));
					}
					else if(s.equals("2"))
					{
						filter = new EdgeDetection(new MorphoExtFiter());
						Display2D.invoke(filter.doFilter(img));
					}
					else
						break;
				}
				else
					break;
				
			}
			catch(Exception e)
			{
				e.printStackTrace();
			}
		}
	}
}
