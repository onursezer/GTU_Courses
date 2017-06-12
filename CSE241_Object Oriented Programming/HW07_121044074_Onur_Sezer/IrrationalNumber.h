/* 
 * File:   IrrationalNumber.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:25 PM
 */

#ifndef IRRATIONALNUMBER_H
#define	IRRATIONALNUMBER_H
#include "RealNumber.h"
namespace SEZER{
class IrrationalNumber : public RealNumber{
    public:
        IrrationalNumber(double r = 0.0): RealNumber(r){}     
        IrrationalNumber operator +(const IrrationalNumber& other);
        IrrationalNumber operator -(const IrrationalNumber& other);
        friend ostream& operator <<(ostream& out, const IrrationalNumber& r);
        bool operator <(IrrationalNumber& other);
    };
}
#endif	/* IRRATIONALNUMBER_H */

