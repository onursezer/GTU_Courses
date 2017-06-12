#include "Integer.h"

namespace SEZER{
     Integer Integer::operator +(const Integer& other)
    {
        Integer i;
        i = getNominator() + other.getNominator();
        return i;
    }
    Integer Integer::operator -(const Integer& other)
    {
        Integer i;
        i = getNominator() - other.getNominator();
        return i;        
    }
    ostream& operator <<(ostream& out, const Integer& i)
    {
        out << i.getNominator();
    }    
    bool Integer::operator <(Integer& other)
    {
        return getNominator() < other.getNominator();
    }    
}
