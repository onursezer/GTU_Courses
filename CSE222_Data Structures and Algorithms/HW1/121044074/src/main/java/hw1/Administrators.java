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
public class Administrators extends Users implements SetCourse, Administrator{

    
    public Administrators(String name, String surname, String ID) 
    {
        super(name, surname, ID);
    }
   /**
    * Admin sisteme daha once eklenmemis user i ekler
    * @param user : sisteme eklencek olan user objesi
    * @return : boolean
    */
    @Override
    public boolean addUser(Users user)
    {
        int status = 0;
        
        for (int i = 0; i < system.users.size(); i++) {
            if(system.users.get(i).getID() == user.getID())
                status = -1;
        }
        if(status == 0)
        {
            system.users.add(user);
            return true;
        }
        throw new IllegalArgumentException("There is already same user!");
        
    }
    /**
     * Admin sistemde olan bir user i siler
     * @param user : sistemden silinecek user objesi
     * @return : boolean
     */
    @Override
    public boolean removeUser(Users user)
    {
        for (int i = 0; i < system.users.size(); i++) {
            if(system.users.get(i).getID() == user.getID())
            {
                system.users.remove(i);
                return true;
            }
        }
        throw new IllegalArgumentException("There is not same user!");
    } 
    /**
     * Admin sistemde daha once olmayan course i acar
     * @param course : acilacak olan course
     * @return : boolean
     */
    @Override
    public boolean addCource(Courses course) 
    {

        system.courses.add(course);
        return true; 
    }

    /**
     * Admin sistemdeki course i siler
     * @param course : sistemden silinicek olan course objesi
     * @return 
     */
    @Override
    public boolean removeCource(Courses course) {
        
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID()== course.getCourseID()){
                system.courses.remove(i);
                return true;
            }
        }
        throw new IllegalArgumentException("Course was not founded !");
    }

    /**
     * Admin course a kayıt olmak isteyen ogrencileri enroll eder
     * @param course : studentlerin kayıt olmak icin basvurdugu couse un objesi
     * @return
     */
    @Override
    public boolean enrollStudentCource(Courses course) {
        int status = 0, count = 0; 

        for (int i = 0; i < system.enroll.size(); i++) {
            for (int j = 0; j < system.courses.size(); j++) {
                if(system.enroll.get(i).getCourseID() == course.getCourseID() && system.courses.get(j).getCourseID() == course.getCourseID())
                {
                    system.courses.get(j).students.add(system.enroll.get(i).getStudent());
                    ++count;
                }
            }
        }
        system.enroll.clear();
        if(count == 0)
            throw new IllegalArgumentException("Illegel argument was entered ! ");
        return true;
    }
    /**
     * Cource a teacher atanir
     * @param course : Teacher in atilacagi couse un objesi
     * @param teacher : Course a atilacak teacher objesi
     * @return : boolean
     */
    @Override
    public boolean teacherToCourse(Courses course, Teachers teacher) {
        for (int i = 0; i < system.courses.size(); i++) {
            if (system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher() == null) {
                system.courses.get(i).setTeacher(teacher);
                return true;
            }
        }
        throw new IllegalArgumentException("There is already teacher in course !");
    }

    @Override
    public String toString() {
        return "Admin - " + getID() + ", " + getName() + ", " + getSurname();
    }
    







}
