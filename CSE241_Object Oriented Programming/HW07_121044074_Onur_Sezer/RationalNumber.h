/* 
 * File:   RationalNumber.h
 * Author: onur
 *
 * Created on December 15, 2015, 10:25 PM
 */

#ifndef RATIONALNUMBER_H
#define	RATIONALNUMBER_H
#include "RealNumber.h"
namespace SEZER{
    class RationalNumber : public RealNumber{
    public:
        RationalNumber(int nom = 0, int denom = 1): RealNumber(static_cast<double>(nom)/denom),nominator(nom), denominator(denom){}
        int getNominator() const {return nominator;}
        int getDenominator()const {return denominator;}
        void setNominator( int nom){ nominator = nom; }
        void setDenominator( int denom){ denominator = denom; } 
        double rational() const;   
        RationalNumber operator +(const RationalNumber& other);
        RationalNumber operator -(const RationalNumber& other);
        friend ostream& operator <<(ostream& out, const RationalNumber& r);
        bool operator <(RationalNumber& other);
    private:
        int nominator;
        int denominator;     
        int gcd(int num1, int num2) const; // en büyük ortak boleni bulur, toplama veya cıkarma isleminde sadelestirme yapmak icin kullanilir
    };
}


#endif	/* RATIONALNUMBER_H */

