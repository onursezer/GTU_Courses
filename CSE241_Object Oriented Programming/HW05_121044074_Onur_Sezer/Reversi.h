#ifndef REVERSI_H
#define	REVERSI_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>
using std::vector;
using std::string;
using std::istream;
using std::ostream;
class Cell
{
public:
    Cell():corX("a"),ch('.'), corY(0){ /* Empty */}
    Cell(string x, int y, char c): corX(x), corY(y), ch(c){ /*Empty*/ }
    void setPosition(const string x,const char c,const int y);
    string getCorX() const{ return corX; }
    int getCorY() const{ return corY; }
    char getCh() const{return ch; }
    void printCell() const;    
    /*~~~~~~~~~~~~~~~           HW5         ~~~~~~~~~~~~~~~~~~~*/    
    bool operator <(const Cell &other)const;
    bool operator >(const Cell &other)const;
    bool operator <=(const Cell &other)const;
    bool operator >=(const Cell &other)const;
    bool operator ==(const Cell &other)const;
    bool operator !=(const Cell &other)const;
    Cell& operator ++();
    Cell& operator ++(int);
    Cell& operator --();
    Cell& operator --(int);
    friend ostream& operator <<(ostream &out,const Cell &cell); 
    friend istream& operator >>(istream &in, Cell &cell);        
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
private:
    int corY;
    char ch;
    string corX;
    void fixCommand(string str,int &xCor,int &yCor);  
    string combineChar(const int j); 
};
class Reversi
{
public:
    Reversi();
    Reversi(const int row);
    Reversi(const int row,const int col);
    Reversi(const char *name);
    void readFile();
    void writeFile(const char fileName[]) const;
    int getSizeX() const {return sizeRow;}
    int getSizeY() const {return sizeCol;}
    void displayBoard() const;
    static int getNumOfAlive() { return numberOfAlive;}
    int getCircular() const {return circular;}           
    /*~~~~~~~~~~~~~~~           HW5         ~~~~~~~~~~~~~~~~~~~*/
    void saveBoard();
    friend std::ostream& operator <<(std::ostream &out,const Reversi &reversi); 
    Reversi operator++();
    Reversi operator++(int);
    Reversi operator--();
    Reversi operator--(int);
    Reversi& operator+=(const Cell &cell);   
    Cell operator[](string str) const;
    Cell operator()(string str) const;
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
    
private:
    vector< vector<Cell> > gameCells;
    vector<int> saveNumberOfAlive;
    vector< vector < vector<Cell> > > board3D;
    char nameOfFile[30];
    static int numberOfAlive;
    int sizeRow, sizeCol;
    int numStep;
    int circular;
    int play(); // play computer
    int play(int xCor,int yCor); // play user
    void mainPlay();
    int endOfGame(const int userCont,const int computerCont) ; 
    void testReversi() const; 
    int controlElements(int &cross,int &point ); // vectorde hangi elemandan kac tane oldugunu sayar
    int move(const int xCor,const int yCor,const int rows,const int cols,int change,const char char1,const char char2,int &numberOfMoves); // hamle yapmayi saglar
    void fixCommand(string str,int &xCor,int &yCor);  
    string combineChar(const int j);
};

#endif	/* REVERSI_H */


