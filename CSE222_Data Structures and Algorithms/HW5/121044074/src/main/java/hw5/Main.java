/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw5;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 *
 * @author Onur Sezer
 */
public class Main {
    
    
    public static void main(String[] args)
    {
        System.out.println("======== PART 1 ========");
        ArrayList<Integer> src = new ArrayList<Integer>();
        ArrayList<Integer> dst = new ArrayList<Integer>();
        ArrayList<Integer> aux = new ArrayList<Integer>();
        
        Hanoi part1 = new Hanoi();
        part1.TowerOfHanoi(4, src, dst, aux);


        System.out.println("======== PART 2 ========");
        System.out.println("--- Test Integer --- ");
        LinkedListRec l1 = new LinkedListRec();
        l1.add(1);
        l1.add(3);
        l1.add(2);
        l1.add(4);
        l1.add(5);
        l1.add(5);
        
        int num = 5;
        System.out.println(l1);
        if(l1.remove(num))
            System.out.println("Removed "+ num);
        else
            System.out.println("No Remove");
        System.out.println(l1);
        
        System.out.println("--- Test Char --- ");
        LinkedListRec l2 = new LinkedListRec();
        l2.add('o');
        l2.add('n');
        l2.add('u');
        l2.add('u');
        l2.add('u');
        l2.add('r');
        
        char c = 'u';
        System.out.println(l2);
        if(l2.remove(c))
            System.out.println("Removed "+ c);
        else
            System.out.println("No Remove");
        System.out.println(l2);


        
        System.out.println("======== PART 3 ========");
        System.out.println("--- Test Integer --- ");
        Part3 p1 = new Part3();
        p1.list1.add(1);
        p1.list1.add(2);
        p1.list1.add(3);
        p1.list1.add(4);
        p1.list1.add(5);
        p1.list1.add(6);
        p1.list2.add(2);
        p1.list2.add(3);
        p1.list2.add(4);
        System.out.print("List1 : ");
        for (Object l : p1.list1)
            System.out.print(l+" ");
        System.out.println("");
        System.out.print("List2 : ");
        for (Object l : p1.list2)
            System.out.print(l+" ");
        System.out.println("");
        
        System.out.println("# Inersect");
        if(!p1.intersectionOfLists().isEmpty()){
            for (int i = 0; i < p1.intersectionOfLists().size(); i++) {
                System.out.println( p1.intersectionOfLists().get(i));
            }
        }
        else
            System.out.println("No intersect");
        
        
        System.out.println("# Union");
        if(!p1.unionOfLists().isEmpty()){
            for (int i = 0; i < p1.unionOfLists().size(); i++) {
                System.out.println( p1.unionOfLists().get(i));
            }
        }
        else
            System.out.println("No union");

        System.out.println("# isSubset");
        if(p1.isSubset())
            System.out.println("TRUE");
        else
            System.out.println("FALSE");
        
        System.out.println("\n--- Test Char --- ");
        
        Part3 p2 = new Part3();
        p2.list1.add('o');
        p2.list1.add('n');
        p2.list1.add('u');
        p2.list1.add('r');
        p2.list1.add('s');
        p2.list1.add('e');
        p2.list2.add('v');
        p2.list2.add('e');
        p2.list2.add('y');
        System.out.print("List1 : ");
        for (Object l : p2.list1)
            System.out.print(l+" ");
        System.out.println("");
        System.out.print("List2 : ");
        for (Object l : p2.list2)
            System.out.print(l+" ");
        System.out.println("");
        
        System.out.println("# Inersect");
        if(!p2.intersectionOfLists().isEmpty()){
            for (int i = 0; i < p2.intersectionOfLists().size(); i++) {
                System.out.println( p2.intersectionOfLists().get(i));
            }
        }
        else
            System.out.println("No intersect");
        
        
        System.out.println("# Union");
        if(!p2.unionOfLists().isEmpty()){
            for (int i = 0; i < p2.unionOfLists().size(); i++) {
                System.out.println( p2.unionOfLists().get(i));
            }
        }
        else
            System.out.println("No union");

        System.out.println("# isSubset");
        if(p2.isSubset())
            System.out.println("TRUE");
        else
            System.out.println("FALSE");
    }
}
