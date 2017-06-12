package hw7;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Enumeration;
import java.util.Hashtable;

/**
 *
 * @author Onur Sezer
 */
public class Part2 {
    Hashtable table = new Hashtable();
    int student[] = new int[500];
    int academic[] = new int[500];
    
    /**
     * tabloyu doldurmak icin file'dan okuma yapar
     * @throws IOException 
     */
    public void readFile() throws IOException
    {
        BufferedReader rd = new BufferedReader( new FileReader("table.txt"));    
        int count = 0;
        String str, name = null;
        int stdCard = 0, acaCard = 0;
        String[] words;

        try
        {
            while((str = rd.readLine()) != null)
            {
                if(count != 0) 
                {
                    words = str.split("\\s+");
                    for (int i = 0; i < words.length; i++) 
                    {
                        words[i] = words[i].replaceAll("[^\\w]", "");
                        if(i == 0)
                        {
                            name = words[i];
                        }
                        else if(i == 1)
                        {
                            if(words[i].equals("null"))
                                stdCard = 0;
                            else
                                stdCard = Integer.parseInt(words[i]);
                            student[count - 1] = stdCard;
                        }
                        else if(i == 2)
                        {
                            acaCard = Integer.parseInt(words[i]);
                            academic[count - 1] = acaCard;
                        }
                    }
                    
                    table.put(31*31*acaCard + 31*stdCard, new Person(name, stdCard, acaCard)); // table i dolduruyor
                    
                }
                count++;
            }
        } 
        catch (FileNotFoundException ex) 
        {
            System.err.format("File was not found\n");
        }
    }
    /**
     * alinan studentCard ve academisyenCard ı kullanarak resarch asistana esit olup olmadigina bakar
     * @param stuCard : student card id
     * @param acaCard : academisyen card id
     * @return boolean
     */
    public boolean equal(int stuCard,int acaCard)
    {
        Enumeration person;       
        person = table.keys();
        int value;
        while(person.hasMoreElements()) {
            value = (int) person.nextElement();
            if(value == 31*31*acaCard + 31*stuCard)
            {
                System.out.println(((Person)table.get(value)).getName() + " is resarch asistant. Student Card -> " + ((Person)table.get(value)).getStudentCard() +
                    ", Academic Card -> " + ((Person)table.get(value)).getAcademicCard() + ", New card id -> " + value );
                return true;
            }
        }
        return false;
    }
    /**
     * tablonun hepsini dolasir
     */
    public void cont()
    {
        for (int i = 0; i < 500; i++)
        {
            if(student[i] != 0)
                if(equal(student[i],academic[i]))
                    System.out.println("true");
        }
    }
   
}
