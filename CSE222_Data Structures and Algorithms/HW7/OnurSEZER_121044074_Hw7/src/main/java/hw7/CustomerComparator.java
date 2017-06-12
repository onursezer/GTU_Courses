package hw7;

import java.util.Comparator;

/**
 *
 * @author Onur Sezer
 */
public class CustomerComparator implements Comparator{

    /**
     * Customer objelerini karsilastirir
     * @param o1 : karsilastirilacak obje
     * @param o2 : karsilastirilacak obje
     * @return : int
     */
    @Override
    public int compare(Object o1, Object o2) 
    {
        Customer c1 = (Customer) o1;
        Customer c2 = (Customer) o2;

        if(c1.getCustometType() < c2.getCustometType())
            return 1;
        else if(c1.getCustometType() == c2.getCustometType())
        {
            if(c1.getTotalMin() < c2.getTotalMin())
                return 1;
            else if(c1.getTotalMin() > c2.getTotalMin())
                return -1;
            else
                return 0;
        }
        else
            return -1;
    }
    
}
