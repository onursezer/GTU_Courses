/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw4;

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
public class InfixToPostfixTest {
    
    public InfixToPostfixTest() {
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
     * Test of processOperator method, of class InfixToPostfix.
     */
    @Test
    public void testProcessOperator() {
        System.out.println("processOperator");
        String op = "print";
        InfixToPostfix instance = new InfixToPostfix();
        boolean expResult = true;
        boolean result = instance.processOperator(op);
        assertEquals(expResult, result);
    }

    /**
     * Test of convert method, of class InfixToPostfix.
     */
    @Test
    public void testConvert() throws Exception {
        System.out.println("convert");
        String infix = "b = a - c - b * 3";
        InfixToPostfix instance = new InfixToPostfix();
        String expResult = "b a c - b 3 * - = ";
        String result = instance.convert(infix);
        assertEquals(expResult, result);
    }

    /**
     * Test of isOperator method, of class InfixToPostfix.
     */
    @Test
    public void testIsOperator() {
        System.out.println("isOperator");
        String str = "print";
        InfixToPostfix instance = new InfixToPostfix();
        boolean expResult = true;
        boolean result = instance.isOperator(str);
        assertEquals(expResult, result);
    }

    /**
     * Test of precedence method, of class InfixToPostfix.
     */
    @Test
    public void testPrecedence() {
        System.out.println("precedence");
        char op = '=';
        InfixToPostfix instance = new InfixToPostfix();
        int expResult = -1;
        int result = instance.precedence(op);
        assertEquals(expResult, result);
    }
    
}
