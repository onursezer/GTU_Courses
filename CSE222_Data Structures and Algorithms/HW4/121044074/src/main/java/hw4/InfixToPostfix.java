/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw4;

import java.util.EmptyStackException;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 *
 * @author Onur Sezer
 */
public class InfixToPostfix {

    /**
     * Syntax errorlarinda firlatilir
     */
    public static class SyntaxErrorException extends Exception {

        SyntaxErrorException(String message)
        {
            super(message);
        }
    }

    // Data Fields
    /** The operator stack */
    public Stack < String > operatorStack = new Stack < String > ();

    /** The operators */
    private static final String OPERATORS = "+-*/=";

    /** The precedence of the operators, matches order in OPERATORS. */
    private static final int[] PRECEDENCE = {1, 1, 2, 2, -1};

    /** The postfix string */
    private StringBuilder postfix;


    /**
     * infix i postfix e cevirir
     * @param infix : infix ifadesi
     * @return : cevirdigi postfix ifadesi String olarak return eder
     * @throws SyntaxErrorException
     */
    public String convert(String infix) throws SyntaxErrorException {
        postfix = new StringBuilder();
        StringTokenizer infixTokens = new StringTokenizer(infix);
        try 
        {
            // Process each token in the infix string.
            while (infixTokens.hasMoreTokens()) {
                String nextToken = infixTokens.nextToken();

                char firstChar = nextToken.charAt(0);
                // Is it an operand?
                if (!nextToken.equals("print") && Character.isJavaIdentifierStart(firstChar) || Character.isDigit(firstChar)) {
                    postfix.append(nextToken);
                    postfix.append(' ');
                } 
                else if (isOperator(nextToken)) {
                    processOperator(nextToken);
                }
                else {
                    throw new SyntaxErrorException("Unexpected Character Encountered: "+ firstChar);
                }    
            } 
            while (!operatorStack.empty()) {
                String op = operatorStack.pop();
                postfix.append(op);
                postfix.append(' ');
            }
            // assert: Stack is empty, return result.
            return postfix.toString();
        }
        catch (EmptyStackException ex) { 
            throw new SyntaxErrorException ("Syntax Error: The stack is empty");
        }
    }

    /**
     * postfix e cevirirken operatorleri precedence ni gone yerlestirilir
     * @param op : operator
     */
    public boolean processOperator(String op) {
        if (operatorStack.empty() || op.equals("print"))  {
            operatorStack.push(op);
        }
        else {
            // Peek the operator stack and
            // let topOp be top operator.
            String topOp = operatorStack.peek();
            if (precedence(op.charAt(0)) > precedence(topOp.charAt(0))) 
                operatorStack.push(op);
            else 
            {
                while (!operatorStack.empty() && precedence(op.charAt(0)) <= precedence(topOp.charAt(0))) {
                    operatorStack.pop();
                    postfix.append(topOp);
                    postfix.append(' ');
                    if (!operatorStack.empty()) {
                      // Reset topOp.
                      topOp = operatorStack.peek();
                    }
                }
                operatorStack.push(op);
            }
        }
        return true;
    }

    /**
     * String in operator olup olmadigini kontrol eder
     * @param str : konrol edilecek String
     * @return : boolean
     */
    public boolean isOperator(String str) {
        if(str.equals("print"))
              return true;
        return OPERATORS.indexOf(str.charAt(0)) != -1;
    }

    /**
     * Operatorun precedence ni integer olarak verir
     * @param op : operator
     * @return : integer
     */
    public int precedence(char op) {
      return PRECEDENCE[OPERATORS.indexOf(op)];
    }
    
}
