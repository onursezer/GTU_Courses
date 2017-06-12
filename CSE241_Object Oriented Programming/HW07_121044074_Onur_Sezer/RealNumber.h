/* 
 * File:   RealNumber.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:24 PM
 */

#ifndef REALNUMBER_H
#define	REALNUMBER_H
#include "ComplexNumber.h"
namespace SEZER{
class RealNumber : public ComplexNumber{
    public:
        RealNumber(double r = 0.0): ComplexNumber(r,0.0){}
        RealNumber operator +(const RealNumber& other);
        RealNumber operator -(const RealNumber& other);
        friend ostream& operator <<(ostream& out, const RealNumber& r);
        bool operator <(RealNumber& other);
    };
}

#endif	/* REALNUMBER_H */

