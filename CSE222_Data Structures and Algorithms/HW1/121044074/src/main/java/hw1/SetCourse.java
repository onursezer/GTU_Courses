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
public interface SetCourse 
{
    public boolean teacherToCourse(Courses course, Teachers teacher);
    public boolean enrollStudentCource(Courses course);
}
