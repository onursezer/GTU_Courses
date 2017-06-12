package hw7;

import java.io.IOException;

/**
 *
 * @author Onur Sezer
 */
public class Main {

    
    public static void main(String []args) throws IOException
    {
        Simulation sim = new Simulation("data1.txt");
        Simulation sim2 = new Simulation("data2.txt");
        
        System.out.println("####################  PART1 ####################");
        System.out.println("\n data1.txt");
        sim.CustomerSimulation();
        System.out.println("\n======================================================================\n");
        System.out.println("\n data2.txt");
        sim2.CustomerSimulation();
        
        System.out.println("####################  PART2 ####################");
        Part2 p = new Part2();
        p.readFile();
        p.cont();
    }
    
}
