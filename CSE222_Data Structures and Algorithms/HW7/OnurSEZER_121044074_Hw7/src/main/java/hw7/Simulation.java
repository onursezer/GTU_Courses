package hw7;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;  // File dan okunan Customerlari tutmak icin 

/**
 *
 * @author Onur Sezer
 */
public class Simulation {
    
    // Data Fields
    private ArrayList<Customer> customers = new ArrayList<Customer>(); // Customerlarin bilgilerini tutar
    public ArrayList<String> printCustomer = new ArrayList<String>(); 
    private MyPriorityQueue customerQueue= new MyPriorityQueue();
    private int sysHour, sysMin;
    private String fileName;
    private int clock = 0, twentyHour = 1200;
    private int gold=0, silver=0, bronz=0;
    private BufferedWriter wr; 
    
    /**
     * Constuctor 
     * @param fileName : Customer datalarinin alinacagi file ismi
     * @throws IOException 
     */
    public Simulation(String fileName) throws IOException {
        this.fileName = fileName;
        wr = new BufferedWriter( new FileWriter("result_" + fileName)); // sonuclarin yazilacagi file acilir
    }
    
    /**
     * filedan okuma yapar, customer arraylistine alinan customerlari atar
     * @throws IOException 
     */
    private void readFile() throws IOException
    {
        BufferedReader rd = new BufferedReader( new FileReader(fileName));    
        int count = 0;
        String str;
        String[] words;
        int ihour = 0, iminute = 0;
        int transactionDuration = 0;
        int type = 0;
        StringBuilder hour;
        StringBuilder minute;
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
                            hour = new StringBuilder();
                            minute = new StringBuilder();
                            hour.append(words[i].charAt(0));
                            hour.append(words[i].charAt(1));
                            minute.append(words[i].charAt(2));
                            minute.append(words[i].charAt(3));
                            ihour = Integer.parseInt(hour.toString());
                            iminute = Integer.parseInt(minute.toString());
                        }
                        else if(i == 1)
                        {
                            transactionDuration = Integer.parseInt(words[i]);
                        }
                        else if(i == 3)
                        {
                            type = Integer.parseInt(words[i]);
                        }
                    }
                    customers.add(new Customer(ihour, iminute, transactionDuration, type));
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
     * Customer Simulasyon islemini yapar 
     * @throws IOException 
     */
    public void CustomerSimulation() throws IOException
    {
        readFile();
        int count = 0, size = 0;
        int index = -1;
        int totalTime = 1440;
        int endTime, find = -1;
        StringBuilder builder = new  StringBuilder();
        sysHour = customers.get(0).getHour();
        sysMin = customers.get(0).getMin();
        
        while(clock <= totalTime)
        {
            for (int i = 0; i < customers.size(); i++) {
                if(customers.get(i).getTotalMin() == totalMin())
                    find = 1;
            }
            if((clock == 0) || customerQueue.getIndex() != 0 || find == 1)
            {
                find = -1;
                if(index <= customers.size() - 1)
                {
                    if(index == -1 || ((customerQueue.getIndex() == 0) && size != customers.size()))
                    {
                        //System.out.println("111111");
                        index++;
                        size++;
                        customerQueue.enqueue(customers.get(index));
                        Customer out = customerQueue.deque();
                        if(out.getCustometType() == 1)
                            gold++;
                        else if(out.getCustometType() == 2)
                            silver++;
                        else if(out.getCustometType() == 3)
                            bronz++;
                        builder.append( printClock(out.getHour(),out.getMin()) + " müsteri girdi " );  
                        updateSystemHour( out.getTransactionDuration() );
                        builder.append(printClock(sysHour,sysMin) + " müsteri cikti" + "-> Onceligi : " + "Customer " + out.getCustometType());
                        printCustomer.add(builder.toString());
                        System.out.println(builder.toString());
                        wr.write(builder.toString() + "\n");
                        increaseClock( out.getTransactionDuration() ); 
                        builder = new StringBuilder();
                        endTime = totalMin();
                        for (int i = index+1; i < customers.size(); i++) {
                            if(customers.get(i).getTotalMin() <= endTime)
                            {
                                customerQueue.enqueue(customers.get(i));
                                size++;
                                index = i;    
                            }
                        }
                    }
                    else if(customerQueue.getIndex() != 0)
                    {
                        //System.out.println("222222");
                        Customer out = customerQueue.deque();
                        if(out.getCustometType() == 1)
                            gold++;
                        else if(out.getCustometType() == 2)
                            silver++;
                        else if(out.getCustometType() == 3)
                            bronz++;
                        builder.append( printClock(out.getHour(),out.getMin()) + " müsteri girdi " );  
                        updateSystemHour( out.getTransactionDuration() );
                        builder.append(printClock(sysHour,sysMin) + " müsteri cikti" + "-> Onceligi : " + "Customer " + out.getCustometType());
                        printCustomer.add(builder.toString());
                        System.out.println(builder.toString());
                        wr.write(builder.toString() + "\n");
                        increaseClock( out.getTransactionDuration() ); 
                        builder = new StringBuilder();
                        endTime = totalMin();
                        for (int i = index+1; i < customers.size(); i++) {
                            if(customers.get(i).getTotalMin() <= endTime)
                            {
                                customerQueue.enqueue(customers.get(i));
                                index = i;   
                                size++;
                            }
                        }
                    }
                    else{
                        //System.out.println("55555");
                        increaseClock( 1 );
                        updateSystemHour(1);
                    }
                }
                else{
                        //System.out.println("3333333");
                        Customer out = customerQueue.deque();
                        if(out.getCustometType() == 1)
                            gold++;
                        else if(out.getCustometType() == 2)
                            silver++;
                        else if(out.getCustometType() == 3)
                            bronz++;
                        builder.append( printClock(out.getHour(),out.getMin()) + " müsteri girdi " );  
                        updateSystemHour( out.getTransactionDuration() );                 
                        builder.append(printClock(sysHour,sysMin) + " müsteri cikti" + "-> Onceligi : " + "Customer " + out.getCustometType());
                        printCustomer.add(builder.toString());
                        System.out.println(builder.toString());
                        wr.write(builder.toString() + "\n");
                        increaseClock( out.getTransactionDuration() ); 
                        builder = new StringBuilder();
                }
            }
            else{
                //System.out.println("44444");
                increaseClock( 1 );
                updateSystemHour(1);
            }
        }
        wr.close();
    }
    /**
     * sistem saatini update eder
     * @param min kadar sistem saati artar
     */
    private void updateSystemHour(int min)
    {
        sysMin += min;
        if(sysMin > 59)
        {
            int t = sysMin / 60; 
            sysMin %= 60;
            sysHour += t;
            if(sysHour >= 24)
                sysHour %= 24;
        }
    }
    /**
     * toplam dakikayi verir
     * @return 
     */
    private int totalMin()
    {
        return sysHour*60 + sysMin;
    }  
    /**
     * Alinan saat ve dakikaya gore print islemi yapar
     * @param hour saat
     * @param min dakika
     * @return  String
     */
    private String printClock(int hour, int min)
    {
        StringBuilder shour = new StringBuilder(); 
        StringBuilder smin = new StringBuilder(); 
        
        String h = Integer.toString(hour);
        String m = Integer.toString(min);
        
        if(h.length() == 1){
            shour.append(0);
            shour.append(h);
        }
        else
            shour.append(h);
        if(m.length() == 1){
            smin.append(0);
            smin.append(m);
        }
        else
            smin.append(m);             
        return shour.toString()+":"+smin.toString();
    }
    /**
     * sistemin 24 saat kadar acik olmasini kontrol etmek icin tutulan clock artirilir
     * @param min
     * @throws IOException 
     */
    private void increaseClock(int min) throws IOException
    {
        if(fileName.equals("data1.txt"))
            clock += min;
        else
            for (int i = 0; i < min; i++) {
                ++clock;
                if(clock == twentyHour)
                {
                    System.out.println("-------------------------------------------------------------------");
                    System.out.println("    #20 saat geçtikten sonra#");
                    System.out.println("    Gold Customer : " + gold);
                    System.out.println("    Silver Customer : " + silver);
                    System.out.println("    Bronz Customer : " + bronz);
                    int total = gold + silver + bronz;
                    System.out.println("    Total Customer : " + total);
                    System.out.println("-------------------------------------------------------------------");
                    
                    wr.write("-------------------------------------------------------------------\n");
                    wr.write("    #20 saat geçtikten sonra#\n");
                    wr.write("    Gold Customer : " + Integer.toString(gold) + "\n");
                    wr.write("    Silver Customer : " + Integer.toString(silver) + "\n");
                    wr.write("    Bronz Customer : " + Integer.toString(bronz) + "\n");
                    wr.write("    Total Customer : " + Integer.toString(total) + "\n");
                    wr.write("-------------------------------------------------------------------\n");
                    
                }
            }
    }
}
