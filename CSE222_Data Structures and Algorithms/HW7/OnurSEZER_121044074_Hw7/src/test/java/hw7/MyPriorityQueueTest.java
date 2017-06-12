/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Onur Sezer
 */
public class MyPriorityQueueTest {
    
    public MyPriorityQueueTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of enqueue method, of class MyPriorityQueue.
     */
    @Test
    public void testEnqueue() {
        System.out.println("enqueue");
        Customer cus = new Customer();
        MyPriorityQueue instance = new MyPriorityQueue();
        boolean expResult = true;
        boolean result = instance.enqueue(cus);
        assertEquals(expResult, result);
    }

    /**
     * Test of deque method, of class MyPriorityQueue.
     */
    @Test
    public void testDequeWithException()
    {
        System.out.println("deque");
        MyPriorityQueue instance = new MyPriorityQueue();
        boolean expResult = true, result = false;
        try{
            instance.deque();
        }catch(Exception e)
        {
            result = true;
        }
        assertEquals(expResult, result);
    }
    /**
     * Test of deque method, of class MyPriorityQueue.
     */
    @Test
    public void testDeque()
    {
        System.out.println("deque");
        MyPriorityQueue instance = new MyPriorityQueue();
        int expResult = 1, result; // customer type    

        instance.enqueue(new Customer(3, 2, 5, 1));
        instance.enqueue(new Customer(2, 2, 15, 3));

        result = instance.deque().getCustometType();

        assertEquals(expResult, result);
    }
    
}
