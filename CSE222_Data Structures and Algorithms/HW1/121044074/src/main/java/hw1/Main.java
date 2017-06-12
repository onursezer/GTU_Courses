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
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {   
        Administrators admin = new Administrators("Admin", "Admin", "000");
        System.out.println("Administrator olusturuldu.\n");

        Students s1 = new Students("Onur", "Sezer", "121044074");
        Students s2 = new Students("Recep", "Sivri", "121044038");
        Students s3 = new Students("Emre", "Dulundu", "131044044");
        Students s4 = new Students("Hasan", "Bilgin", "121044077");
        Students s5 = new Students("Ali", "Yılmaz", "131044001");
        Students s6 = new Students("Ahmet", "İnan", "121044007");
        Students s7 = new Students("İbrahim", "Çetinkaya", "131044003");
        Students s8 = new Students("Ercan", "Ulusoy", "121044004");
        Students s9 = new Students("Caner", "Bakar", "131044005");
        Students s10 = new Students("Mutlu", "Polatcan", "121044006");


        Tutors tutor = new Tutors("Halil", "Oymaci", "121044019");
        Tutors tutor2 = new Tutors("Emrah", "Yıldırım", "121044045");
        Tutors tutor3 = new Tutors("Ali", "Ekşi", "121044002");

        Teachers t1 = new Teachers("Fatih Erdogan", "Sevilgen", "001");
        Teachers t2 = new Teachers("Yusuf Sinan", "Akgül", "002");
        Teachers t3 = new Teachers("Mehmet", "Göktürk", "003");

        Courses c1 = new Courses("CSE222", "Data Structers and Algorithms");
        Courses c2 = new Courses("CSE241", "Object Oriented Programming");
        Courses c3 = new Courses("CSE343", "Yazilim Mühendisliği");

        System.out.println("~~~ SENERYO 1 ~~~");

        try {
            admin.addCource(c1);
            System.out.println("Admin sisteme course ekledi.");
            System.out.println("    " + c1);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.addUser(s1);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s1);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.addUser(s2);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s2);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.addUser(s3);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s3);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.addUser(s4);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s4);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.addUser(tutor);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + tutor);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.addUser(t1);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + t1);
            System.out.println("");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            admin.teacherToCourse(c1, t1);
            System.out.println("Admin course a teacher atadi.");
            System.out.println("    " + c1);
            System.out.println("    " + t1);
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            s1.registerCource(c1);
            System.out.println(s1 + ", " + c1.getCourseID() + " dersine kayit olmak icin basvurdu." );
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            s2.registerCource(c1);
            System.out.println(s2 + ", " + c1.getCourseID() + " dersine kayit olmak icin basvurdu." );
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            s3.registerCource(c1);
            System.out.println(s3 + ", " + c1.getCourseID() + " dersine kayit olmak icin basvurdu." );
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            s4.registerCource(c1);
            System.out.println(s4 + ", " + c1.getCourseID() + " dersine kayit olmak icin basvurdu." );
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t1.enrollStudentCource(c1);
            System.out.println(t1 + ", " + c1.getCourseID() + " dersine kayıt olmak icin basvuran studentleri enroll etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t1.addTutorToCource(c1, tutor);
            System.out.println(t1 + ", " + c1.getCourseID() + " dersine tutor olarak, " + tutor + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t1.addAssign(c1, new Homeworks("Homework 01", "24.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1"));
            System.out.println(t1 + ", " + c1.getCourseID() +  " dersine Homework verdi.\n");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            s1.uploadAssignment(c1, new Homeworks("Homework 01", "25.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1"));
            System.out.println(s1 + ", " + c1.getCourseID() + ", dersindeki cse222-hw1 e UPLOAD etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            s2.uploadAssignment(c1, new Homeworks("Homework 01", "26.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1"));
            System.out.println(s2 + ", " + c1.getCourseID() + ", dersindeki cse222-hw1 e UPLOAD etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            s3.uploadAssignment(c1, new Homeworks("Homework 01", "27.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1"));
            System.out.println(s3 + ", " + c1.getCourseID() + ", dersindeki cse222-hw1 e UPLOAD etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            s4.uploadAssignment(c1, new Homeworks("Homework 01", "28.02.2016", "01.03.2016", "03.03.2016", "cse222-hw1"));
            System.out.println(s4 + ", " + c1.getCourseID() + ", dersindeki cse222-hw1 e UPLOAD etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t1.giveGrade(c1, s1, 80, "cse222-hw1");
            System.out.println(t1 + ", " + s1.getID() + ", studentina cse222-hw1 icin GRADE verdi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.giveGrade(c1, s2, 85, "cse222-hw1");
            System.out.println(t1 + ", " + s2.getID() + ", studentina cse222-hw1 icin GRADE verdi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.giveGrade(c1, s3, 85, "cse222-hw1");
            System.out.println(t1 + ", " + s3.getID() + ", studentina cse222-hw1 icin GRADE verdi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.giveGrade(c1, s4, 90, "cse222-hw1");
            System.out.println(t1 + ", " + s4.getID() + ", studentina cse222-hw1 icin GRADE verdi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t1.listStudentsGrade(c1, "cse222-hw1");
            System.out.println(t1 + ", cse222-hw1 i upload eden student larin gradelerini LISTeledi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t1.addMetarial(c1, new Urls("http://www.tutorialspoint.com/java/java_exceptions.htm", "24.02.2016"));
            System.out.println(t1 +  ", " + c1.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.addMetarial(c1, new Books("Data Structures abstraction and design using java", "01.02.2016"));
            System.out.println(t1 +  ", " + c1.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.addMetarial(c1, new Slides("Slide-1", "03.02.2016"));
            System.out.println(t1 + ", " + c1.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.addMetarial(c1, new WhiteboardDescriptions("Yarin Quiz yapilacaktir", "06.01.2016"));
            System.out.println(t1 +  ", " + c1.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t1.addMetarial(c1, new Files("silede.zip", "11.02.2016"));
            System.out.println(t1 +  ", " + c1.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            tutor.listMaterials(c1);
            System.out.println(tutor + ", " + c1.getCourseID() + " dersinin materyellerini listeledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        System.out.println("~~~ SENERYO 2 ~~~");
        try {
            admin.addUser(s5);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s5);
            System.out.println();
            admin.addUser(s6);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s6);
            System.out.println();
            admin.addUser(s7);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s7);
            System.out.println();
            admin.addUser(s8);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s8);
            System.out.println();
            admin.addUser(s9);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s9);
            System.out.println();
            admin.addUser(s10);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + s10);
            System.out.println();
            admin.addUser(tutor2);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + tutor2);
            System.out.println();
            admin.addUser(tutor3);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + tutor3);
            System.out.println();
            admin.addUser(t2);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + t2);
            System.out.println();
            admin.addUser(t3);
            System.out.println("Admin sisteme user ekledi.");
            System.out.println("    " + t3);
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try{
            admin.addCource(c2);
            System.out.println("Admin sisteme course ekledi.");
            System.out.println("    " + c2);
            System.out.println();
            admin.addCource(c3);
            System.out.println("Admin sisteme course ekledi.");
            System.out.println("    " + c3);
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.teacherToCourse(c2, t2);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersini secti.");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.addStudentToCource(c2,s5);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s5 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try{
            t2.addStudentToCource(c2,s6);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s6 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try{
            t2.addStudentToCource(c2,s7);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s7 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.addStudentToCource(c2,s8);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s8 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.addStudentToCource(c2,s9);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s9 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.addStudentToCource(c2,s10);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s10 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.addStudentToCource(c2,s1);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + s1 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try{
            t2.removeStudentFromCource(c2, s5);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersinden " + s5 + ", cikardi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t2.addTutorToCource(c2,tutor2);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + tutor2 + ", ekledi");
            System.out.println();
            t2.addTutorToCource(c2,tutor3);
            System.out.println(t2 + ", " + c2.getCourseID() + " dersine " + tutor3 + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t2.addMetarial(c2, new Urls("http://stackoverflow.com/questions/7486012/static-classes-in-java", "24.02.2016"));
            System.out.println(t1 +  ", " + c2.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t2.addMetarial(c2, new Books("Object Oriented Programming", "01.02.2016"));
            System.out.println(t1 +  ", " + c2.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t2.addMetarial(c2, new Slides("Slide-4", "03.02.2016"));
            System.out.println(t1 + ", " + c2.getCourseID() + " dersine materyal ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            s1.listMaterials(c2);
            System.out.println(s1 + ", " + c2.getCourseID() + " dersinin materyellerini listeledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try
        {
            t2.teacherToCourse(c3, t2);
            System.out.println(t2 + ", " + c3.getCourseID() + " dersini secti.");
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try
        {
            t2.addStudentToCource(c3, s5);
            System.out.println(t2 + ", " + c3.getCourseID() + " dersine " + s5 + ", ekledi");
            System.out.println();
            t2.addStudentToCource(c3, s4);
            System.out.println(t2 + ", " + c3.getCourseID() + " dersine " + s4 + ", ekledi");
            System.out.println();
            t2.addTutorToCource(c3, tutor);
            System.out.println(t2 + ", " + c3.getCourseID() + " dersine " + tutor + ", ekledi");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            t2.addAssign(c3, new Quizs("Quiz 1", "21.02.2016", "24.02.2016", "26.20.2016", "cse343-quiz1"));

            System.out.println(t2 + ", " + c3.getCourseID() +  " dersine Quiz verdi.\n");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }

        try {
            s5.uploadAssignment(c3, new Quizs("Quiz 1", "25.02.2016", "01.03.2016", "03.03.2016", "cse343-quiz1"));
            System.out.println(s5 + ", " + c3.getCourseID() + ", dersindeki cse343-quiz1 e UPLOAD etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            s4.uploadAssignment(c3, new Quizs("Quiz 1", "25.02.2016", "01.03.2016", "03.03.2016", "cse343-quiz1"));
            System.out.println(s4 + ", " + c3.getCourseID() + ", dersindeki cse343-quiz1 e UPLOAD etti.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t2.giveGrade(c3,s5,88,"cse343-quiz1");
            System.out.println(t2 + ", " + s5.getID() + ", studentina cse343-quiz1 icin GRADE verdi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t2.giveGrade(c3,s4,92,"cse343-quiz1");
            System.out.println(t2 + ", " + s4.getID() + ", studentina cse343-quiz1 icin GRADE verdi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
        try {
            t2.listStudentsGrade(c3,"cse343-quiz1");
            System.out.println(t2 + ", cse343-quiz1 i upload eden student larin gradelerini LISTeledi.");
            System.out.println();
        }
        catch(IllegalArgumentException e){
            e.printStackTrace();
        }
    }
    
}
