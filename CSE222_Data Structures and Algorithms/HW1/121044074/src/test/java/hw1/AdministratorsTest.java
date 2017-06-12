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
public class AdministratorsTest {
    
    public AdministratorsTest() {
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
     * Test of addUser method, of class Administrators.
     */
    @Test
    public void testAddUser() {
        System.out.println("addUser");
        Teachers user = new Teachers("onur", "sezer", "121212");
        Administrators instance = new Administrators("admin","admin","1");
        boolean expResult = true;
        boolean result = instance.addUser(user);
        assertEquals(expResult, result);
    }

    /**
     * Test of removeUser method, of class Administrators.
     */
    @Test
    public void testRemoveUser() {
        System.out.println("removeUser");
        Teachers user = new Teachers("onur", "sezer", "121212");
        Administrators instance = new Administrators("admin","admin","1");
        system.users.add(user);
        boolean expResult = true;
        boolean result = instance.removeUser(user);
        assertEquals(expResult, result);
    }

    /**
     * Test of addCource method, of class Administrators.
     */
    @Test
    public void testAddCource() {
        System.out.println("addCource");
        Courses course = new Courses("cse241", "object oriented");
        Administrators instance = new Administrators("admin","admin","1");
        system.courses.add(course);
        boolean expResult = true;
        boolean result = instance.addCource(course);
        assertEquals(expResult, result);
    }

    /**
     * Test of removeCource method, of class Administrators.
     */
    @Test
    public void testRemoveCource() {
        System.out.println("removeCource");
        Courses course = new Courses("cse241", "object oriented");
        Administrators instance = new Administrators("admin","admin","1");
        boolean expResult = true;
        system.courses.add(course);
        boolean result = instance.removeCource(course);
        assertEquals(expResult, result);
    }

    /**
     * Test of teacherToCourse method, of class Administrators.
     */
    @Test
    public void testTeacherToCourse() {
        System.out.println("teacherToCourse");
        Courses course = new Courses("cse241", "object oriented");
        Teachers teacher = new Teachers("onur", "sezer", "121212");
        Administrators instance = new Administrators("onur", "sezer", "1");
        system.courses.add(course);
  
        boolean expResult = true;
        boolean result = instance.teacherToCourse(course, teacher);
        assertEquals(expResult, result);
    }
    @Test
    public void testToString() {
        System.out.println("toString");
        Administrators instance = new Administrators("onur", "sezer", "1213");
        String expResult = "Admin - " + instance.getID() + ", " + instance.getName() + ", " + instance.getSurname();
        String result = instance.toString();
        assertEquals(expResult, result);
    }
    
}
