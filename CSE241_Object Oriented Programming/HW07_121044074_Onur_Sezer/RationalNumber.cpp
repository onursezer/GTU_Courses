#include "RationalNumber.h"

namespace SEZER{
     double RationalNumber::rational() const
    {
        return (static_cast<double>(getNominator()) / getDenominator());
    }
    int RationalNumber::gcd(int num1, int num2) const
    {
        if(num1 < num2)
        {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }    
        while(num2 != 0)
        {
            int temp = num2;
            num2 = num1 % num2;
            num1 = temp;
        }
        return num1;
    }
    RationalNumber RationalNumber::operator +(const RationalNumber& other)
    {
        RationalNumber r1,r2;
        r1.nominator = nominator * other.denominator;
        r2.nominator = other.nominator * denominator;
        r1.denominator = denominator * other.denominator;
        
        r1.nominator += r2.nominator;
        int num = gcd(r1.nominator, r1.denominator);  
        r1.nominator /= num;
        r1.denominator /= num;
        return r1;
    }
    RationalNumber RationalNumber::operator -(const RationalNumber& other)
    {
        RationalNumber r1,r2;
        r1.nominator = nominator * other.denominator;
        r2.nominator = other.nominator * denominator;
        r1.denominator = denominator * other.denominator;
        
        r1.nominator -= r2.nominator;
        int num = gcd(r1.nominator, r1.denominator);
        r1.nominator /= num;
        r1.denominator /= num;
        return r1;
    }
    ostream& operator <<(ostream& out, const RationalNumber& r)
    {
        out << r.rational();
        return out;
    }
    bool RationalNumber::operator <(RationalNumber& other)
    {
        return ( rational() < other.rational() );
    }
}
