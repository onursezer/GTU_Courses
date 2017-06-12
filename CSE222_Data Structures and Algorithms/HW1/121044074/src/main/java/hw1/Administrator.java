/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hw1;

/**
 *
 * @author Onur Sezer
 */
public interface Administrator {
    
    public boolean addUser(Users user);
    public boolean removeUser(Users user);
    public boolean addCource(Courses course);
    public boolean removeCource(Courses course);
    
}
