/* 
 * File:   main.cpp
 * Author: OnurSezer
 *
 * Created on 09 Aralık 2015 Çarşamba, 10:35
 */

#include <iostream>
#include <cstdlib>
#include "Reversi.h"
#include "Cell.h"
using namespace SEZER;
using namespace std;

int main() {
    Reversi game1;
    Reversi game2(8);
    Reversi game3(10,12);
    Reversi game4(6,4);   
    Reversi game5(150,100); 
    Reversi *sect, *sect2;
    bool compare;
    int choice,choice2 = 0,choice3, choice4;  
    

    cout << "\n~~~~~~~~~~~~~~~~~~~   REVERSI GAME  ~~~~~~~~~~~~~~~~~~~ " << endl;
    cout << "game1, game2(8), game3(10,12), game4(6,4), game5(150,100)" << endl;
            
    cout << "\nEnter a game number (1-5)" << endl;
    cin >> choice;
    if(1 == choice)
        sect = &game1;
    else if(2 == choice)
        sect = &game2;
    else if(3 == choice)
        sect = &game3;
    else if(4 == choice)
        sect = &game4;
    else if(5 == choice)
        sect = &game5;
    else{
        cout << "Error choice!!" << endl;
        exit(0);
    }
                   
    while(1){
        cout << endl;
        cout << "1- Single step play" << endl
             << "2- playGame" << endl
             << "3- Compare" << endl
             << "4- Test Stream insertion operator" << endl
             << "5- Test operator '++' prefix" << endl
             << "6- Test operator '++' postfix" << endl            
             << "7- Test for assignment operators" << endl
             << "8- Test for copy constructor" << endl
             << "9- Test for call by reference and call by value" << endl
             << "10- CHANGE GAME" << endl
            << "11- Exit" << endl;
        cout << "\nEnter a your choice (1-11)" << endl;
        cin >> choice3;
        if(!(choice3 > 0 && choice3 <= 11))
        {
            cout << "Error choice!!!" << endl;
            exit(0);
        }
        switch(choice3){
            case 1:
                cout << "--------------------------------------" << endl;
                (*sect).singleStepPlay();
                cout << "--------------------------------------" << endl;
                break;
            case 2:
                cout << "--------------------------------------" << endl;
                sect->playGame();  
                cout << "--------------------------------------" << endl;
                break;
            case 3:
                cout << "--------------------------------------" << endl;
                cout << "game1, game2, game3, game4, game5" << endl;
                cout << "Enter a number to compare game" << endl;
                cin >> choice4;
                if(1 == choice4)
                    sect2 = &game1;
                else if(2 == choice4)
                    sect2 = &game2;
                else if(3 == choice4)
                    sect2 = &game3;
                else if(4 == choice4)
                    sect2 = &game4;
                else if(5 == choice4)
                    sect2 = &game5;
                else{
                    cout << "Error choice!!" << endl;
                    exit(0);
                }
                
                compare = sect->compareReversiGames(*sect2);
                if(compare == true)
                    cout << "Your game is better than other game." << endl;
                else
                    cout << "Your game is not better than other game.!" << endl;
                cout << "--------------------------------------" << endl;
                break;
            case 4:
                cout << "--------------------------------------" << endl;
                cout << "game1, game2, game3, game4, game5" << endl;          
                cout << "\nEnter a game number (1-5)" << endl;
                cin >> choice;
                if(1 == choice)
                    cout << game1;
                else if(2 == choice)
                    cout << game2;
                else if(3 == choice)
                    cout << game3;
                else if(4 == choice)
                    cout << game4;
                else if(5 == choice)
                    cout << game5;
                else{
                    cout << "Error choice!!" << endl;
                    exit(0);
                }
                cout << "--------------------------------------" << endl;
                break;
            case 5: 
                cout << "--------------------------------------" << endl;
                cout << "Test operator '++' prefix" << endl;
                cout << "\nStart object" << endl;
                cout << *sect;
                cout << "\nReturned object" << endl;
                cout << ++(*sect);
                cout << "\nChanged object" << endl;
                cout << *sect;
                cout << "--------------------------------------" << endl;
                break;
            case 6:
                cout << "--------------------------------------" << endl;
                cout << "Test operator '++' postfix\n" << endl;
                cout << "\nStart object" << endl;
                cout << *sect;
                cout << "\nReturned object" << endl;
                cout << (*sect)++;
                cout << "\nChanged object" << endl;
                cout << *sect;          
                cout << "--------------------------------------" << endl;
                break;
            case 7:
                cout << "--------------------------------------" << endl;
                cout << "Test for assignment operators" << endl;
                cout << "game1: " << endl;
                cout << game1;
                cout << "\ngame2:" << endl;
                cout << game2;
                cout << "\ngame1' e game2 atandi." << endl;
                game1 = game2;
                cout << game1;   
                cout << "--------------------------------------" << endl;
                break;
            case 8:
            {   
                cout << "--------------------------------------" << endl;
                cout << "Test for copy constructor" << endl;
                cout << "game1: " << endl;
                cout << game1;
                Reversi game6(game1);
                cout << "\ngame6 objesi game1' den olusturuldu." << endl;
                cout << game6;
                cout << "--------------------------------------" << endl;
                break;
            }
            case 9:
            {
                cout << "--------------------------------------" << endl;
                cout << "Test call by value:\n" << endl; 
                cout << "game4, call by value ile parametre olarak gonderildi." << endl;
                sect->testCallByValeu(game4);
                cout << "\nTest call by reference:" << endl; 
                cout << "game4, call by reference ile parametre olarak gonderildi." << endl;
                sect->testCallByRef(game4);
                cout << "--------------------------------------" << endl;
                break;
            }
            case 10:
            {
                cout << "--------------------------------------" << endl;
                cout << "game1, game2, game3, game4, game5" << endl;
                cout << "\nEnter a number to change game (1-5)" << endl;
                cin >> choice2;
                if(1 == choice2){
                    sect = &game1;
                    cout << "You choised game1" << endl;
                }
                else if(2 == choice2){
                    sect = &game2;
                    cout << "You choiced game2" << endl;
                }
                else if(3 == choice2){
                    sect = &game3;
                    cout << "You choiced game3" << endl;
                }
                else if(4 == choice2){
                    sect = &game4;
                    cout << "You choiced game4" << endl;
                }
                else if(5 == choice2){
                    sect = &game5;
                    cout << "You choiced game5" << endl;
                }
                else{
                    cout << "Error choice!!" << endl;
                    exit(0);
                }
                cout << "--------------------------------------" << endl;
                break;
            }
            case 11:{
                exit(0);
                break;
            }
            default :
            {
                cout << "Error entery" << endl;    
            }                    
        }     
    }

    
    
    return 0;
}


