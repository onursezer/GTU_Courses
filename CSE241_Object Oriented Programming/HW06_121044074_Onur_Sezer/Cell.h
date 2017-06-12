/* 
 * File:   Cell.h
 * Author: OnurSezer
 *
 * Created on 09 Aralık 2015 Çarşamba, 21:11
 */

#ifndef CELL_H
#define	CELL_H
#include <iostream>

using std::string;

namespace SEZER{
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
    private:
        int corY;
        char ch;
        string corX;
    };
}
#endif	/* CELL_H */

