package hw1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import vpt.Image;

public class MorphoExtFiter implements AlgorithmFilter{
	private Image clone = null;

	@Override
	public Image doFilter(Image img) {
					
        List<Integer> pixel = null;
        clone = img;
        for(int i=0;i<clone.getXDim();i++)
            for(int j=0;j<clone.getYDim();j++)
            {
            	pixel = new ArrayList<Integer>();
            	pixel.add(getByte(i-2, j-2) );
				pixel.add(getByte(i-1, j-2));
				pixel.add( getByte(i, j-2));
				pixel.add( getByte(i+1, j-2));
				pixel.add( getByte(i+2, j-2));
				pixel.add( getByte(i-2,j-1));
				pixel.add( getByte(i-1,j-1));
				pixel.add( getByte(i,j-1)) ;
				pixel.add( getByte(i+1,j-1));
				pixel.add( getByte(i+2,j-1));
				pixel.add( getByte(i-2,j));
				pixel.add( getByte(i-1,j));
				pixel.add( getByte(i,j) );
				pixel.add( getByte(i+1,j));
				pixel.add( getByte(i+2,j));
				pixel.add( getByte(i-2,j+1));
				pixel.add( getByte(i-1,j+1));
				pixel.add( getByte(i,j+1));
				pixel.add( getByte(i+1,j+1));
				pixel.add( getByte(i+2,j+1));
				pixel.add( getByte(i-2,j+2));
				pixel.add( getByte(i-1,j+2));
				pixel.add( getByte(i,j+2));
				pixel.add( getByte(i+1,j+2));
				pixel.add( getByte(i+2,j+2));

				Collections.sort(pixel);
				int diff = Math.abs(clone.getXYByte(i,j) - pixel.get(24));
            	img.setXYByte(i, j, diff); // degistir
            }
        return img;
	}
	private int getByte(int x, int y)
	{
		if(isInImage(x, y))
			return clone.getXYByte(x,y);
		else
			return 0;
	}
	private boolean isInImage(int i, int j)
	{
		if(i < 0 || i >= clone.getXDim())
			return false;
		if(j < 0 || j >= clone.getYDim())
			return false;
		return true;
	}

}
