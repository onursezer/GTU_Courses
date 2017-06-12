/* 
 * File:   ImaginaryNumber.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:24 PM
 */

#ifndef IMAGINARYNUMBER_H
#define	IMAGINARYNUMBER_H
#include "ComplexNumber.h"
namespace SEZER{
class ImaginaryNumber : public ComplexNumber{
    public:
        ImaginaryNumber(double i = 0.0): ComplexNumber(0.0,i){}
        ImaginaryNumber operator +(const ImaginaryNumber& other);
        ImaginaryNumber operator -(const ImaginaryNumber& other);
        friend ostream& operator <<(ostream& out, const ImaginaryNumber& i);
        bool operator <(ImaginaryNumber& other);
    };
}

#endif	/* IMAGINARYNUMBER_H */

