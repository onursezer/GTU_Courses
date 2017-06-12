#include "ComplexNumber.h"
namespace SEZER{
    using namespace std;
    ComplexNumber ComplexNumber::operator +(const ComplexNumber& other)
    {
        ComplexNumber c;
        c.real = getReal() + other.getReal();
        c.imag = getImag() + other.getImag();
        return c;
    }
    ComplexNumber ComplexNumber::operator -(const ComplexNumber& other)
    {
        ComplexNumber c;
        c.real = getReal() - other.getReal();
        c.imag = getImag() - other.getImag();
        return c;        
    }
    ostream& operator <<(ostream& out, const ComplexNumber& c)
    {
        if(c.getImag() != 0 && c.getReal() != 0)
            out << c.getReal() << "+" << c.getImag() << "i";
        else if(c.getImag() == 0)
            out << c.getReal();
        else if(c.getReal() == 0)
            out << c.getImag() << "i";
        return out;
    }
    bool ComplexNumber::operator <(ComplexNumber& other)
    {
        if(getReal() < other.getReal())
            return true;
        else if(getReal() == other.getReal())
            return (getImag() < other.getImag());
    }
}
