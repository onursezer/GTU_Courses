#include "NaturalNumber.h"
#include <cstdlib>
using namespace std;
namespace SEZER{
    NaturalNumber::NaturalNumber(): Integer(0)
    {

    }
    NaturalNumber::NaturalNumber(int i): Integer(i)
    {
        if(i < 0)
        {
            cout << "Not Natural Number!" << endl;
            exit(0);
        }
    }
    NaturalNumber NaturalNumber::operator +(const NaturalNumber& other)
    {
        NaturalNumber i;
        i = getNominator() + other.getNominator();
        return i;
    }
    NaturalNumber NaturalNumber::operator -(const NaturalNumber& other)
    {
        NaturalNumber i;
        i = getNominator() - other.getNominator();
        return i;        
    }
    ostream& operator <<(ostream& out, const NaturalNumber& i)
    {
        out << i.getNominator();
    }    
    bool NaturalNumber::operator <(NaturalNumber& other)
    {
        return getNominator() < other.getNominator();
    }    
}
