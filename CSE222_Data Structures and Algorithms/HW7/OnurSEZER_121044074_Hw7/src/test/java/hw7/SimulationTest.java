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
public class SimulationTest {
    
    public SimulationTest() {
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
     * Test of CustomerSimulation method, of class Simulation.
     */
    @Test
    public void testCustomerSimulation() throws Exception 
    {
        System.out.println("CustomerSimulation");
        boolean expResult = true, result;
        Simulation instance = new Simulation("data1.txt");
        instance.CustomerSimulation();                 // Dogru calistigini gostermek icic iki cikti kontrol edilmistir  
        if(instance.printCustomer.get(0).equals("08:30 müsteri girdi 08:42 müsteri cikti-> Onceligi : Customer 1")
            &&   instance.printCustomer.get(1).equals("08:36 müsteri girdi 08:50 müsteri cikti-> Onceligi : Customer 3")  )    
            result = true;
        else
            result = false;
            
        assertEquals(expResult, result);
    }
    /**
     * Test of CustomerSimulation method, of class Simulation.
     */
    @Test
    public void testCustomerSimulation2() throws Exception 
    {
        System.out.println("CustomerSimulation");
        boolean expResult = true, result;
        Simulation instance = new Simulation("data2.txt");
        instance.CustomerSimulation();                 // Dogru calistigini gostermek icic iki cikti kontrol edilmistir  
        if(instance.printCustomer.get(0).equals("00:00 müsteri girdi 00:13 müsteri cikti-> Onceligi : Customer 3")
            &&   instance.printCustomer.get(1).equals("00:05 müsteri girdi 00:24 müsteri cikti-> Onceligi : Customer 3")  )    
            result = true;
        else
            result = false;
            
        assertEquals(expResult, result);
    }
    
}
