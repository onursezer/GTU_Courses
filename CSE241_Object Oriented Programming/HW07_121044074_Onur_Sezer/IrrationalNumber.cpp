#include "IrrationalNumber.h"

namespace SEZER{
    IrrationalNumber IrrationalNumber::operator +(const IrrationalNumber& other)
    { 
        IrrationalNumber i;
        i = getReal() + other.getReal();
        return i;
    }
    IrrationalNumber IrrationalNumber::operator -(const IrrationalNumber& other)
    {
        IrrationalNumber i;
        i = getReal() - other.getReal();
        return i;               
    }
    ostream& operator <<(ostream& out, const IrrationalNumber& r)
    {  
        out << r.getReal();
        return out;
    }
    bool IrrationalNumber::operator <(IrrationalNumber& other)
    {
        return getReal() < other.getReal();
    }
}
