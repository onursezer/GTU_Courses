/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw6;

import java.util.Iterator;
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
public class BinarySearchTreeTest {
    
    public BinarySearchTreeTest() {
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
     * Test of iterator method, of class BinarySearchTree.
     */
    @Test
    public void testIteratorNext() {
        System.out.println("iterator");
        
        
        BinarySearchTree<Integer> Btree = new BinarySearchTree<Integer>();
        Btree.add(2);
        Btree.add(1);
        Btree.add(12);
        Btree.add(20);
        Btree.add(11);
        
        
        Btree.inOrder();
        Iterator it = Btree.iterator();
        Integer result = (Integer) it.next();
        Integer expResult = 1;
        
     
        assertEquals(expResult, result);
    }
    /**
     * Test of iterator method, of class BinarySearchTree.
     */
    @Test
    public void testIteratorHasNext() {
        System.out.println("iterator");
        
        
        BinarySearchTree<Integer> Btree = new BinarySearchTree<Integer>();
        Btree.add(2);
        Btree.add(1);
        Btree.add(12);
        Btree.add(20);
        Btree.add(11);
        
        
        Btree.inOrder();
        Iterator it = Btree.iterator();
        boolean result = it.hasNext();
        boolean expResult = true;
        
     
        assertEquals(expResult, result);
    }
    
}
