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
public interface Student {
    public boolean registerCource(Courses course);
    public boolean  uploadAssignment(Courses course, Assignments assign);
    public boolean listMaterials(Courses course);
}
