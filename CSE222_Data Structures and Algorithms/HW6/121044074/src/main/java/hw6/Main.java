/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw6;

import java.io.FileNotFoundException;
import java.io.UnsupportedEncodingException;
import java.util.Iterator;

/**
 *
 * @author Onur Sezer
 */
public class Main {
    
    
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        
        System.out.println("=====================================");
        System.out.println("        PART1");
        
        HuffmanTree Htree = new HuffmanTree();
        
        // Create symbol array
        HuffmanTree.HuffData[] symbols = {
                    new HuffmanTree.HuffData(186, '_'),
                    new HuffmanTree.HuffData(103, 'e'),
                    new HuffmanTree.HuffData(80, 't'),
                    new HuffmanTree.HuffData(64, 'a'),
                    new HuffmanTree.HuffData(63, 'o'),
                    new HuffmanTree.HuffData(57, 'i'),
                    new HuffmanTree.HuffData(57, 'n'),
                    new HuffmanTree.HuffData(51, 's'),
                    new HuffmanTree.HuffData(48, 'r'),
                    new HuffmanTree.HuffData(47, 'h'),
                    new HuffmanTree.HuffData(32, 'd'),
                    new HuffmanTree.HuffData(32, 'l'),
                    new HuffmanTree.HuffData(23, 'u'),
                    new HuffmanTree.HuffData(22, 'c'),
                    new HuffmanTree.HuffData(21, 'f'),
                    new HuffmanTree.HuffData(20, 'm'),
                    new HuffmanTree.HuffData(18, 'w'),
                    new HuffmanTree.HuffData(16, 'y'),
                    new HuffmanTree.HuffData(15, 'g'),
                    new HuffmanTree.HuffData(15, 'p'),
                    new HuffmanTree.HuffData(13, 'b'),
                    new HuffmanTree.HuffData(8, 'v'),
                    new HuffmanTree.HuffData(5, 'k'),
                    new HuffmanTree.HuffData(1, 'j'),
                    new HuffmanTree.HuffData(1, 'q'),
                    new HuffmanTree.HuffData(1, 'x'),
                    new HuffmanTree.HuffData(1, 'z')
        };
        
        // Build hufffman tree 
        Htree.buildTree(symbols);
       

        // Print huffman codes of the symbols
        String EncodedSymbolList = Htree.toString();
        
        // Decode huffman codes to symbıls
        String code = "11000010011111110010100001";
        String decodedCode = Htree.decode(code);
        System.out.println("Code to Message : \n"+code+" : \t"+decodedCode);
        
        System.out.println("String => q__rg");
        try{
        System.out.println("\nEncode : " +  Htree.encode("q__rg", null));
        }catch(IllegalArgumentException e)
        {
            e.printStackTrace();
        }
        
        
        
        System.out.println("=====================================");
        System.out.println("        PART2");
        
        
        BinarySearchTree<Integer> Btree = new BinarySearchTree<Integer>();
        Btree.add(2);
        Btree.add(1);
        Btree.add(12);
        Btree.add(20);
        Btree.add(11);
        Btree.add(0);

        
        Btree.inOrder();
        Iterator it = Btree.iterator();
        System.out.println("next : "+it.next());
        System.out.println("next : "+it.next());
        System.out.println("next : "+it.next());
        System.out.println("next : "+it.next());
        System.out.println("next : "+it.next());
        System.out.println("next : "+it.next());
        System.out.println("hasNext :"+it.hasNext());
        
        System.out.println("=====================================");
        System.out.println("        PART3");   
        System.out.println("**************");
        System.out.println("#ArrayList");
        ArrayListPriorityQueue aList = new ArrayListPriorityQueue();
        
        System.out.println("isEmpty : "+aList.isEmpty());

        aList.enqueue(100);
        aList.enqueue(10);
        aList.enqueue(3);
        aList.enqueue(4);
        System.out.println("size : "+aList.size());
               
        for (int i = 0; i < aList.arr.size(); i++) {
            if(aList.arr.get(i) != null)
                System.out.println(aList.arr.get(i));
        }
        System.out.println("isEmpty : "+aList.isEmpty());
        
        aList.dequeue();
        System.out.println("    dequeue yapildi");
        
        
        for (int i = 0; i < aList.arr.size(); i++) {
            if(aList.arr.get(i) != null)
                System.out.println(aList.arr.get(i));
        }

        System.out.println("**************");
        System.out.println("#LinkedList");
        
        LinkedListPriorityQueue lList = new LinkedListPriorityQueue();
        System.out.println("isEmpty : "+lList.isEmpty());
        lList.enqueue(2);
        lList.enqueue(1);
        lList.enqueue(10);
        lList.enqueue(8);
        lList.enqueue(20);
        System.out.println("size : "+lList.size());
        
        for (int i = 0; i < lList.arr.size(); i++) {
            if(lList.arr.get(i) != null)
                System.out.println(lList.arr.get(i));
        }
        System.out.println("isEmpty : "+lList.isEmpty());
        
        lList.dequeue();
        System.out.println("    dequeue yapildi");
        lList.dequeue();
        System.out.println("    dequeue yapildi");
        
        for (int i = 0; i < lList.arr.size(); i++) {
            if(lList.arr.get(i) != null)
                System.out.println(lList.arr.get(i));
        }
        
        
        System.out.println("**************");
        System.out.println("#UnsortedVector");
        
        UnsortedVectorPriorityQueue uList = new UnsortedVectorPriorityQueue();
        System.out.println("isEmpty : "+uList.isEmpty());
        uList.enqueue(5);
        uList.enqueue(20);
        uList.enqueue(4);
        uList.enqueue(8);
        uList.enqueue(30);
        System.out.println("size : "+uList.size());
        
        for (int i = 0; i < uList.arr.size(); i++) {
            if(uList.arr.get(i) != null)
                System.out.println(uList.arr.get(i));
        }
        System.out.println("isEmpty : "+uList.isEmpty());
        
        uList.dequeue();
        System.out.println("    dequeue yapildi");
        uList.dequeue();
        System.out.println("    dequeue yapildi");
        uList.dequeue();
        System.out.println("    dequeue yapildi");
        
        for (int i = 0; i < uList.arr.size(); i++) {
            if(uList.arr.get(i) != null)
                System.out.println(uList.arr.get(i));
        }
       
    }    
}
