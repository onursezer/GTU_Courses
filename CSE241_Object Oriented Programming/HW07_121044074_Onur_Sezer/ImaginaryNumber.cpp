#include "ImaginaryNumber.h"
namespace SEZER{
    ImaginaryNumber ImaginaryNumber::operator +(const ImaginaryNumber& other)
    {
        ImaginaryNumber i;
        i = getImag() + other.getImag();
        return i;
    }
    ImaginaryNumber ImaginaryNumber::operator -(const ImaginaryNumber& other)
    {
        ImaginaryNumber i;
        i = getImag() - other.getImag();
        return i;
    }
    ostream& operator <<(ostream& out, const ImaginaryNumber& i)
    {
        if(i.getImag() == 0)
            out << i.getImag();
        else
            out << i.getImag() << "i";
        return out;
    }
    bool ImaginaryNumber::operator <(ImaginaryNumber& other)
    {
        return getImag() < other.getImag();
    }
}
