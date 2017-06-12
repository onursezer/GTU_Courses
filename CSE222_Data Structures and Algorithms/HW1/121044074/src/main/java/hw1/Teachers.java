package hw1;

/**
 *
 * @author Onur Sezer
 */
public class Teachers extends Users implements SetCourse, Teacher  {

    public Teachers(String name, String surname, String ID) {
        super(name, surname, ID);
    }

    
    /**
     * Teacher kendi dersine asssignment verir
     * @param course : Assignment verilen course un objesi
     * @param assignments : Teacherin assignment vercegi assignemn objesi
     * @return boolean
     */
    @Override
    public boolean addAssign(Courses course, Assignments assignments)
    {
        int status = 0;
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher().getID() == this.getID())
            {
                    system.courses.get(i).assigns.add(assignments);
                    return true;
            }
        }
        throw new IllegalArgumentException("Illegel argument was entered !");
    }
     /**
     * Teacher kendi dersine material verir
     * @param course : Material verilen course un objesi
     * @param material : Teacherin material vercegi material objesi
     * @return boolean
     */
    @Override
    public boolean addMetarial(Courses course, Materials material)
    {
        int status = 0; 
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher().getID() == this.getID())
            {
                    system.courses.get(i).materials.add(material);
                    return true;
            }
        }
        throw new IllegalArgumentException("Illegel argument was entered !");
    }
    /**
     * Teacher kendisine ait olan course a student ekleme islemi yapar
     * @param course Student in, eklenmek istenilen course un objesi
     * @param student  course a eklencek olan student in objesi
     * @return boolean
     */
    @Override
    public boolean addStudentToCource(Courses course, Students student) {
        int status = 0;
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher().getID() == this.getID())
            {
                    system.courses.get(i).students.add(student);
                    return true;
            }    
        }
        throw new IllegalArgumentException("Illegel argument was entered !");
    }

    /**
     * Teacher kendisine ait olan course a tutor ekleme islemi yapar
     * @param course Tutor un, eklenmek istenilen course un objesi
     * @param tutor  course a eklencek olan tutor iun objesi
     * @return boolean
     */
    @Override
    public boolean addTutorToCource(Courses course, Tutors tutor) {
        int status = 0;
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher().getID() == this.getID())
            {
                    system.courses.get(i).tutors.add(tutor);
                    return true;
            }
        }
        throw new IllegalArgumentException("Illegel argument was entered !");
    }

    /**
     * Teacher kendine ait olan course dan student cikarir
     * @param course: student in cikarilacagi couce in objesi
     * @param student course dan cikarilacak olan stutent in objesi
     * @return boolean
     */
    @Override
    public boolean removeStudentFromCource(Courses course, Students student) {
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher().getID() == this.getID())
            {
                for (int j = 0; j < system.courses.get(i).students.size(); j++) 
                    if(system.courses.get(i).students.get(j).getID() == student.getID())
                    {
                        system.courses.get(i).students.remove(j);
                        return  true;
                    }
            }    
        }
        throw new IllegalArgumentException("Illegel argument was entered !");
    }
    /**
     * Teacher kendi dersine student in enroll unu kabul eder
     * @return boolean
     */
    @Override
    public boolean enrollStudentCource(Courses course) {
        int status = 0, count = 0; 

        for (int i = 0; i < system.enroll.size(); i++) {
            for (int j = 0; j < system.courses.size(); j++) {
                if((system.enroll.get(i).getCourseID()  == course.getCourseID() && system.courses.get(j).getCourseID() == course.getCourseID() )
                        && system.courses.get(j).getTeacher().getID() == this.getID())
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
     * Teacher verdigi cource larda studentlerin assingmnetlirini notlandirir
     * @param course : Teacherin verdigi courcse in objesi
     * @param student : Course u alan student in objesi
     * @param grade : Student in assingment ini verilecek olan puan 
     * @param assignID : Teacherin verdigi assignmentin id si
     * @return  : boolean
     */
    @Override
    public boolean giveGrade(Courses course, Students student, int grade, String assignID)
    {
        for (int i = 0; i < system.courses.size(); i++) {
            if(system.courses.get(i).getCourseID() == course.getCourseID())
            {
                for (int j = 0; j < system.courses.get(i).assigns.size(); j++) {
                    if(system.courses.get(i).assigns.get(j).getID() == assignID)
                    {
                        for (int k = 0; k < system.courses.get(i).assigns.get(j).studentUpload.size(); k++) {
                            if(system.courses.get(i).assigns.get(j).studentUpload.get(k).getStudent().getID() == student.getID())
                            {
                                system.courses.get(i).assigns.get(j).studentUpload.get(k).setGrade(grade);
                                return true;
                            }
                            
                        }
                    }
                    
                }
            }
            
        }
        throw new IllegalArgumentException("Illegel argument was entered !");
    }
    /**
     * Teacher class i icin toSting methodu override edildi
     * @return String
     */
    @Override
    public String toString() {
        return "Teacher - " + getID() + ", " + getName() + ", " + getSurname();
    }
    /**
     * Teacher course a kendini ekler
     * @param course : Teacher in kendini ekleyecegi kursun objesi
     * @param teacher : Course a eklencek olcak olan obje, teacher course a sadece kendini ekler
     * @return 
     */
    @Override
    public boolean teacherToCourse(Courses course, Teachers teacher) {
        if(teacher == this){
            for (int i = 0; i < system.courses.size(); i++) {
                if (system.courses.get(i).getCourseID() == course.getCourseID() && system.courses.get(i).getTeacher() == null) {
                    system.courses.get(i).setTeacher(teacher);
                    return true;
                }
            }
            throw new IllegalArgumentException("There is already teacher in course !");
        }
        throw new IllegalArgumentException("You must add yourself to course!");
        
    }
    /**
     * Teacher course undaki verdigi assignment lardaki ogrencilerin notlarini listeler
     * @param course : Teacher in verdigi course in objesi
     * @param assignID : Teacherin verdi assingment in id si
     * @return  : boolean
     */
    @Override
    public boolean listStudentsGrade(Courses course, String assignID) {
        for (int i = 0; i < system.courses.size(); i++) {
            if(course.getCourseID() == system.courses.get(i).getCourseID() && system.courses.get(i).getTeacher().getID() == this.getID())
            {
                for (int j = 0; j < system.courses.get(i).assigns.size(); j++) {
                    if(system.courses.get(i).assigns.get(j).getID() == assignID)
                    {
                        System.out.println("Notlar" + " ," + assignID);
                        for (int k = 0; k < system.courses.get(i).assigns.get(j).studentUpload.size(); k++) {
                            System.out.println("Grade : " + system.courses.get(i).assigns.get(j).studentUpload.get(k).getGrade() + ", " +
                                    system.courses.get(i).assigns.get(j).studentUpload.get(k).getStudent()); 
                        }
                        return true;
                    }
                    
                }
            }
            
        }
        throw new IllegalArgumentException("Illegel argument was entered!");
    }
    
}
