/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw6;

import java.util.Comparator;
import java.util.Vector;

/**
 *
 * @author Onur Sezer
 */
public class UnsortedVectorPriorityQueue<E> implements PriorityQueue<E>{
    //Data Fields
    public Vector<E> arr = new  Vector<E>();
    private int size = 0;

    private final Comparator<? super E> comparator;

    private int modCount = 0; 
    
    public UnsortedVectorPriorityQueue() {
        this(null);
    }

    public UnsortedVectorPriorityQueue(Comparator<? super E> comparator) {
        this.comparator = comparator;
    }
    
    /////////////////////////////////////////
    /**
     * Inserts item x at position k, maintaining heap invariant by
     * demoting x down the tree repeatedly until it is less than or
     * equal to its children or is a leaf.
     *
     * @param k the position to fill
     * @param x the item to insert
     */
    private void siftUp(int k, E x) {
        if (comparator != null)
            siftUpUsingComparator(k, x);
        else
            siftUpComparable(k, x);
    }

    private void siftUpComparable(int k, E x) {
        Comparable<? super E> key = (Comparable<? super E>) x;
        while (k > 0) {
            int parent = (k - 1) >>> 1;
            Object e = arr.get(parent);
            
            if (key.compareTo((E) e) >= 0)
                break;
            arr.set(k, (E) e);
            k = parent;
        }
        arr.set(k, (E) key);
    }
    private void siftUpUsingComparator(int k, E x) {
        while (k > 0) {
            int parent = (k - 1) >>> 1;
            Object e = arr.get(parent);
            if (comparator.compare(x, (E) e) >= 0)
                break;
            arr.set(k, (E) e);
            k = parent;
        }
        arr.set(k, (E) x);
    }
    /**
     * Inserts the specified element into this priority queue.
     *
     * @return {@code true} (as specified by {@link Queue#offer})
     * @throws ClassCastException if the specified element cannot be
     *         compared with elements currently in this priority queue
     *         according to the priority queue's ordering
     * @throws NullPointerException if the specified element is null
     */
    private boolean offer(E e) {
        if (e == null)
            throw new NullPointerException();
        modCount++;
        int i = size;
        if (i >= arr.size())
            arr.add(null);
        size = i + 1;
        if (i == 0)
            arr.set(i, e);
        else
            siftUp(i, e);
        return true;
    }
    @Override
    public boolean enqueue(Object item) {
        return offer((E) item);
    }
    ///////////////////////////////////////////////////////////////////
    /**
     * Inserts item x at position k, maintaining heap invariant by
     * demoting x down the tree repeatedly until it is less than or
     * equal to its children or is a leaf.
     *
     * @param k the position to fill
     * @param x the item to insert
     */ 
    private void siftDown(int k, E x) {
        if (comparator != null)
            siftDownUsingComparator(k, x);
        else
            siftDownComparable(k, x);
    }
    @SuppressWarnings("unchecked")
    private void siftDownComparable(int k, E x) {
        Comparable<? super E> key = (Comparable<? super E>)x;
        int half = size >>> 1;        // loop while a non-leaf
        while (k < half) {
            int child = (k << 1) + 1; // assume left child is least
            Object c = arr.get(child);
            int right = child + 1;
            if (right < size &&
                ((Comparable<? super E>) c).compareTo((E) arr.get(child)) > 0)
                c = arr.get(child = right);
            if (key.compareTo((E) c) <= 0)
                break;
            arr.set(k, (E) c);
            k = child;
        }
        arr.set(k, (E) key);
    }

    @SuppressWarnings("unchecked")
    private void siftDownUsingComparator(int k, E x) {
        int half = size >>> 1;
        while (k < half) {
            int child = (k << 1) + 1;
            Object c = arr.get(child);
            int right = child + 1;
            if (right < size &&
                comparator.compare((E) c, (E) arr.get(right)) > 0)
                c = arr.get(child = right);
            if (comparator.compare(x, (E) c) <= 0)
                break;
            arr.set(k, (E) c);
            k = child;
        }
        arr.set(k, (E) x);
    }
     
    /**
     * Arrayin ilk elemanini siler
     * @return 
     */  
    private E poll() {
        if (size == 0)
            return null;
        int s = --size;
        modCount++;
        E result = (E) arr.get(0);
        E x = (E) arr.get(s);
        arr.set(s, null);
        if (s != 0)
            siftDown(0, x);
        return result;
    }
    /**
     * PriorityQueue dan eleman siler
     * @return 
     */   
    @Override
    public boolean dequeue() {
        if(poll() == null)
            return false;
        return true;
    }
    ///////////////////////////////////////////////////////////////////
    @Override
    public boolean isEmpty() {
        if(arr.size() == 0)
            return true;
        return false;
    }

    @Override
    public int size() {
        return arr.size();
    }
    
}
