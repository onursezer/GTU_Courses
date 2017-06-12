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
public class TeachersTest {
    
    public TeachersTest() {
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
     * Test of addAssign method, of class Teachers.
     */
    @Test
    public void testAddAssign() {
        System.out.println("addAssign");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Homeworks assign = new Homeworks("Homework 01", "25.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1");
        system.courses.add(course);
        system.courses.get(0).setTeacher(instance);

        boolean expResult = true;
        boolean result = instance.addAssign(course, assign);
        assertEquals(expResult, result);
    }

    /**
     * Test of addMetarial method, of class Teachers.
     */
    @Test
    public void testAddMetarial() {
        System.out.println("addMetarial");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Books material = new Books("Object Oriented Programming", "01.02.2016");
        system.courses.get(0).setTeacher(instance);
        boolean expResult = true;
        boolean result = instance.addMetarial(course, material);
        assertEquals(expResult, result);
    }

    /**
     * Test of addStudentToCource method, of class Teachers.
     */
    @Test
    public void testAddStudentToCource() {
        System.out.println("addStudentToCource");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Students student = new Students("onur","sezer","123");
        system.courses.add(course);
        system.courses.get(0).setTeacher(instance);
        system.courses.get(0).students.add(student);
        
        boolean expResult = true;
        boolean result = instance.addStudentToCource(course, student);
        assertEquals(expResult, result);
    }

    /**
     * Test of addTutorToCource method, of class Teachers.
     */
    @Test
    public void testAddTutorToCource() {
        System.out.println("addTutorToCource");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Tutors tutor = new Tutors("onur","sezer","123");
        system.courses.get(0).setTeacher(instance);
        boolean expResult = true;
        boolean result = instance.addTutorToCource(course, tutor);
        assertEquals(expResult, result);
    }

    /**
     * Test of removeStudentFromCource method, of class Teachers.
     */
    @Test
    public void testRemoveStudentFromCource() {
        System.out.println("removeStudentFromCource");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Students student = new Students("onur","sezer","123");
        system.courses.add(course);
        system.courses.get(0).setTeacher(instance);
        system.courses.get(0).students.add(student);
        
        boolean expResult = false;
        boolean result = instance.removeStudentFromCource(course, student);
        assertEquals(expResult, result);
    }

    /**
     * Test of giveGrade method, of class Teachers.
     */
    @Test
    public void testGiveGrade() {
        System.out.println("giveGrade");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Students student = new Students("onur","sezer","123");
        system.courses.add(course);
        system.courses.get(0).setTeacher(instance);
        system.courses.get(0).students.add(student);
        Homeworks assign = new Homeworks("Homework 01", "25.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1");
        system.courses.get(0).assigns.add(assign);
        StudentUploadAssign stu = new StudentUploadAssign(student, assign);
        system.courses.get(0).assigns.get(0).studentUpload.add(stu);
        int grade = 0;
        boolean expResult = true;
        boolean result = instance.giveGrade(course, student, grade, assign.getID());
        assertEquals(expResult, result);
    }

    /**
     * Test of toString method, of class Teachers.
     */
    @Test
    public void testToString() {
        System.out.println("toString");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        String expResult = "Teacher - " + instance.getID() + ", " + instance.getName() + ", " + instance.getSurname();
        String result = instance.toString();
        assertEquals(expResult, result);
    }

    /**
     * Test of teacherToCourse method, of class Teachers.
     */
    @Test
    public void testTeacherToCourse() {
        System.out.println("teacherToCourse");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        system.courses.add(course);
        boolean expResult = true;
        boolean result = instance.teacherToCourse(course, instance);
        assertEquals(expResult, result);
    }

    /**
     * Test of listStudentsGrade method, of class Teachers.
     */
    @Test
    public void testListStudentsGrade() {
        System.out.println("listStudentsGrade");
        Courses course = new Courses("cse241", "object oriented");
        Teachers instance = new Teachers("onur", "sezer", "1213");
        Homeworks assign = new Homeworks("Homework 01", "25.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1");
        Students student = new Students("onur","sezer","123");
        system.courses.get(0).assigns.add(assign);
        StudentUploadAssign stu = new StudentUploadAssign(student, assign);
        system.courses.get(0).assigns.get(0).studentUpload.add(stu);
        
        boolean expResult = true;
        boolean result = instance.listStudentsGrade(course, assign.getID());
        assertEquals(expResult, result);
    }
    
}
