/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw5;

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
public class LinkedListRecTest {
    
    public LinkedListRecTest() {
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
     * Test of remove method, of class LinkedListRec.
     */
    @Test
    public void testRemoveInt() {
        System.out.println("remove");
        LinkedListRec instance = new LinkedListRec();
        instance.add(1);
        instance.add(2);
        instance.add(3);
        instance.add(3);
        boolean expResult = true;
        boolean result = instance.remove(3); // remove 3
        assertEquals(expResult, result);
    }
    /**
     * Test of remove method, of class LinkedListRec.
     */
    @Test
    public void testNoRemoveInt() {
        System.out.println("remove");
        LinkedListRec instance = new LinkedListRec();
        instance.add(1);
        instance.add(2);
        instance.add(3);
        instance.add(3);
        boolean expResult = false;
        boolean result = instance.remove(4); // no remove
        assertEquals(expResult, result);
    }
    /**
     * Test of remove method, of class LinkedListRec.
     */
    @Test
    public void testRemoveChar() {
        System.out.println("remove");
        LinkedListRec instance = new LinkedListRec();
        instance.add('a');
        instance.add('b');
        instance.add('c');
        instance.add('c');
        boolean expResult = true;
        boolean result = instance.remove('c'); // no remove
        assertEquals(expResult, result);
    }
    /**
     * Test of remove method, of class LinkedListRec.
     */
    @Test
    public void testNoRemoveChar() {
        System.out.println("remove");
        LinkedListRec instance = new LinkedListRec();
        instance.add('a');
        instance.add('b');
        instance.add('c');
        instance.add('c');
        boolean expResult = false;
        boolean result = instance.remove('d'); // no remove
        assertEquals(expResult, result);
    }
    
}
