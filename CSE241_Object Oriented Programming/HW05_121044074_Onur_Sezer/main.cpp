/* 
 * File:   main.cpp
 * Author: OnurSezer
 *    Num: 121044074
 * Created on 24 Kasım 2015 Salı, 03:26
 */


#include "Reversi.h"

using namespace std;
int main() {
    bool compare;
 
    cout << "~~~~~~~~~~~~~~ TEST CELL ~~~~~~~~~~~~~~" << endl;
    Cell  cell1("a",4,'X');
    Cell  cell2("b",4,'X');
    
    cout << "Test '<' " << endl;
    if( cell1 < cell2)
        cout << "   "  << cell1.getCorY() << " < " << cell2.getCorY() << " is true." << endl;
    else
        cout << "   "  << cell1.getCorY() << " < " << cell2.getCorY() << " is false." << endl;
    
    cout << "\nTest '>' " << endl;   
    if( cell1 > cell2)
        cout << "   "  << cell1.getCorY() << " > " << cell2.getCorY() << " is true." << endl;
    else
        cout << "   " << cell1.getCorY() << " > " << cell2.getCorY() << " is false." << endl;
    
    cout << "\nTest '<=' " << endl;   
    if( cell1 <= cell2)
        cout << "   "  << cell1.getCorY() << " <= " << cell2.getCorY() << " is true." << endl;
    else
        cout << "   " << cell1.getCorY() << " <= " << cell2.getCorY() << " is false." << endl;
    
    cout << "\nTest '>=' " << endl;   
    if( cell1 >= cell2)
        cout << "   "  << cell1.getCorY() << " >= " << cell2.getCorY() << " is true." << endl;
    else
        cout << "   " << cell1.getCorY() << " >= " << cell2.getCorY() << " is false." << endl;
    
    
    cout << "\nTest '==' " << endl;   
    if( cell1 == cell2)
        cout << "   "  << cell1.getCorY() << cell1.getCorX() << " == " << cell2.getCorY() << cell2.getCorX() << " is true." << endl;
    else
        cout << "   " << cell1.getCorY()  << cell1.getCorX() << " == " << cell2.getCorY() << cell2.getCorX() << " is false." << endl;
    
    cout << "\nTest '!=' " << endl;   
    if( cell1 != cell2)
        cout << "   "  << cell1.getCorY()  << cell1.getCorX() << " != " << cell2.getCorY()  << cell2.getCorX() << " is true." << endl;
    else
        cout << "   " << cell1.getCorY()  << cell1.getCorX() << " != " << cell2.getCorY()  << cell2.getCorX() << " is false." << endl;
    
    
    cout << "\nTest '++' prefix" << endl;
    cout << "   Start: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    Cell cell3 = ++cell1;
    cout << "   Returned objecet: ";
    cout << cell3.getCorY() << cell3.getCorX() << "," << cell3.getCh() << endl;
    cout << "   Changed object: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    
    
    cout << "\nTest '++' postfix" << endl;
    cout << "   Start: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    Cell cell4 = cell1++;
    cout << "   Returned objecet: ";
    cout << cell3.getCorY() << cell3.getCorX() << "," << cell3.getCh() << endl;
    cout << "   Changed object: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    
    
    cout << "\nTest '--' prefix" << endl;
    cout << "   Start: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    Cell cell5 = --cell1;
    cout << "   Returned objecet: ";
    cout << cell3.getCorY() << cell3.getCorX() << "," << cell3.getCh() << endl;
    cout << "   Changed object: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    
    
    cout << "\nTest '--' postfix" << endl;
    cout << "   Start: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    Cell cell6 = cell1--;
    cout << "   Returned objecet: ";
    cout << cell3.getCorY() << cell3.getCorX() << "," << cell3.getCh() << endl;
    cout << "   Changed object: ";
    cout << cell1.getCorY() << cell1.getCorX() << "," << cell1.getCh() << endl;
    
    
    cout << "\nTest  '<<' " << endl;
    cout << cell1;
    cout << "\nTest  '>>' "<< endl;
    cout << "You should enter like 5a,X " << endl;  
    cin >> cell2;
    cout << "getCorY() : " << cell2.getCorY() << endl 
         << "getCorX() : " << cell2.getCorX() << endl 
         << "getCh() : " << cell2.getCh() << endl;
    cout << "~~~~~~~~~~~~~~ END OF TEST CELL ~~~~~~~~~~~~~~" << endl; 
    cout << "\n\n~~~~~~~~~~~~~~ TEST Reversi ~~~~~~~~~~~~~~" << endl;
    const char name1[]="game1.txt", name2[]="game2.txt", name3[]="game3.txt", name4[]="game4.txt", name5[]="game5.txt";
    Reversi game1(name1);
    Reversi game2(name2);
    Reversi game3(name3);
    Reversi game4(12);   
    Reversi game5(6,4); 
    Reversi *sect, *sect2;

    int choice,choice2 = 0,choice3, choice4;  
    string y,str;
    int x;
    Cell cell;
    
    game1.readFile();
    game2.readFile();
    game3.readFile();
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
        exit(1);
    }            
    while(1){
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "        Number of Live Cell : " << Reversi::getNumOfAlive() << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "1- Test operator '++' prefix" << endl
             << "2- Test operator '++' postfix" << endl
             << "3- Test operator '--' for prefix" << endl
             << "4- Test operator '--' for postfix" << endl
             << "5- Test operator '+=' " << endl
             << "6- Test operator '[]' " << endl
             << "7- Test operator '()' " << endl
             << "8- CHANGE game" << endl  
             << "9- Exit" << endl; 
        cout << "\nEnter a your choice (1-9)" << endl;
        cin >> choice3;
        if(!(choice3 > 0 && choice3 <= 9))
        {
            cout << "Error choice!!!" << endl;
            exit(1);
        }
        switch(choice3){
            case 1:
                cout << "Test operator '++' prefix" << endl;
                cout << "\nStart object" << endl;
                cout << *sect;
                cout << "\nReturned object" << endl;
                cout << ++(*sect);
                cout << "\nChanged object" << endl;
                cout << *sect;
                break;
            case 2: 
                cout << "Test operator '++' postfix\n" << endl;
                cout << "\nStart object" << endl;
                cout << *sect;
                cout << "\nReturned object" << endl;
                cout << (*sect)++;
                cout << "\nChanged object" << endl;
                cout << *sect;
                break;
            case 3: 
                cout << "Test operator '--' prefix" << endl;
                cout << "\nStart object" << endl;
                cout << *sect;
                cout << "\nReturned object" << endl;
                cout << --(*sect);
                cout << "\nChanged object" << endl;
                cout << *sect;
                break;
            case 4: 
                cout << "Test operator '--' postfix\n" << endl;
                cout << "\nStart object" << endl;
                cout << *sect;
                cout << "\nReturned object" << endl;
                cout << (*sect)--;
                cout << "\nChanged object" << endl;
                cout << *sect;
                break;
            case 5: 
                cout << "Test operator '+='" << endl;
                cout << *sect;
                cout << "Enter a command (like 3a,4ab, etc.)" << endl;
                cin >> x >> y;
                cell.setPosition(y,'.',x);
                *sect += cell;
                cout << *sect;   
                break;    
            case 6: 
                cout << "Test operator '[]' " << endl;
                str = "4c"; 
                cout << "Test for '4c' " << endl;
                cell = (*sect)[str];
                cout << cell.getCorY() << " " << cell.getCorX() << endl;
                str = "12b"; 
                cout << "Test for '12b' " << endl;
                cell = (*sect)[str];
                cout << cell.getCorY() << " " << cell.getCorX() << endl;
                break;
            case 7: 
                cout << "Test operator '()' " << endl;
                str = "2a"; 
                cout << "Test for '2a' " << endl;
                cell = (*sect)(str);
                cout << cell.getCorY() << " " << cell.getCorX() << endl;
                str = "9c"; 
                cout << "Test for '9c' " << endl;
                cell = (*sect)(str);
                cout << cell.getCorY() << " " << cell.getCorX() << endl;
                break;
            case 8: 
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
                    exit(1);
                }
                break;
            case 9:
                game1.writeFile("last_game1.txt");
                game2.writeFile("last_game2.txt");
                game3.writeFile("last_game3.txt");
                game4.writeFile("last_game4.txt");
                game5.writeFile("last_game5.txt");   
                cout << "game1 was written to last_game1.txt" << endl;
                cout << "game2 was written to last_game2.txt" << endl;
                cout << "game3 was written to last_game3.txt" << endl;
                cout << "game4 was written to last_game4.txt" << endl;
                cout << "game5 was written to last_game5.txt" << endl;
                exit(0);
                break;
 
            default :
                cout << "Error entery" << endl;                        
        }     
    }
    return 0;
}



