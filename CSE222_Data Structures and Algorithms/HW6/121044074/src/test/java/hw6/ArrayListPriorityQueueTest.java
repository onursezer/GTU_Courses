/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw6;

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
public class ArrayListPriorityQueueTest {
    
    public ArrayListPriorityQueueTest() {
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
     * Test of enqueue method, of class ArrayListPriorityQueue.
     */
   @Test
    public void testEnqueue() {
        System.out.println("enqueue");
        Integer item = 1;
        ArrayListPriorityQueue instance = new ArrayListPriorityQueue();
        boolean expResult = true;
        boolean result;
        result = instance.enqueue(item);
        
        assertEquals(expResult, result);
    }

    /**
     * Test of dequeue method, of class ArrayListPriorityQueue.
     */
   @Test
    public void testDequeue() {
        System.out.println("dequeue");
        ArrayListPriorityQueue instance = new ArrayListPriorityQueue();
        Integer item = 1;
        instance.enqueue(item);

        boolean expResult = true;

        boolean result = instance.dequeue();
       
        assertEquals(expResult, result);
    }

    /**
     * Test of isEmpty method, of class ArrayListPriorityQueue.
     */
    @Test
    public void testIsEmpty() {
        System.out.println("isEmpty");
        ArrayListPriorityQueue instance = new ArrayListPriorityQueue();
        boolean expResult = true;
        boolean result = instance.isEmpty();
        assertEquals(expResult, result);
    }

    /**
     * Test of size method, of class ArrayListPriorityQueue.
     */
   @Test
    public void testSize() {
        System.out.println("size");
        ArrayListPriorityQueue instance = new ArrayListPriorityQueue();
        int expResult = 0;
        int result = instance.size();
        assertEquals(expResult, result);
    }
    
}
