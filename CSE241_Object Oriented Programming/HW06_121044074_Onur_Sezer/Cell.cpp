#include "Cell.h"

#include <iostream>

using namespace std;
namespace SEZER{
    void Cell::setPosition(const string x,const char c, const int y)
    {
        corX = x;
        corY = y;
        ch = c;
    }
    void Cell::printCell() const
    { 
        cout << "corX : " << getCorX() << " corY : " << getCorY() << " ch: " << getCh()  << endl; 
    } 
}