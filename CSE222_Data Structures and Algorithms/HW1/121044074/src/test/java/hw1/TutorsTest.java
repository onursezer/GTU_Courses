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
public class TutorsTest {
    
    public TutorsTest() {
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
     * Test of toString method, of class Tutors.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        Tutors instance = new Tutors("onur", "sezer", "1213");
        String expResult = "Tutor - " + instance.getID() + ", " + instance.getName() + ", " + instance.getSurname();;
        String result = instance.toString();
        assertEquals(expResult, result);
    }

    /**
     * Test of listMaterials method, of class Tutors.
     */
    @Test
    public void testListMaterials() {
        System.out.println("listMaterials");
        Courses course = new Courses("cse241", "object oriented");
        Tutors instance = new Tutors("onur", "sezer", "1213");
        system.courses.add(course);
        system.courses.get(0).tutors.add(instance);
        boolean expResult = true;
        boolean result = instance.listMaterials(course);
        assertEquals(expResult, result);
    }
    
}
