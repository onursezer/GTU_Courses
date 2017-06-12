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
public abstract class Materials {
    
    private String name;
    private String dateOfIssue;

    public Materials(String name, String dateOfIssue) {
        this.name = name;
        this.dateOfIssue = dateOfIssue;
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

    @Override
    public String toString() {
        return "Material - " + ", " + getName() + ", " + getDateOfIssue();
    }

    
}
