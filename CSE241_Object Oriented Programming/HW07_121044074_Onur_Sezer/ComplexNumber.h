/* 
 * File:   ComplexNumber.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:23 PM
 */

#ifndef COMPLEXNUMBER_H
#define	COMPLEXNUMBER_H
#include <iostream>
using std::ostream;
namespace SEZER{
    class ComplexNumber{
    public:
        ComplexNumber(double r = 0.0, double i = 0.0): real(r), imag(i){}
        double getReal() const {return real;}
        double getImag()const {return imag;}
        void setReal( int r){ real = r; }
        void setImag( int i){ imag = i; } 
        double complexNumber() const;
        ComplexNumber operator +(const ComplexNumber& other);
        ComplexNumber operator -(const ComplexNumber& other);
        friend ostream& operator <<(ostream& out, const ComplexNumber& c);
        bool operator <(ComplexNumber& other);
    private:
        double real;
        double imag; 
    };
}

#endif	/* COMPLEXNUMBER_H */

