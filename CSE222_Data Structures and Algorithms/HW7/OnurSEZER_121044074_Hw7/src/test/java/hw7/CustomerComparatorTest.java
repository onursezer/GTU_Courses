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
public class CustomerComparatorTest {
    
    public CustomerComparatorTest() {
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
     * Test of compare method, of class CustomerComparator.
     */
    @Test
    public void testCompare() {
        System.out.println("compare");
        Customer o1 = new Customer(3,23,5,1);
        Customer o2 = new Customer(12,1,4,2);
        CustomerComparator instance = new CustomerComparator();
        int expResult = 1;
        int result = instance.compare(o1, o2);
        assertEquals(expResult, result);
    }
    /**
     * Test of compare method, of class CustomerComparator.
     */
    @Test
    public void testCompare2() {
        System.out.println("compare");
        Customer o1 = new Customer(3,23,5,2);
        Customer o2 = new Customer(3,23,4,2);
        CustomerComparator instance = new CustomerComparator();
        int expResult = 0;
        int result = instance.compare(o1, o2);
        assertEquals(expResult, result);
    }
    /**
     * Test of compare method, of class CustomerComparator.
     */
    @Test
    public void testCompare3() {
        System.out.println("compare");
        Customer o1 = new Customer(3,23,5,3);
        Customer o2 = new Customer(12,1,4,1);
        CustomerComparator instance = new CustomerComparator();
        int expResult = -1;
        int result = instance.compare(o1, o2);
        assertEquals(expResult, result);
    }
    
}
