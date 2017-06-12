/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw6;

import java.io.PrintStream;
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
public class HuffmanTreeTest {
    
    public HuffmanTreeTest() {
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
     * Test of encode method, of class HuffmanTree.
     */
    @org.junit.Test
    public void testEncode() {
        System.out.println("encode");
        
        
        
        HuffmanTree Htree = new HuffmanTree();
        
        // Create symbol array
        HuffmanTree.HuffData[] symbols = {
                    new HuffmanTree.HuffData(186, '_'),
                    new HuffmanTree.HuffData(103, 'e'),
                    new HuffmanTree.HuffData(80, 't'),
                    new HuffmanTree.HuffData(64, 'a'),
                    new HuffmanTree.HuffData(63, 'o'),
                    new HuffmanTree.HuffData(57, 'i'),
                    new HuffmanTree.HuffData(57, 'n'),
                    new HuffmanTree.HuffData(51, 's'),
                    new HuffmanTree.HuffData(48, 'r'),
                    new HuffmanTree.HuffData(47, 'h'),
                    new HuffmanTree.HuffData(32, 'd'),
                    new HuffmanTree.HuffData(32, 'l'),
                    new HuffmanTree.HuffData(23, 'u'),
                    new HuffmanTree.HuffData(22, 'c'),
                    new HuffmanTree.HuffData(21, 'f'),
                    new HuffmanTree.HuffData(20, 'm'),
                    new HuffmanTree.HuffData(18, 'w'),
                    new HuffmanTree.HuffData(16, 'y'),
                    new HuffmanTree.HuffData(15, 'g'),
                    new HuffmanTree.HuffData(15, 'p'),
                    new HuffmanTree.HuffData(13, 'b'),
                    new HuffmanTree.HuffData(8, 'v'),
                    new HuffmanTree.HuffData(5, 'k'),
                    new HuffmanTree.HuffData(1, 'j'),
                    new HuffmanTree.HuffData(1, 'q'),
                    new HuffmanTree.HuffData(1, 'x'),
                    new HuffmanTree.HuffData(1, 'z')
        };
         Htree.buildTree(symbols);
        
        String result = Htree.encode("q__rg", null);;
        System.out.println("asadd : "+result);
        String expResult = "11000010011111110010100001"; 
        
        assertEquals(expResult, result);

    }

    
}
