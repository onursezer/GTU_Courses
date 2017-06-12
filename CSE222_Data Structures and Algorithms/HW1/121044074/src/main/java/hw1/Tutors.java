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
public class Tutors extends Students {

    public Tutors(String name, String surname, String ID) {
        super(name, surname, ID);
    }

    @Override
    public String toString() {
        return "Tutor - " + getID() + ", " + getName() + ", " + getSurname();
    }
    public boolean listMaterials(Courses course) {
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID())
            {
                for (int j = 0; j < system.courses.get(i).tutors.size(); j++) {
                    if(system.courses.get(i).tutors.get(j).getID() == this.getID())
                    {
                        for (int k = 0; k < system.courses.get(i).materials.size(); k++)
                            System.out.println(system.courses.get(i).materials.get(k));
                        return true;
                    }
                }
            }

        }
        throw new IllegalArgumentException("Illegel argument was entered ! ");
    }
    
}
