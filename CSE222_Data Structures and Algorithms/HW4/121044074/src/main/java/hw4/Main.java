/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw4;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;



/**
 *
 * @author Onur Sezer
 */
public class Main {
    
    public static void main(String[] args) throws IOException
    {
        BufferedReader rd = new BufferedReader( new FileReader("input.txt"));
        BufferedWriter wr = new BufferedWriter( new FileWriter("output.asm"));
        
        ArrayList<String> input = new ArrayList<String>();
        ArrayList<String> postfix = new ArrayList<String>();
        InfixToPostfix convert = new InfixToPostfix();
        PostfixEvaluator eva = new PostfixEvaluator();
        
        String str;
        try 
        {
            while((str = rd.readLine()) != null)
            {
                input.add(str);
            }
        } 
        catch (FileNotFoundException ex) 
        {
            System.err.format("File was not found\n");
        }
        
        
        for (int i = 0; i < input.size(); i++)
        {
            try {
                postfix.add(convert.convert(input.get(i)));
            } catch (InfixToPostfix.SyntaxErrorException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        
        for (int i = 0; i < postfix.size(); i++) {
            try {
                eva.eval(postfix.get(i));
            } catch (PostfixEvaluator.SyntaxErrorException ex) {
                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println("Input was converted to Assembly.");
        System.out.println("input.txt >> output.asm ");
        for (int i = 0; i < eva.assembly.size(); i++) {
            wr.write(eva.assembly.get(i));
            wr.write('\n');
        }
        wr.close();
        
    }
    
}
