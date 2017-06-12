/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_121044074_onur_sezer;

import static java.lang.System.exit;
import java.util.ArrayList;
import java.util.Scanner;


/**
 *
 * @author Onur Sezer
 */
public class HW10_121044074_Onur_Sezer {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        ArrayList<Base> arr = new ArrayList<Base>(); 
        String[] strArr;
        String str;
        int i;
        Expression ex = null, ex2;
        
        System.out.println("1- Inputlari kullanicidan alma modu");
        System.out.println("2- Testing modu");
        System.out.println("");
        System.out.println("Yukardaki modlardan birini seciniz");
        i = input.nextInt();
        
        if(i == 1)
        {
            System.out.println("Enter your expression, after each operator or operand press enter, to end the expression press =");
            System.out.println("Enter your expression element");
            str = input.nextLine();
            str = input.nextLine(); 

            while(!str.equals("="))
            {
                if(str.equals("(") || str.equals(")"))
                {
                    Paranthesis parant = new Paranthesis(str);
                    arr.add(parant);
                }
                else if(str.equals("+") || str.equals("-") || str.equals("/") || str.equals("*"))
                {
                    Operator op = new Operator(str);
                    arr.add(op);
                }
                else if(str.matches("^[+-]?\\d+$"))
                {
                    Operand operand = new Operand(str);
                    arr.add(operand);
                }
                else
                {
                    System.out.println("Error Entery");
                    exit(0); // exception koy
                }

                System.out.println("Enter your expression element");
                str = input.nextLine();
            }

            ex = new Expression(arr);
            ex.evaluate();
        }
        else if(i == 2)
        {
            System.out.println("~~~~~~~~~~~ Testing ~~~~~~~~~~");
            while(true)
            {
                System.out.println("");
                System.out.println("    Islemler");
                System.out.println("1-  3 + 7 * ( 1 + 2 ) = ");
                System.out.println("2-  1 * 3 + 2 * ( 1 + 2 ) + ( 2 + ( 6 * 5) ) = ");
                System.out.println("3-  1 + 2 / 4 + 8 * 2 = ");
                System.out.println("4-  ( ( 12 / 2 ) + ( 2 + 3 ) - 1 ) / 2 = ");
                System.out.println("5-  ( + 2 ) + ( 2 * 3 ) = ");
                System.out.println("6-  3 + + 7 = ");
                System.out.println("7-  ( 45 / 5 ( ( 5 - 2 ) = ");
                System.out.println("8-  (100 / 4) - (6 - 5) =");
                System.out.println("9-  Test Equal -> 1. islem == 2. islem ");
                System.out.println("10-  Test Equal -> 1. islem == 8. islem ");
                System.out.println("11-  Exit");
                System.out.println("Islem sec");
                int choice;
                choice = input.nextInt();
                String[] str1 = new String[] {"3","+","7","*","(","1","+","2",")","="};
                String[] str2 = new String[] {"1","*","3","+","2","*","(","1","+","2",")","+","(","2","+","(","6","*","5",")",")","="};
                String[] str3 = new String[] {"1","+","2","/","4","+","8","*","2","="};
                String[] str4 = new String[] {"(","(","12","/","2",")","+","(","2","+","3",")","-","1",")","/","2","=" };
                String[] str5 = new String[] {"(","+","2",")","+","(","2","*","3",")","="};
                String[] str6 = new String[] {"3","+","+","7","="};
                String[] str7 = new String[] {"(","45","/","5","(","(","5","-","2",")","="};
                String[] str8 = new String[] {"(","100","/","4",")","-","(","6","-","5",")", "="};
                StringBuilder strarr = new StringBuilder();

                String[] c_str = null; 
                String[] c_str2 = null;
                if(choice == 1)
                {
                    c_str = str1;
                }
                else if(choice == 2)
                {
                    c_str = str2;
                }
                else if(choice == 3)
                {
                    c_str = str3;
                }
                else if(choice == 4)
                {
                    c_str = str4;
                }
                else if(choice == 5)
                {
                    c_str = str5;
                }
                else if(choice == 6)
                {
                    c_str = str6;
                }
                else if(choice == 7)
                {
                    c_str = str7;
                }
                else if(choice == 8)
                {
                    c_str = str8;
                }
                else if(choice == 9)
                {
                    c_str = str1;
                    c_str2 = str2;
                }
                else if(choice == 10)
                {
                    c_str = str1;
                    c_str2 = str8;
                }
                else if(choice == 11)
                {
                    break;
                }
                else
                    System.out.println("Hatali Giris");
                int st = 1;
                if(choice == 9 || choice == 10)
                    st = 2;
                for(int k = 0; k < st; k++)
                {
                    ArrayList<Base> arr2 = new ArrayList<Base>();
                    if(k == 1)
                        c_str = c_str2;
                    int j=0;
                    while(!(c_str[j].equals("=")))
                    {
                        if(c_str[j].equals("(") || c_str[j].equals(")"))
                        {
                            Paranthesis parant = new Paranthesis(c_str[j]);
                            arr2.add(parant);
                        }
                        else if(c_str[j].equals("+") || c_str[j].equals("-") || c_str[j].equals("/") || c_str[j].equals("*"))
                        {
                            Operator op = new Operator(c_str[j]);
                            arr2.add(op);
                        }
                        else if(c_str[j].matches("^[+-]?\\d+$"))
                        {
                            Operand operand = new Operand(c_str[j]);
                            arr2.add(operand);
                        }
                        else
                        {
                            System.out.println("Error Entery");
                            exit(0); // exception koy
                        }
                        j++;
                    }
                    if(k == 1){
                       System.out.println("");
                        ex2 = new Expression(arr2);
                        ex2.evaluate();
                        if(ex2.equals(ex))
                        {
                            System.out.println("");
                            System.out.println("1. islem : "+ex.resultEvaluate);
                            System.out.println("2. islem : "+ex2.resultEvaluate);
                            System.out.println("Sonuclar esit");
                        }
                        else                        
                        {
                            System.out.println("");
                            System.out.println("1. islem : "+ex.resultEvaluate);
                            System.out.println("2. islem : "+ex2.resultEvaluate);
                            System.out.println("Sonuclar farkli");
                        }
                    }
                    else if (k == 0){
                        System.out.println("");
                        ex = new Expression(arr2);
                        ex.evaluate();
                    }
                    
                }  
            }
        }
        else
            System.out.println("Hatali Giris");
    }
    
}
