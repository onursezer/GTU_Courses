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
public abstract class Assignments {
    
    private String name;
    private String dateOfIssue;
    private String  deadline;
    private String lateDeadline;
    private String ID;
    public ArrayList <StudentUploadAssign> studentUpload = new ArrayList <StudentUploadAssign>();

    public Assignments(String name, String dateOfIssue, String deadline, String lateDeadline, String ID) {
        this.name = name;
        this.dateOfIssue = dateOfIssue;
        this.deadline = deadline;
        this.lateDeadline = lateDeadline;
        this.ID = ID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDateOfIssue() {
        return dateOfIssue;
    }

    public void setDateOfIssue(String dateOfIssue) {
        this.dateOfIssue = dateOfIssue;
    }

    public String getDeadline() {
        return deadline;
    }

    public void setDeadline(String deadline) {
        this.deadline = deadline;
    }

    public String getLateDeadline() {
        return lateDeadline;
    }

    public void setLateDeadline(String lateDeadline) {
        this.lateDeadline = lateDeadline;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }
       
}
