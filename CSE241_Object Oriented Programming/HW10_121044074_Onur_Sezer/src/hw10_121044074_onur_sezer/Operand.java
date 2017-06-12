/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_121044074_onur_sezer;


public class Operand implements Base {
    private String operand;
    
    /**
    * integer degerleri ifade etmek icin kullanildi
    */
    public Operand(String _operand)
    {
        operand = _operand;
    }
    /**
     * operandi string olarak return eder
     * @return String
     */
    public String getOperand()
    {
        return operand;
    }
}
