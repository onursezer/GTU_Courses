/* 
 * File:   Reversi.h
 * Author: OnurSezer
 *
 * Created on 09 Aralık 2015 Çarşamba, 10:36
 */

#ifndef REVERSI_H
#define	REVERSI_H
#include "Cell.h"
using std::string;
using std::ostream;

namespace SEZER{
    class Reversi
    {
    public:
        Reversi();
        Reversi(const int row);
        Reversi(const int row,const int col);
        Reversi(const char *name);
        Reversi(const Reversi &other); // copy constructor
        int getCapacity() {return capacity;}
        int getSizeX() const {return sizeRow;}
        int getSizeY() const {return sizeCol;}
        void displayBoard() const;
        void singleStepPlay();
        void playGame(); // play by asking
        static int getNumOfReversiGame() { return livingReversiGame;}
        bool compareReversiGames(Reversi &other);
        int getCircular() const {return circular;}
        friend ostream& operator <<(ostream &out,const Reversi &reversi);
        Reversi operator++();
        Reversi operator++(int);
        Reversi& operator=(const Reversi& other); // assigment
        void testCallByValeu(const Reversi test);
        void testCallByRef(const Reversi &test);
        ~Reversi(); // destructor
    private:
        Cell* gameCells;
        int capacity;        
        char nameOfFile[30];
        static int livingReversiGame;
        int sizeRow, sizeCol;
        int circular;
        void resize(int sizeX, int sizeY); // gameCells i yeniden boyutlandirir
        void mainPlay();
        int play(); // play computer
        int play(int xCor,int yCor); // play user
        void takeCommand(int &xCor,int &yCor);
        int endOfGame(const int userCont,const int computerCont) ; 
        void testReversi() const; 
        int controlElements(int &cross,int &point ); // vectorde hangi elemandan kac tane oldugunu sayar
        int move(const int xCor,const int yCor,const int rows,const int cols,int change,const char char1,const char char2,int &numberOfMoves); // hamle yapmayi saglar
        string combineChar(const int j);
    };
}
#endif	/* REVERSI_H */



