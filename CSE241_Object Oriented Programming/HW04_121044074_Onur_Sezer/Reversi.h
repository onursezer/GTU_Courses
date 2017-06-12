#ifndef REVERSI_H
#define	REVERSI_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

class Cell
{
public:
    Cell():corX("a"),ch('.'), corY(0){ /* Empty */}
    Cell(std::string x, int y, char c): corX(x), corY(y), ch(c){ /*Empty*/ }
    void setPosition(const std::string x,const char c,const int y);
    std::string getCorX() const{ return corX; }
    int getCorY() const{ return corY; }
    char getCh() const{return ch; }
    void printCell() const;    
private:
    int corY;
    char ch;
    std::string corX;
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
    void singleStepPlay();
    void playGame(); // play by asking
    static int getNumOfAlive() { return numberOfAlive;}
    bool compareReversiGames(Reversi &other);
    int getCircular() const {return circular;}
private:
    std::vector< std::vector<Cell> > gameCells;
    char nameOfFile[30];
    static int numberOfAlive;
    int sizeRow, sizeCol;
    int circular;
    int play(); // play computer
    int play(int xCor,int yCor); // play user
    void mainPlay();
    void takeCommand(int &xCor,int &yCor);
    int endOfGame(const int userCont,const int computerCont) ; 
    void testReversi() const; 
    int controlElements(int &cross,int &point ); // vectorde hangi elemandan kac tane oldugunu sayar
    int move(const int xCor,const int yCor,const int rows,const int cols,int change,const char char1,const char char2,int &numberOfMoves); // hamle yapmayi saglar
    std::string combineChar(const int j);
};

#endif	/* REVERSI_H */

