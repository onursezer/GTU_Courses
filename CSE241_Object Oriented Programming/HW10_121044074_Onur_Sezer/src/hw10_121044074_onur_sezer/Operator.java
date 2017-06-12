/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_121044074_onur_sezer;


public class Operator implements Base {
    private String operator;
    
    /**
    * +, -, *, / operatorlerini ifade etmek icin kulllanildi 
    */   
    public Operator(String _op)
    {
        operator = _op;
    }
    /**
     * operatorleri string olarak return eder
     * @return String
     */
    public String getOperator()
    {
        return operator;
    }
}
