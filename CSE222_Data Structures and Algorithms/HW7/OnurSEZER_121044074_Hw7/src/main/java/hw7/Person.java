package hw7;

/**
 *
 * @author Onur Sezer
 */
public class Person {
    // Data Fields
    private String name;
    private int  studentCard;
    private int academicCard;

    // Constructor
    public Person(String name, int studentCard, int academicCard) {
        this.name = name;
        this.studentCard = studentCard;
        this.academicCard = academicCard;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getStudentCard() {
        return studentCard;
    }

    public void setStudentCard(int studentCard) {
        this.studentCard = studentCard;
    }

    public int getAcademicCard() {
        return academicCard;
    }

    public void setAcademicCard(int academicCard) {
        this.academicCard = academicCard;
    }

    @Override
    public String toString() {
        return name + "  " + studentCard + "  " + academicCard;
    }

    

    
    
    
    
}
