/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw1;

import static hw1.Users.system;
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
public class StudentsTest {
    
    public StudentsTest() {
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
     * Test of registerCource method, of class Students.
     */
    @Test
    public void testRegisterCource() {
        System.out.println("registerCource");
        Courses course = new Courses("cse241", "object oriented");
        Students instance = new Students("onur", "sezer", "1213");
        boolean expResult = true;
        boolean result = instance.registerCource(course);
        assertEquals(expResult, result);
    }

    /**
     * Test of uploadAssignment method, of class Students.
     */
    @Test
    public void testUploadAssignment() {
        System.out.println("uploadAssignment");
        Courses course = new Courses("cse241", "object oriented");
        Students instance = new Students("onur", "sezer", "1213");
        Homeworks assign = new Homeworks("Homework 01", "25.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1");
        system.courses.add(course);
        system.courses.get(0).students.add(instance);
        system.courses.get(0).assigns.add(assign);
        boolean expResult = true;
        boolean result = instance.uploadAssignment(course, assign);
        assertEquals(expResult, result);
    }

    /**
     * Test of listMaterials method, of class Students.
     */
    @Test
    public void testListMaterials() {
        System.out.println("listMaterials");
        Courses course = new Courses("cse241", "object oriented");
        Students instance = new Students("onur", "sezer", "1213");
        system.courses.add(course);
        system.courses.get(0).students.add(instance);
        boolean expResult = true;
        boolean result = instance.listMaterials(course);
        assertEquals(expResult, result);
    }
    
}
