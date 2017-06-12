/* 
 * File:   NaturalNumber.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:25 PM
 */

#ifndef NATURALNUMBER_H
#define	NATURALNUMBER_H
#include "Integer.h"
namespace SEZER{
class NaturalNumber : public Integer{
    public:
        NaturalNumber();
        NaturalNumber(int i);
        NaturalNumber operator +(const NaturalNumber& other);
        NaturalNumber operator -(const NaturalNumber& other);
        friend ostream& operator <<(ostream& out, const NaturalNumber& i);
        bool operator <(NaturalNumber& other);
    };
}
#endif	/* NATURALNUMBER_H */

