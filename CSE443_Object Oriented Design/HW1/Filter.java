package hw1;

import vpt.Image;

public abstract class Filter implements IFilter{
	 AlgorithmFilter filter;             
	 public void setChoice(AlgorithmFilter filter)       
	 {               
		 this.filter = filter;        
	 }       
	 public Image doFilter(Image img)  
	 {
	 	return filter.doFilter(img);     
	 } 
}
