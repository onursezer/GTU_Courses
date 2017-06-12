package hw1;

import vpt.Image;

public interface IFilter {
	 public void setChoice(AlgorithmFilter filter);
	 public Image doFilter(Image img);
}
