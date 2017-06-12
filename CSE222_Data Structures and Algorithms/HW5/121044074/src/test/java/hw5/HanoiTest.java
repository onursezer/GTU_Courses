/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw5;

import java.util.ArrayList;
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
public class HanoiTest {
    
    public HanoiTest() {
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
     * While disksize is odd 
     * Test of TowerOfHanoi method, of class Hanoi.
     */
    @Test
    public void testTowerOfHanoi1() {
        System.out.println("TowerOfHanoi");
        int disksize = 3;
        ArrayList<Integer> src = new ArrayList<Integer>();
        ArrayList<Integer> dst = new ArrayList<Integer>();
        ArrayList<Integer> aux = new ArrayList<Integer>();
        
        
        src.add(1);
        src.add(2);
        src.add(3);
        Hanoi instance = new Hanoi();
        instance.TowerOfHanoi(disksize, src, dst, aux);
        
        boolean expResult = true;
        boolean result;
        
        if(dst.get(0).equals(3) && dst.get(1).equals(2) && dst.get(2).equals(1))
            result = true;
        else
            result = false;
            
        assertEquals(expResult, result);
    }
    
    
    /**
     * While disksize is double 
     * Test of TowerOfHanoi method, of class Hanoi.
     */
    @Test
    public void testTowerOfHanoi2() {
        System.out.println("TowerOfHanoi");
        int disksize = 4;
        ArrayList<Integer> src = new ArrayList<Integer>();
        ArrayList<Integer> dst = new ArrayList<Integer>();
        ArrayList<Integer> aux = new ArrayList<Integer>();
        
        src.add(1);
        src.add(2);
        src.add(3);
        src.add(4);
        Hanoi instance = new Hanoi();
        instance.TowerOfHanoi(disksize, src, dst, aux);
        
        boolean expResult = true;
        boolean result;
        
        if(dst.get(0).equals(4) && dst.get(1).equals(3) && dst.get(2).equals(2) && dst.get(3).equals(1))
            result = true;
        else
            result = false;
            
        assertEquals(expResult, result);
    }
    
    /**
     * When catch Exception
     * Test of TowerOfHanoi method, of class Hanoi.
     */
    @Test
    public void testTowerOfHanoi3() {
        System.out.println("TowerOfHanoi");
        int disksize = 2;
        ArrayList<Integer> src = new ArrayList<Integer>();
        ArrayList<Integer> dst = new ArrayList<Integer>();
        ArrayList<Integer> aux = new ArrayList<Integer>();
        
        src.add(1);
        src.add(2);

        Hanoi instance = new Hanoi();
        
        boolean expResult = true;
        boolean result = false;
        try
        {
            instance.TowerOfHanoi(disksize, src, dst, aux);
        }
        catch(IllegalArgumentException e)
        {
            result = true;
        }
        
        assertEquals(expResult, result);
    }
}
