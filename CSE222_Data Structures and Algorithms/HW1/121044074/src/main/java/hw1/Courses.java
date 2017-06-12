/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw1;

import java.util.ArrayList;

/**
 *
 * @author Onur Sezer
 */
public class Courses {
   
    private String courseID;
    private String courseName;
    private Teachers teacher = null; 
    public ArrayList <Students> students = new ArrayList <Students> ();
    public ArrayList <Tutors> tutors = new ArrayList <Tutors> ();
    public ArrayList <Assignments> assigns = new ArrayList <Assignments> ();
    public ArrayList <Materials> materials = new ArrayList <Materials> ();
    
    public Courses(String courseID, String courseName) {
        this.courseID = courseID;
        this.courseName = courseName;
    }
    
    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }
    
    public Teachers getTeacher() {
        return teacher;
    }
    
    public void setTeacher(Teachers teacher) {
        this.teacher = teacher;
    }

    public String getCourseID() {
        return courseID;
    }

    public void setCourseID(String courseID) {
        this.courseID = courseID;
    }

    @Override
    public String toString() {
        return "Course - " + getCourseID() + ", " + getCourseName();
    }
    
}
