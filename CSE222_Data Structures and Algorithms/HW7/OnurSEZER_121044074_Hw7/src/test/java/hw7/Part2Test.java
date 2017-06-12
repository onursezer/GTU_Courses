/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw7;

import java.io.IOException;
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
public class Part2Test {
    
    public Part2Test() {
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
     * Test of equal method, of class Part2.
     */
    @Test
    public void testEqual() throws IOException {
        System.out.println("equal");
        
        int stuCard = 1028;
        int acaCard = 5019;
        Part2 instance = new Part2();
        instance.readFile();
        boolean expResult = true;
        boolean result = instance.equal(stuCard, acaCard);
        assertEquals(expResult, result);
    }
    /**
     * Test of equal method, of class Part2.
     */
    @Test
    public void testEqual2() throws IOException 
    {
        System.out.println("equal");
        
        int stuCard = 1099;   
        int acaCard = 5022;
        Part2 instance = new Part2();
        instance.readFile();
        boolean expResult = false;
        boolean result = instance.equal(stuCard, acaCard);
        assertEquals(expResult, result);
    }

    /**
     * Test of cont method, of class Part2.
     */
    @Test
    public void testCont() {
        System.out.println("cont");
        Part2 instance = new Part2();
        instance.cont();
    }
    
}
