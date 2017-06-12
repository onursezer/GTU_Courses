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
public class PostfixEvaluatorTest {
    
    public PostfixEvaluatorTest() {
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
     * Test of freeTemporaryRegister method, of class PostfixEvaluator.
     */
    @Test
    public void testFreeTemporaryRegister() {
        System.out.println("freeTemporaryRegister");
        PostfixEvaluator instance = new PostfixEvaluator();
        Register r1 = new Register();
        r1.setTemporary(true);
        Register r2 = new Register();
        r2.setTemporary(true);
        Register r3 = new Register();
        r3.setTemporary(true);
        Register r4 = new Register();
        r4.setTemporary(true);
        Register r5 = new Register();
        r5.setTemporary(true);
        Register r6 = new Register();
        r6.setTemporary(true);
        Register r7 = new Register();
        r7.setTemporary(true);
        Register r8 = new Register();
        r8.setTemporary(true);
        Register r9 = new Register();
        r9.setTemporary(true);
        instance.register.add(r1);
        instance.register.add(r2);
        instance.register.add(r3);
        instance.register.add(r4);
        instance.register.add(r5);
        instance.register.add(r6);
        instance.register.add(r7);
        instance.register.add(r8);
        instance.register.add(r9);       
        
        int expResult = 0;
        int result = instance.freeTemporaryRegister();
        assertEquals(expResult, result);
    }

    /**
     * Test of isNumeric method, of class PostfixEvaluator.
     */
    @Test
    public void testIsNumeric() {
        System.out.println("isNumeric");
        String str = "12";
        PostfixEvaluator instance = new PostfixEvaluator();
        boolean expResult = true;
        boolean result = instance.isNumeric(str);
        assertEquals(expResult, result);
    }

    /**
     * Test of setRegister method, of class PostfixEvaluator.
     */
    @Test
    public void testSetRegister() {
        System.out.println("setRegister");
        
        Register r1 = new Register();
        int index = 0;
        boolean b = false;
        int value = 0;
        PostfixEvaluator instance = new PostfixEvaluator();
        instance.register.add(r1);
        boolean expResult = true;
        boolean result = instance.setRegister(index, b, value);
        assertEquals(expResult, result);
    }

    /**
     * Test of evalOp method, of class PostfixEvaluator.
     */
    @Test
    public void testEvalOp() throws Exception {
        System.out.println("evalOp");
        PostfixEvaluator instance = new PostfixEvaluator();
        Register r1 = new Register();
        r1.setId("a");
        r1.setRegisterName("a");
        r1.setTemporary(false);
        r1.setValue(12);
        instance.register.add(r1);
        instance.operandStack.push("a");
        String op = "print";  
        instance.evalOp(op);
        boolean result;
        if(instance.assembly.get(1).equals("move      $a0, a"))
            result = true;
        else
            result = false;
        boolean expResult = true;
        assertEquals(expResult, result);   
        
    }

    /**
     * Test of isOperator method, of class PostfixEvaluator.
     */
    @Test
    public void testIsOperator() {
        System.out.println("isOperator");
        String str = "/";
        PostfixEvaluator instance = new PostfixEvaluator();
        boolean expResult = true;
        boolean result = instance.isOperator(str);
        assertEquals(expResult, result);
    }

    /**
     * Test of eval method, of class PostfixEvaluator.
     */
    @Test
    public void testEval() throws Exception {
        System.out.println("eval");
        String expression = "3 a ";
        PostfixEvaluator instance = new PostfixEvaluator();
        boolean expResult = true;
        boolean result = instance.eval(expression);
        assertEquals(expResult, result);
    }
    
}
