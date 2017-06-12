/* 
 * HW04_121044074_Onur_Sezer
 * File:   main.cpp
 * Author: OnurSezer
 *
 * Created on 05 Kasım 2015 Perşembe, 22:14
 */
#include "Reversi.h"

using namespace std;
int main() {
    const char name1[]="game1.txt", name2[]="game2.txt", name3[]="game3.txt", name4[]="game4.txt", name5[]="game5.txt";
    Reversi game1(name1);
    Reversi game2(name2);
    Reversi game3(name3);
    Reversi game4(12);   
    Reversi game5(6,4); 
    Reversi *sect, *sect2;
    bool compare;
    int choice,choice2 = 0,choice3, choice4;  
    
    game1.readFile();
    game2.readFile();
    game3.readFile();
    cout << "~~~~~~~~~~~~~  REVERSI GAME  ~~~~~~~~~~~~~" << endl;
    cout << name1 << " added to game1" << endl
         << name2 << " added to game2" << endl
         << name3 << " added to game3" << endl
         << "No read from file game4" << endl
         << "No read from file game5" << endl;
            
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
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "        Number of Live Cell : " << Reversi::getNumOfAlive() << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1- Single step play" << endl
             << "2- playGame" << endl
             << "3- Compare" << endl
             << "4- Change game" << endl
             << "5- Write a file" << endl
             << "6- Exit" << endl; 
        cout << "\nEnter a your choice (1-6)" << endl;
        cin >> choice3;
        if(!(choice3 > 0 && choice3 <= 6))
        {
            cout << "Error choice!!!" << endl;
            exit(0);
        }
        switch(choice3){
            case 1:
                (*sect).singleStepPlay();
                break;
            case 2:
                sect->playGame();               
                break;
            case 3:
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
                break;
            case 4:
                cout << "game1, game2, game3, game4, game5" << endl;
                cout << "\nEnter a number to change game (1-5)" << endl;
                cin >> choice2;
                if(1 == choice2){
                    sect = &game1;
                    cout << "You choised game1" << endl;
                }
                else if(2 == choice2){
                    sect = &game2;
                    cout << "You choised game2" << endl;
                }
                else if(3 == choice2){
                    sect = &game3;
                    cout << "You choised game3" << endl;
                }
                else if(4 == choice2){
                    sect = &game4;
                    cout << "You choised game4" << endl;
                }
                else if(5 == choice2){
                    sect = &game5;
                    cout << "You choised game5" << endl;
                }
                else{
                    cout << "Error choice!!" << endl;
                    exit(0);
                }
                break;
            case 5: 
                if(choice2 == 0){   // oyunu degistirmediyse ilk sectigi oyuna gore file'a kaydeder
                    if(1 == choice){
                        sect->writeFile(name1);
                        cout <<"game1 was writed to " << name1 << endl;
                    }
                    else if(2 == choice){
                        sect->writeFile(name2);
                        cout <<"game2 was writed to " << name2 << endl;
                    }
                    else if(3 == choice){
                        sect->writeFile(name3);
                        cout <<"game3 was writed to " << name3 << endl;
                    }
                    else if(4 == choice){
                        sect->writeFile(name4);
                        cout <<"game4 was writed to " << name4 << endl;
                    }
                    else if(5 == choice){
                        sect->writeFile(name5);
                        cout <<"game5 was writed to " << name5 << endl;
                    }
                    else{
                        cout << "Error choice!!" << endl;
                        exit(0);
                    }
                }
                else{       // oyunu degistirdiyse ona gore file'a yazar
                    if(1 == choice2){
                        sect->writeFile(name1);
                        cout <<"game1 was writed to " << name1 << endl;
                    }
                    else if(2 == choice2){
                        sect->writeFile(name2);
                        cout <<"game2 was writed to " << name2 << endl;
                    }
                    else if(3 == choice2){
                        sect->writeFile(name3);
                        cout <<"game3 was writed to " << name3 << endl;
                    }
                    else if(4 == choice2){
                        sect->writeFile(name4);
                        cout <<"game4 was writed to " << name4 << endl;
                    }
                    else if(5 == choice2){
                        sect->writeFile(name5);
                        cout <<"game5 was writed to " << name5 << endl;
                    }
                    else{
                        cout << "Error choice!!" << endl;
                        exit(0);
                    }
                }
                break;
            case 6:
                exit(0);
                break;
 
            default :
                cout << "Error entery" << endl;                        
        }     
    }
    return 0;
}
