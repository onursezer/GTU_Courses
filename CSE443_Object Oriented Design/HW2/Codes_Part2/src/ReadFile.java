import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class ReadFile {

	public static List<Point> readFile(String fileName)
	{
		List<Point> list = new ArrayList<Point>();
		BufferedReader br = null ;
		StringTokenizer st = null;
		try {
			br = new BufferedReader(new FileReader(fileName));
		    
			String line = br.readLine();
		    while (line != null) {
		    	
		    	st = new StringTokenizer(line, ", ");
		    	int count = 0;
		    	int x = 0, y = 0, z=0;
				while (st.hasMoreElements()) {
					if(count == 0 )	
						x = Integer.parseInt((String) st.nextElement());
					if(count == 1 )	
						y = Integer.parseInt((String) st.nextElement());
					if(count == 2 )	
						z = Integer.parseInt((String) st.nextElement());
		
					count++;
				}
		    	list.add(new Point(x, y, z));
		        line = br.readLine();
		    }
		} 
		catch(Exception e){
			e.printStackTrace();
		}finally {
		    try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		return list;
	}
}
