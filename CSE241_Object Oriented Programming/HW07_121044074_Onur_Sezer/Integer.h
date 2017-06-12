/* 
 * File:   Integer.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:25 PM
 */

#ifndef INTEGER_H
#define	INTEGER_H
#include "RationalNumber.h"
namespace SEZER{
class Integer : public RationalNumber{
    public:
        Integer(int i = 0): RationalNumber(i,1){}
        Integer operator +(const Integer& other);
        Integer operator -(const Integer& other);
        friend ostream& operator <<(ostream& out, const Integer& i);
        bool operator <(Integer& other);
    };
}
#endif	/* INTEGER_H */

