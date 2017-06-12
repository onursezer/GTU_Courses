/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw5;

import java.util.*;

/**
 *
 * @author Onur Sezer
 */
public class Part3<E>{
    

    //Data Fields
    public List<E> list1 = new ArrayList<E>();
    public List<E> list2 = new ArrayList<E>();


    /**
     * returns intersection set as a list of list1 and list 2 
     * @return list
     */
    public List<E> intersectionOfLists()
    {
        return intersection(list1, list2);
    }
    /**
     * returns union set as a list of list1 and list 2
     * @return list
     */
    public List unionOfLists()
    {
        List<E> list3 = new ArrayList<E>();
        return union(list1, list2, list3);
    }
    /**
     * return true if list2 is subset of list1
     * @return boolean
     */
    public boolean isSubset()
    {
        if(list1.size() < list2.size())
            return subset(list1, list2);
        else
            return subset(list2, list1);
    }
    /**
     * Wrapper fucntion of intersectionOfLists()
     * Find intersection between two list
     * @param list1  searched list
     * @param list2 searched list
     * @return intersect list
     */
    private List<E> intersection(List<E> list1, List<E> list2){
        if(list1.isEmpty())
            return list1;
        else {
            List<E> result = new ArrayList<E>();
            E head = list1.get(0);
            if (list2.contains(head)) 
                result.add(head);
            ArrayList<E> tail = new ArrayList<>();
            tail.addAll(list1.subList(1, list1.size()));
            result.addAll(intersection(tail, list2));
            return result;
        }
    }
    /**
     * Wrapper fucntion of unionOfLists()
     * Find union between two list
     * @param list1 searched list
     * @param list2 searched list
     * @param list3 union list
     * @return union list
     */
    private List<E> union(List<E> list1, List<E> list2, List<E> list3)
    {
        if(list1.isEmpty() && list2.isEmpty())
        {            
            return list3;
        }
        else
        {
            if(!list1.isEmpty() && !list2.isEmpty())
            {
                if(!list3.contains(list1.get(0)))
                    list3.add(list1.get(0));
                if(!list3.contains(list2.get(0)))
                    list3.add(list2.get(0));
                List<E> tail1 = new ArrayList<>();
                List<E> tail2 = new ArrayList<>();
                tail1.addAll(list1.subList(1, list1.size()));
                tail2.addAll(list2.subList(1, list2.size()));
                union(tail1, tail2, list3);
                return list3;
            }
            else if(!list1.isEmpty())
            {
                if(!list3.contains(list1.get(0)))
                    list3.add(list1.get(0));
                List<E> tail1 = new ArrayList<>();
                List<E> tail2 = new ArrayList<>();
                tail1.addAll(list1.subList(1, list1.size()));
                union(tail1, tail2, list3);
                return list3; 
            }
            else 
            {
                if(!list3.contains(list2.get(0)))
                    list3.add(list2.get(0));
                List<E> tail1 = new ArrayList<>();
                List<E> tail2 = new ArrayList<>();
                tail2.addAll(list2.subList(1, list2.size()));
                union(tail1, tail2, list3);
                return list3; 
            }
        }
    }
    /**
     * Wrapper fucntion of isSubset()
     * Find subset between two list
     * @param list1 searched list
     * @param list2 searched list
     * @return boolean
     */
    private boolean subset(List<E> list1, List<E> list2)
    {
        if(list1.isEmpty())
            return true;
        else
        {
            E head = list1.get(0);
            if (list2.contains(head))
            {
                List<E> tail = new ArrayList<>();
                tail.addAll(list1.subList(1, list1.size()));
                return true && subset(tail, list2);
            }
            else
                return false;
        }
    }

}
