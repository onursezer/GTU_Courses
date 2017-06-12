/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw4;

import java.util.ArrayList;
import java.util.EmptyStackException;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 *
 * @author Onur Sezer
 */
public class PostfixEvaluator {

    // Nested Class
    /** Class to report a syntax error. */
    public static class SyntaxErrorException
        extends Exception {
      /** Construct a SyntaxErrorException with the specified
          message.
          @param message The message
       */
      SyntaxErrorException(String message) {
        super(message);
      }
    }

    // Constant
    /** A list of operators. */
    private static final String OPERATORS = "+-*/=";

    private static final int SIZE = 9;

    // Data Field
    /** The operand stack. */
    public Stack < String > operandStack = new Stack < String > ();;

    public ArrayList <Register> register = new ArrayList <Register>();
    public ArrayList <String> assembly = new  ArrayList <String>();

    /**
     * Registerin size i doldugunda gecici registerlarin indexini verir
     * @return : index i return eder
     */
    public int freeTemporaryRegister()
    {
        for (int i = 0; i < register.size(); i++) {
            if(register.get(i).isTemporary() == true)
            {
                return i;
            }
        }
        return -1;
    }

    /**
     * Stringin sayi olup olmadigini kontrol eder
     * @param str : kontrol edilecek string
     * @return : sayi ise true degilse false
     */
    public boolean isNumeric(String str)
    {
        for (char c : str.toCharArray())
        {
            if (!Character.isDigit(c)) return false;
        }
        return true;
    }

    /**
     * Register i set eder
     * @param index : register arrayindeki registere ulasmak icin alinir
     * @param b    : boolean
     * @param value : registerin icerdigi deger
     */
    public boolean setRegister(int index, boolean b, int value )
    {
        register.get(index).setTemporary(b);
        register.get(index).setRegisterName("$" + "t" + index);
        register.get(index).setId(register.get(index).getRegisterName());
        register.get(index).setValue(value);
        return true;
    }

    // Methods

    /**
     * Parametre olarak aldigi operatore gore postfix ifadeyi assembly koda cevirir
     * @param op : operator
     * @throws SyntaxErrorException
     */
    public void evalOp(String op) throws SyntaxErrorException
    {

        if(op.equals("print"))
        {
            String token1 = operandStack.pop();
            int st = -1;
            for (int i = 0; i < register.size(); i++) {
                if (register.get(i).getId().equals(token1)) {
                    st = i;
                    break;
                }
            }
            if(st != -1) {
                assembly.add("");
                assembly.add("move      $a0, "+register.get(st).getRegisterName());
                assembly.add("li        $v0, 1");
                assembly.add("syscall");
            }
            else
                throw new SyntaxErrorException("Invalid character encountered");
        }
        else
        {
            String token1 = operandStack.pop();
            String token2 = operandStack.pop();


            if(op.equals("+") || op.equals("-"))
            {
                if(!isNumeric(token2) && isNumeric(token1))  //  like a + 3
                {
                    int st = -1;
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token2)) {
                            st = i;
                            break;
                        }
                    }
                    if(st != -1) {
                        int size = register.size();
                        int index;
                        if (size <= SIZE - 1) {
                            index = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index = freeTemporaryRegister()) != -1) {

                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index, true, Integer.parseInt(token1));

                        int sum;
                        if(op.equals("+"))
                            sum = register.get(index).getValue() + register.get(st).getValue();
                        else
                            sum = register.get(index).getValue() - register.get(st).getValue();

                        size = register.size();
                        int index2;
                        if (size <= SIZE - 1) {
                            index2 = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index2 = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index2, true, sum);

                        operandStack.push(register.get(index2).getId());
                        assembly.add("");
                        assembly.add("li        " +  register.get(index).getRegisterName() + ", " + register.get(index).getValue());
                        if(op.equals("+"))
                            assembly.add("add       " + register.get(index2).getRegisterName() + ", " +
                                                     register.get(st).getRegisterName() + ", " +  register.get(index).getRegisterName());
                        else
                            assembly.add("sub       " + register.get(index2).getRegisterName() + ", " +
                                    register.get(st).getRegisterName() + ", " +  register.get(index).getRegisterName());
                    }
                    else
                        throw new SyntaxErrorException("Invalid character encountered");

                }
                else if(!isNumeric(token2) && !isNumeric(token1)) // like a + b
                {
                    int st = -1, st2 = -1;
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token2)) {
                            st = i;
                        }
                        if (register.get(i).getId().equals(token1)) {
                            st2 = i;
                        }
                        if(st != -1 && st2 != -1)
                            break;
                    }
                    if(st != -1 && st2 != -1) {

                        int size = register.size();
                        int index;
                        if (size <= SIZE - 1) {
                            index = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        int sum;
                        if(op.equals("+"))
                            sum = register.get(st).getValue() + register.get(st2).getValue();
                        else
                            sum = register.get(st).getValue() - register.get(st2).getValue();
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index, true, sum);

                        operandStack.push(register.get(index).getId());
                        assembly.add("");
                        if(op.equals("+"))
                            assembly.add("add       " + register.get(index).getRegisterName() + ", " +
                                register.get(st).getRegisterName() + ", " +  register.get(st2).getRegisterName());
                        else
                            assembly.add("sub       " + register.get(index).getRegisterName() + ", " +
                                    register.get(st).getRegisterName() + ", " +  register.get(st2).getRegisterName());
                    }
                    else
                        throw new SyntaxErrorException("Invalid character encountered");
                }
                else if(isNumeric(token2) && !isNumeric(token1)) // like 3 + b
                {
                    int st = -1;
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token1)) {
                            st = i;
                            break;
                        }
                    }
                    if(st != -1) {
                        int size = register.size();
                        int index;
                        if (size <= SIZE - 1) {
                            index = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index, true, Integer.parseInt(token2));

                        int sum;
                        if(op.equals("+"))
                            sum = register.get(index).getValue() + register.get(st).getValue();
                        else
                            sum = register.get(index).getValue() - register.get(st).getValue();


                        size = register.size();
                        int index2;
                        if (size <= SIZE - 1) {
                            index2 = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index2 = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index2, true, sum);

                        operandStack.push(register.get(index2).getId());
                        assembly.add("");
                        assembly.add("li        " +  register.get(index).getRegisterName() + ", " + register.get(index).getValue());
                        if(op.equals("+"))
                            assembly.add("add       " + register.get(index2).getRegisterName() + ", " +
                                register.get(st).getRegisterName() + ", " +  register.get(index).getRegisterName());
                        else
                            assembly.add("sub       " + register.get(index2).getRegisterName() + ", " +
                                    register.get(st).getRegisterName() + ", " +  register.get(index).getRegisterName());
                    }
                    else
                        throw new SyntaxErrorException("Invalid character encountered");
                }
                else if(isNumeric(token2) && isNumeric(token1)) // like 3 + 4
                {

                    int size = register.size();
                    int index;
                    if (size <= SIZE - 1) {
                        index = size;
                    }
                    else // register bittiginde varsa yer alinir
                    {
                        if ((index = freeTemporaryRegister()) != -1) {
                        }
                        else
                            throw new SyntaxErrorException("Exceed register size");
                    }
                    if(register.size() != SIZE)
                        register.add(new Register());
                    setRegister(index, true, Integer.parseInt(token1));

                    int index2;
                    size = register.size();
                    if (size <= SIZE - 1) {
                        index2 = size;
                    }
                    else // register bittiginde varsa yer alinir
                    {
                        if ((index2 = freeTemporaryRegister()) != -1) {
                        }
                        else
                            throw new SyntaxErrorException("Exceed register size");
                    }
                    if(register.size() != SIZE)
                        register.add(new Register());
                    setRegister(index2, true, Integer.parseInt(token2));

                    int sum;
                    if(op.equals("+"))
                        sum = register.get(index).getValue() + register.get(index2).getValue();
                    else
                        sum = register.get(index).getValue() - register.get(index2).getValue();

                    size = register.size();
                    int index3;
                    if (size <= SIZE - 1) {
                        index3 = size;
                    }
                    else // register bittiginde varsa yer alinir
                    {
                        if ((index3 = freeTemporaryRegister()) != -1) {
                        }
                        else
                            throw new SyntaxErrorException("Exceed register size");
                    }
                    if(register.size() != SIZE)
                        register.add(new Register());
                    setRegister(index3, true, sum);

                    operandStack.push(register.get(index3).getId());
                    assembly.add("");
                    assembly.add("li        " +  register.get(index).getRegisterName() + ", " + register.get(index).getValue());
                    assembly.add("li        " +  register.get(index2).getRegisterName() + ", " + register.get(index2).getValue());
                    if(op.equals("+"))
                        assembly.add("add       " + register.get(index3).getRegisterName() + ", " +
                            register.get(index2).getRegisterName() + ", " +  register.get(index).getRegisterName());
                    else
                        assembly.add("sub       " + register.get(index3).getRegisterName() + ", " +
                                register.get(index2).getRegisterName() + ", " +  register.get(index).getRegisterName());

                }
                else
                  throw new SyntaxErrorException("Invalid character encountered");
            }
            else if(op.equals("*") || op.equals("/"))
            {
                if(!isNumeric(token2) && isNumeric(token1))  //  like a * 3
                {
                    int st = -1;
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token2)) {
                            st = i;
                            break;
                        }
                    }
                    if(st != -1) {
                        int size = register.size();
                        int index;
                        if (size <= SIZE - 1) {
                            index = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index = freeTemporaryRegister()) != -1) {

                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index, true, Integer.parseInt(token1));

                        int sum;
                        if(op.equals("*"))
                            sum = register.get(index).getValue() * register.get(st).getValue();
                        else
                            sum = register.get(index).getValue() / register.get(st).getValue();

                        size = register.size();
                        int index2;
                        if (size <= SIZE - 1) {
                            index2 = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index2 = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index2, true, sum);

                        operandStack.push(register.get(index2).getId());
                        assembly.add("");
                        assembly.add("li        " +  register.get(index).getRegisterName() + ", " + register.get(index).getValue());
                        if(op.equals("*")) {
                            assembly.add("mult      " + register.get(st).getRegisterName() + ", " + register.get(index).getRegisterName());
                            assembly.add("mflo      "+register.get(index2).getRegisterName());
                        }
                        else{
                            assembly.add("div       " + register.get(st).getRegisterName() + ", " + register.get(index).getRegisterName());
                            assembly.add("mflo      "+register.get(index2).getRegisterName());
                        }
                    }
                    else
                        throw new SyntaxErrorException("Invalid character encountered");

                }
                else if(!isNumeric(token2) && !isNumeric(token1)) // like a * b
                {
                    int st = -1, st2 = -1;
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token2)) {
                            st = i;
                        }
                        if (register.get(i).getId().equals(token1)) {
                            st2 = i;
                        }
                        if(st != -1 && st2 != -1)
                            break;
                    }
                    if(st != -1 && st2 != -1) {

                        int size = register.size();
                        int index;
                        if (size <= SIZE - 1) {
                            index = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        int sum;
                        if(op.equals("*"))
                            sum = register.get(st).getValue() * register.get(st2).getValue();
                        else
                            sum = register.get(st).getValue() / register.get(st2).getValue();
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index, true, sum);

                        operandStack.push(register.get(index).getId());
                        assembly.add("");
                        if(op.equals("*")) {
                            assembly.add("mult      " + register.get(st).getRegisterName() + ", " + register.get(st2).getRegisterName());
                            assembly.add("mflo      " + register.get(index).getRegisterName());
                        }
                        else {
                            assembly.add("div       " + register.get(st).getRegisterName() + ", " + register.get(st2).getRegisterName());
                            assembly.add("mflo      " + register.get(index).getRegisterName());
                        }
                    }
                    else
                        throw new SyntaxErrorException("Invalid character encountered");
                }
                else if(isNumeric(token2) && !isNumeric(token1)) // like 3 * b
                {
                    int st = -1;
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token1)) {
                            st = i;
                            break;
                        }
                    }
                    if(st != -1) {
                        int size = register.size();
                        int index;
                        if (size <= SIZE - 1) {
                            index = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index, true, Integer.parseInt(token2));

                        int sum;
                        if(op.equals("*"))
                            sum = register.get(index).getValue() * register.get(st).getValue();
                        else
                            sum = register.get(index).getValue() / register.get(st).getValue();


                        size = register.size();
                        int index2;
                        if (size <= SIZE - 1) {
                            index2 = size;
                        }
                        else // register bittiginde varsa yer alinir
                        {
                            if ((index2 = freeTemporaryRegister()) != -1) {
                            }
                            else
                                throw new SyntaxErrorException("Exceed register size");
                        }
                        if(register.size() != SIZE)
                            register.add(new Register());
                        setRegister(index2, true, sum);

                        operandStack.push(register.get(index2).getId());
                        assembly.add("");
                        assembly.add("li        " +  register.get(index).getRegisterName() + ", " + register.get(index).getValue());
                        if(op.equals("*")) {
                            assembly.add("mult      " + register.get(st).getRegisterName() + ", " + register.get(index).getRegisterName());
                            assembly.add("mflo      " + register.get(index2).getRegisterName());
                        }
                        else {
                            assembly.add("div       " + register.get(st).getRegisterName() + ", " + register.get(index).getRegisterName());
                            assembly.add("mflo      " + register.get(index2).getRegisterName());
                        }
                    }
                    else
                        throw new SyntaxErrorException("Invalid character encountered");
                }
                else if(isNumeric(token2) && isNumeric(token1)) // like 3 * 4
                {

                    int size = register.size();
                    int index;
                    if (size <= SIZE - 1) {
                        index = size;
                    }
                    else // register bittiginde varsa yer alinir
                    {
                        if ((index = freeTemporaryRegister()) != -1) {
                        }
                        else
                            throw new SyntaxErrorException("Exceed register size");
                    }
                    if(register.size() != SIZE)
                        register.add(new Register());
                    setRegister(index, true, Integer.parseInt(token1));

                    int index2;
                    size = register.size();
                    if (size <= SIZE - 1) {
                        index2 = size;
                    }
                    else // register bittiginde varsa yer alinir
                    {
                        if ((index2 = freeTemporaryRegister()) != -1) {
                        }
                        else
                            throw new SyntaxErrorException("Exceed register size");
                    }
                    if(register.size() != SIZE)
                        register.add(new Register());
                    setRegister(index2, true, Integer.parseInt(token2));

                    int sum;
                    if(op.equals("*"))
                        sum = register.get(index).getValue() * register.get(index2).getValue();
                    else
                        sum = register.get(index).getValue() / register.get(index2).getValue();

                    size = register.size();
                    int index3;
                    if (size <= SIZE - 1) {
                        index3 = size;
                    }
                    else // register bittiginde varsa yer alinir
                    {
                        if ((index3 = freeTemporaryRegister()) != -1) {
                        }
                        else
                            throw new SyntaxErrorException("Exceed register size");
                    }
                    if(register.size() != SIZE)
                        register.add(new Register());
                    setRegister(index3, true, sum);

                    operandStack.push(register.get(index3).getId());
                    assembly.add("");
                    assembly.add("li        " +  register.get(index).getRegisterName() + ", " + register.get(index).getValue());
                    assembly.add("li        " +  register.get(index2).getRegisterName() + ", " + register.get(index2).getValue());
                    if(op.equals("*")) {
                        assembly.add("mult      " + register.get(index2).getRegisterName() + ", " + register.get(index).getRegisterName());
                        assembly.add("mflo      " + register.get(index3).getRegisterName());
                    }
                    else {
                        assembly.add("div       " + register.get(index2).getRegisterName() + ", " + register.get(index).getRegisterName());
                        assembly.add("mflo      " + register.get(index3).getRegisterName());
                    }

                }
                else
                    throw new SyntaxErrorException("Invalid character encountered");
            }
            else if(op.equals("="))
            {
                int st = -1;
                if(!isNumeric(token2)) // atamanin digite yapilmasi durumunda hata verir
                {
                    for (int i = 0; i < register.size(); i++) {
                        if (register.get(i).getId().equals(token2)) {
                            st = i;
                            break;
                        }
                    }
                    if(st == -1) // daha once girilmemis degisken
                    {
                        if(register.isEmpty()) // register listesi bos oldugunda
                        {
                            register.add(new Register());
                            register.get(0).setId(token2);
                            register.get(0).setRegisterName("$"+"t"+0);
                            if(isNumeric(token1)){
                                register.get(0).setValue(Integer.parseInt(token1.toString()));
                                assembly.add("li        " + register.get(0).getRegisterName() + ", " +  register.get(0).getValue());
                            }
                            else
                               throw new SyntaxErrorException("Invalid character encountered");  // atanacak character digit degilse hata verir
                        }
                        else
                        {
                            int index;
                            int size = register.size();
                            st = -1;

                            if(register.size() == SIZE) {
                                if ((index = freeTemporaryRegister()) != -1) {
                                } else
                                    throw new SyntaxErrorException("Exceed register size");
                            }
                            else {
                                size = register.size();
                                index = size;
                            }

                            if(isNumeric(token1)){
                                if(register.size() != SIZE)
                                    register.add(new Register());
                                register.get(index).setTemporary(false);
                                register.get(index).setId(token2);
                                register.get(index).setRegisterName("$"+"t"+index);
                                register.get(index).setValue(Integer.parseInt(token1.toString()));

                                assembly.add("li        " + register.get(index).getRegisterName() + ", " +  register.get(index).getValue());
                            }
                            else if(!isNumeric(token1))
                            {
                                for (int i = 0; i < size; i++){
                                    if(register.get(i).getId().equals(token1))
                                        st = i;
                                }
                                if(st != -1)
                                {
                                    if(register.size() != SIZE)
                                        register.add(new Register());
                                    register.get(index).setTemporary(false);
                                    register.get(index).setId(token2);
                                    register.get(index).setRegisterName("$"+"t"+index);
                                    register.get(index).setValue(register.get(st).getValue());

                                    assembly.add("move      " + register.get(index).getRegisterName() + ", " +  register.get(st).getRegisterName());
                                }
                                else
                                    throw new SyntaxErrorException("Invalid character encountered");
                            }
                            else
                               throw new SyntaxErrorException("Invalid character encountered");  // atanacak character digit degilse hata verir

                        }
                    }   // daha once girilmiş register
                    else
                    {
                        int st2 = -1;
                        if(!isNumeric(token1))
                        {
                            for (int i = 0; i < register.size(); i++) {
                                if(register.get(i).getId().equals(token1))
                                    st2 = i;
                            }
                            if(st2 != -1)
                            {
                                register.get(st).setValue(register.get(st2).getValue());
                                assembly.add("move      " + register.get(st).getRegisterName() + ", " +  register.get(st2).getRegisterName());
                            }
                            else
                               throw new SyntaxErrorException("Invalid character encountered");
                        }
                    }
                }
                else
                   throw new SyntaxErrorException("Invalid character encountered");

            }
        }
    }

    /**
     * Aldigi String in Operator olup olmadiginin konrolu yapilir
     * @param str : String
     * @return : boolean
     */
    public boolean isOperator(String str)
    {
        if(str.equals("print"))
            return true;
        return OPERATORS.indexOf(str.charAt(0)) != -1;
    }

    /**
     * Postfix olarak aldigi stringi operand ve operatorlerine ayirir
     * @param expression : postfix ifade
     * @throws SyntaxErrorException
     */
    public boolean eval(String expression) throws SyntaxErrorException
    {

        // Process each token.
        StringTokenizer tokens = new StringTokenizer(expression);
        try
        {
            while (tokens.hasMoreTokens()) {
                String nextToken = tokens.nextToken();
                // digit ya da identifier ise  operandStack e token push edilir
                if (!nextToken.equals("print") &&
                    (Character.isDigit(nextToken.charAt(0)) || Character.isJavaIdentifierStart(nextToken.charAt(0))))
                {
                    operandStack.push(nextToken);
                }
                // operator ise evalOp methodu cagrilir
                else if (isOperator(nextToken)) {
                    evalOp(nextToken);
                }
                else {
                    throw new SyntaxErrorException("Invalid character encountered");
                }
            }
        }
        catch (EmptyStackException ex)
        {
          throw new SyntaxErrorException("Syntax Error: The stack is empty");
        }
        return true;
    }
}
