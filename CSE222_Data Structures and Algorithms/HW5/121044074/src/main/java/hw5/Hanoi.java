/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw5;

import static java.lang.Math.pow;
import java.util.ArrayList;

/**
 *
 * @author Onur Sezer
 */
public class Hanoi {
    
    /**
     * Make tower of hanoi as iterative
     * @param disksize : disksize
     * @param src : start tower
     * @param dst : destinition tower 
     * @param aux : temp tower
     * @throws IllegalArgumentException 
     */
    public void TowerOfHanoi(int disksize,ArrayList<Integer> src,ArrayList<Integer> dst,ArrayList<Integer> aux) throws IllegalArgumentException
    {
        if(disksize < 3)
            throw  new IllegalArgumentException("Disksize must be greater than two!");

        for (int i = disksize; i > 0; i--) 
            src.add(i);
        int totalMoves = (int) pow(2, disksize) - 1;
        System.out.println("totalMoves : "+totalMoves);
        for (int i = 1; i <= totalMoves; i++)
        {
            // When diskSize is odd
            if(disksize % 2 != 0)
            {
                if (i % 3 == 1)
                  move(src, dst, "startPeg", "destPeg");
                else if (i % 3 == 2)
                  move(src, aux, "startPeg", "tempPeg");
                else if (i % 3 == 0)
                  move(aux, dst, "tempPeg", "destPeg");
            }
            else // When diskSize is double
            {
                if (i % 3 == 2)
                  move(src, dst, "startPeg", "destPeg");
                else if (i % 3 == 1)
                  move(src, aux, "startPeg", "tempPeg");
                else if (i % 3 == 0)
                  move(aux, dst, "tempPeg", "destPeg");
            }
                
        }
    }
    /**
     * Make move between towers
     * @param src : start tower
     * @param dst : destinition tower 
     * @param s : for print action to screen
     * @param d :for print action to screen
     */
    private void move(ArrayList<Integer> src,ArrayList<Integer> dst, String s, String d)
    {
        int tower1Top = 0,tower2Top = 0, empty1 = -1, empty2 = -1 ;
   

        if(!src.isEmpty()){
            tower1Top = src.get(src.size() - 1);
            src.remove(src.size() - 1);
        }
        else
            empty1 = 0;
        
        if(!dst.isEmpty()){
            tower2Top = dst.get(dst.size() - 1);
            dst.remove(dst.size() - 1);
        }
        else
            empty2 = 0;
        

        // While tower 1 is empty
        if (empty1 == 0)
        {
            src.add(tower2Top);
            System.out.printf("Move the disk %d from %s to %s\n",tower2Top, d, s);
        }
        // While tower 2  is empty
        else if (empty2 == 0)
        {
            dst.add(tower1Top);
            System.out.printf("Move the disk %d from %s to %s\n",tower1Top, s, d);
        }

        // When tower1Top > tower2Top
        else if (tower1Top > tower2Top)
        {
            src.add(tower1Top);
            src.add(tower2Top);
            System.out.printf("Move the disk %d from %s to %s\n",tower2Top, d, s);
        }

        // When tower1Top < tower2Top
        else
        {
            dst.add(tower2Top);
            dst.add(tower1Top);
            System.out.printf("Move the disk %d from %s to %s\n",tower1Top, s, d);
        }
    }
    
}
