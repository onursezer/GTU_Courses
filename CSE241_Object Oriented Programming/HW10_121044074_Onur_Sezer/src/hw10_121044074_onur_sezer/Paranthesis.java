/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw10_121044074_onur_sezer;

public class Paranthesis implements Base {
    private String par;
    /**
     * sol ve sag ve parentezlerini ifade etmek icin kullanildi
     */    
    public Paranthesis(String _par)
    {
        par = _par;
    }
    /**
     * parentezleri string olarak return eder
     * @return String 
     */
    public String getPar()
    {
        return par;
    }
}
