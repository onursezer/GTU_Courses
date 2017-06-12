package hw7;

/**
 *
 * @author Onur Sezer
 */
public class MyPriorityQueue {
    
    // Data Fields
    private Customer[] customerList;
    private int size;
    private int index = 0;
    private CustomerComparator cmp = new CustomerComparator();
    
    /**
     * Customer arrayinin size i dolunca yeniden yer alir 
     */
    private void resize()
    {
        int oldCapacity = size;
        size = oldCapacity * 2;
        Customer[] temp = new Customer[oldCapacity];
        for (int i = 0; i < oldCapacity; i++) {
            temp[i] = customerList[i];
        }
        customerList = new Customer[size];
        for (int i = 0; i < oldCapacity; i++) {
            customerList[i] = temp[i];
        }
    }
    /**
     * Constructor,
     * size 10 ile ilklendirilir
     */
    public MyPriorityQueue() 
    {
        customerList = new Customer[10];
        size = 10;
    }
    /**
     * Arraye ekleme yapar
     * @param cus eklenecek Customer objesi
     * @return boolean
     */
    public boolean enqueue(Customer cus) 
    {        
        if(cus == null)
            throw new NullPointerException();
        if(index >= size)
            resize();
        customerList[index] = cus;  
        index++;
        return true;
    }
    /**
     * Arrayden eleman cikarir, eleman cikartirken oncelikleri dikkate alir
     * @return  Customer
     */
    public Customer deque()
    {
        if (index == 0)
            throw new NullPointerException();
        Customer result = new Customer();
        int findIndex = 0;
        result = customerList[0];
        for (int i = 0; i < index; i++) {
            for (int j = 0; j < index; j++) {
                if(!(i == j) && 1 == cmp.compare(customerList[i], customerList[j]))
                {
                    if( 1 == cmp.compare(customerList[i], result))
                    {
                        result = customerList[i];
                        findIndex = i;
                    }
                }
            }
        }
        if(findIndex == 0)
            for (int i = 1; i < index; i++) 
                customerList[i-1] = customerList[i];
        else
            for (int i = findIndex; i < index-1; i++) 
                customerList[i] = customerList[i+1];
        --index;
        return result;
    }
    public int getIndex() {
        return index;
    }   

}
