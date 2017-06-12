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
public class Students extends Users implements Student{

    public Students(String name, String surname, String ID) {
        super(name, surname, ID);
    }
    
    @Override
    public String toString() {
        return "Student - " + getID() + ", " + getName() + ", " + getSurname();
    }

    /**
     * Student bir course a enroll icin istek gonderir
     * @param course : student in register etmek istedigi course un objesi
     * @return 
     */
    @Override
    public boolean registerCource(Courses course)
    {
        StudentEnroll enroll = new StudentEnroll(course.getCourseID(),this);
        system.enroll.add(enroll);       
        return true;
    }
    /**
     * Student kayitli oldugu course da teacherin verdigi assignmenta upload yapar
     * @param course : Student in upload edecegi course un objesi
     * @param assign
     * @return 
     */
    @Override
    public boolean  uploadAssignment(Courses course, Assignments assign)
    {
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID())
            {
                for (int j = 0; j < system.courses.get(i).students.size(); j++) {
                    if(system.courses.get(i).students.get(j).getID() == this.getID())
                    {
                        for (int k = 0; k < system.courses.get(i).assigns.size(); k++) {
                            if(system.courses.get(i).assigns.get(k).getID() == assign.getID()){
                                system.courses.get(i).assigns.get(k).studentUpload.add(new StudentUploadAssign(this, assign));
                                return true;
                            }  
                        }
                    }
                }
            }
            
        }
        throw new IllegalArgumentException("Illegel argument was entered ! ");
    }
    
    /**
     * Student aldigi course daki verilen material leri listeler
     * @param course : studentin aldigi course un objesi
     * @return
     */
    @Override
    public boolean listMaterials(Courses course) {
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID())
            {
                for (int j = 0; j < system.courses.get(i).students.size(); j++) {
                    if(system.courses.get(i).students.get(j).getID() == this.getID())
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
