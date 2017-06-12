/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw6;

/**
 *
 * @author Onur Sezer
 */
public interface PriorityQueue<E> {
    /**
     * PriorityQueue ye eleman ekeleme islemi yapar
     * @param item : eklecek eleman
     * @return boolean
     */
    boolean enqueue(E item); 
    /**
     * PriorityQueue den eleman siler
     * @return boolean
     */
    boolean dequeue();
    /**
     * PriorityQueue bos ise true doner
     * @return boolean
     */
    boolean isEmpty();
    /**
     * PriorityQueue nun size ini verir
     * @return 
     */
    int size();         
    
}
