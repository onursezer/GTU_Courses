/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw1;

/**
 *
 * @author Onur Sezer
 */
public class StudentUploadAssign {
    private Students student;
    private Assignments assign;
    private int grade;

    public StudentUploadAssign(Students student, Assignments assign) {
        this.student = student;
        this.assign = assign;
    }

    public Students getStudent() {
        return student;
    }

    public void setStudent(Students student) {
        this.student = student;
    }

    public Assignments getAssign() {
        return assign;
    }

    public void setAssign(Assignments assign) {
        this.assign = assign;
    }

    public int getGrade() {
        return grade;
    }

    public void setGrade(int grade) {
        this.grade = grade;
    }
    
}
