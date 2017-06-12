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
class StudentEnroll {
    
    private String courceID;
    private Students student;

    public StudentEnroll(String courceID, Students student) {
        this.courceID = courceID;
        this.student = student;
    }

    public String getCourseID() {
        return courceID;
    }

    public void setCourceID(String courceID) {
        this.courceID = courceID;
    }

    public Students getStudent() {
        return student;
    }

    public void setStudent(Students student) {
        this.student = student;
    }
    
    
}
