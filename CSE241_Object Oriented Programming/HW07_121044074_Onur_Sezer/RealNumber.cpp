#include "RealNumber.h"
namespace SEZER{
    RealNumber RealNumber::operator +(const RealNumber& other)
    {
        RealNumber r;
        r = getReal() + other.getReal();
        return r;
    }
    RealNumber RealNumber::operator -(const RealNumber& other)
    {
        RealNumber r;
        r = getReal() - other.getReal();
        return r;        
    }
    ostream& operator <<(ostream& out, const RealNumber& r)
    {
        out << r.getReal();
        return out;
    }
    bool RealNumber::operator <(RealNumber& other)
    {
        return getReal() < other.getReal();
    }   
}