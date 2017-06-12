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
public interface Teacher {
    public boolean addAssign(Courses course, Assignments assignments);
    public boolean addMetarial(Courses course, Materials material);
    public boolean addStudentToCource(Courses course, Students student);
    public boolean addTutorToCource(Courses course, Tutors tutor);
    public boolean removeStudentFromCource(Courses course, Students student);
    public boolean giveGrade(Courses course, Students student, int grade, String assignID);
    public boolean listStudentsGrade(Courses course, String assignID);
}
