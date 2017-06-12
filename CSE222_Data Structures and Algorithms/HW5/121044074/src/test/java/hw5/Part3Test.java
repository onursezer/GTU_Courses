/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw5;

import java.util.List;
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
public class Part3Test {
    
    public Part3Test() {
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

    // TEST FOR INTEGER
    /**
     * Test of intersectionOfLists method, of class Part3.
     */
    @Test
    public void testIntersectionOfListsInteger() {
        System.out.println("intersectionOfLists");
        Part3 instance = new Part3();

        instance.list1.add(1);
        instance.list1.add(2);
        instance.list1.add(3);
        instance.list1.add(4);
        instance.list2.add(1);
        instance.list2.add(4);
        List list = instance.intersectionOfLists();
       
        boolean expResult = true, result = false;
        
        if(!list.isEmpty())
            if(list.get(0).equals(1) && list.get(1).equals(4))
                result = true;
        
        assertEquals(expResult, result);
    }

    /**
     * Test of unionOfLists method, of class Part3.
     */
    @Test
    public void testUnionOfListsInteger() {
        System.out.println("union");
        Part3 instance = new Part3();

        instance.list1.add(1);
        instance.list1.add(2);
        instance.list1.add(3);
        instance.list1.add(4);
        instance.list2.add(1);
        instance.list2.add(4);
        List list = instance.unionOfLists();
       
        boolean expResult = true, result = false;
        
        if(!list.isEmpty())
            if(list.get(0).equals(1) && list.get(1).equals(2) && list.get(2).equals(4) && list.get(3).equals(3))
                result = true;
        
        assertEquals(expResult, result);
    }

    /**
     * Test of isSubset method, of class Part3.
     */
    @Test
    public void testIsSubsetInteger() {
        System.out.println("isSubset");
        Part3 instance = new Part3();

        instance.list1.add(1);
        instance.list1.add(2);
        instance.list1.add(3);
        instance.list1.add(4);
        instance.list2.add(1);
        instance.list2.add(4);
        boolean result = instance.isSubset();
       
        boolean expResult = true;
        
        assertEquals(expResult, result);
    }
    
    // TEST FOR STRING
    /**
     * Test of intersectionOfLists method, of class Part3.
     */
    @Test
    public void testIntersectionOfListsString() {
        System.out.println("intersectionOfLists");
        Part3 instance = new Part3();

        instance.list1.add("ankara");
        instance.list1.add("bolu");
        instance.list1.add("diyarbakir");
        instance.list1.add("nigde");
        instance.list2.add("bolu");
        instance.list2.add("nigde");
        List list = instance.intersectionOfLists();
       
        boolean expResult = true, result = false;
        
        if(!list.isEmpty())
            if(list.get(0).equals("bolu") && list.get(1).equals("nigde"))
                result = true;
        
        assertEquals(expResult, result);
    }

    /**
     * Test of unionOfLists method, of class Part3.
     */
    @Test
    public void testUnionOfListsString() {
        System.out.println("union");
        
        Part3 instance = new Part3();

        instance.list1.add("ankara");
        instance.list1.add("bolu");
        instance.list1.add("diyarbakir");
        instance.list1.add("nigde");
        instance.list2.add("bolu");
        instance.list2.add("nigde");
        List list = instance.unionOfLists();
       
        boolean expResult = true, result = false;
       
        if(!list.isEmpty())
            if(list.get(0).equals("ankara") && list.get(1).equals("bolu") && list.get(2).equals("nigde") && list.get(3).equals("diyarbakir"))
                result = true;
        
        assertEquals(expResult, result);
    }

    /**
     * Test of isSubset method, of class Part3.
     */
    @Test
    public void testIsSubsetString() {
        System.out.println("isSubset");
        Part3 instance = new Part3();

        instance.list1.add("ankara");
        instance.list1.add("bolu");
        instance.list1.add("diyarbakir");
        instance.list1.add("nigde");
        instance.list2.add("kars");
        boolean result = instance.isSubset();
       
        boolean expResult = false;
        
        assertEquals(expResult, result);
    }
    
}
