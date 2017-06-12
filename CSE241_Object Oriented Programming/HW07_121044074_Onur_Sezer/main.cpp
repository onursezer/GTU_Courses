/* 
 * File:   main.cpp
 * Author: OnurSezer
 *
 * Created on 13 Aralık 2015 Cumartesi, 11:30
 */

#include <cstdlib>
#include <cmath>
#include "ComplexNumber.h"
#include "ImaginaryNumber.h"
#include "Integer.h"
#include "IrrationalNumber.h"
#include "NaturalNumber.h" 
#include "RationalNumber.h"
#include "RealNumber.h"

using namespace SEZER;
using namespace std;

/*
 * 
 */
int main() {
    ComplexNumber c1(2,3), c2(3,3);
    RealNumber real(12.0), real2(1.0);
    ImaginaryNumber imag(2.0), imag2(-3.0);
    RationalNumber rational(3,4), rational2(7,3);
    IrrationalNumber irra(sqrt(2)),irra2(sqrt(5));
    Integer integer(-1),integer2(7);
    NaturalNumber natural(5),natural2(2);
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Complex Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "ComplexNumber + ComplexNumber" << endl;
    cout << c1 << " + " << c2 << " = " << c1 + c2 << endl;
    cout << "ComplexNumber + RealNumber" << endl;
    cout << c1 << " + " << real << " = " << c1 + real << endl;
    cout << "ComplexNumber + ImaginaryNumber" << endl;
    cout << c1 << " + " << imag << " = " << c1 + imag << endl;
    cout << "ComplexNumber + RationalNumber" << endl;
    cout << c1 << " + " << rational << " = " << c1 + rational << endl;
    cout << "ComplexNumber + IrrationalNumber" << endl;
    cout << c1 << " + " << irra << " = " << c1 + irra << endl; 
    cout << "ComplexNumber + Integer" << endl;
    cout << c1 << " + " << integer << " = " << c1 + integer << endl;
    cout << "ComplexNumber + NaturalNumber" << endl;
    cout << c1 << " + " << natural << " = " << c1 + natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "ComplexNumber - ComplexNumber" << endl;
    cout << c1 << " - " << c2 << " = " << c1 - c2 << endl;
    cout << "ComplexNumber - RealNumber" << endl;
    cout << c1 << " - " << real << " = " << c1 - real << endl;
    cout << "ComplexNumber - ImaginaryNumber" << endl;
    cout << c1 << " - " << imag << " = " << c1 - imag << endl;
    cout << "ComplexNumber - RationalNumber" << endl;
    cout << c1 << " - " << rational << " = " << c1 - rational << endl;
    cout << "ComplexNumber - IrrationalNumber" << endl;
    cout << c1 << " - " << irra << " = " << c1 - irra << endl; 
    cout << "ComplexNumber - Integer" << endl;
    cout << c1 << " - " << integer << " = " << c1 - integer << endl;
    cout << "ComplexNumber - NaturalNumber" << endl;
    cout << c1 << " - " << natural << " = " << c1 - natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl;
    cout << "ComplexNumber < ComplexNumber" << endl;
    cout << c1 << " < " << c2 << " = " ;
    if (c1 < c2) 
        cout << "true" << endl;
    else
       cout << "false" << endl; 
    cout << "ComplexNumber < RealNumber" << endl;
    cout << c1 << " < " << real << " = ";
    if (c1 < real) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "ComplexNumber < ImaginaryNumber" << endl;
    cout << c1 << " < " << imag << " = ";
    if (c1 < imag) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "ComplexNumber < RationalNumber" << endl;
    cout << c1 << " < " << rational << " = ";
    if (c1 < rational) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "ComplexNumber < IrrationalNumber" << endl;
    cout << c1 << " < " << irra << " = "; 
    if (c1 < irra) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "ComplexNumber < Integer" << endl;
    cout << c1 << " < " << integer << " = ";
    if (c1 < integer) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "ComplexNumber < NaturalNumber" << endl;
    cout << c1 << " < " << natural << " = ";
    if (c1 < natural) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Real Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "RealNumber + RealNumber" << endl;
    cout << real << " + " << real2 << " = " << real + real2 << endl;
    cout << "RealNumber + RationalNumber" << endl;
    cout << real << " + " << rational << " = " << real + rational << endl;
    cout << "RealNumber + IrrationalNumber" << endl;
    cout << real << " + " << irra << " = " << real + irra << endl; 
    cout << "RealNumber + Integer" << endl;
    cout << real << " + " << integer << " = " << real + integer << endl;
    cout << "RealNumber + NaturalNumber" << endl;
    cout << real << " + " << natural << " = " << real + natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "RealNumber - RealNumber" << endl;
    cout << real << " - " << real2 << " = " << real - real2 << endl;
    cout << "RealNumber - RationalNumber" << endl;
    cout << real << " - " << rational << " = " << real - rational << endl;
    cout << "RealNumber - IrrationalNumber" << endl;
    cout << real << " - " << irra << " = " << real - irra << endl; 
    cout << "RealNumber - Integer" << endl;
    cout << real << " - " << integer << " = " << real - integer << endl;
    cout << "RealNumber - NaturalNumber" << endl;
    cout << real << " - " << natural << " = " << real - natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl; 
    cout << "RealNumber < RealNumber" << endl;
    cout << real << " < " << real2 << " = ";
    if (real < real2) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "RealNumber < RationalNumber" << endl;
    cout << real << " < " << rational << " = ";
    if (real < rational) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "RealNumber < IrrationalNumber" << endl;
    cout << real << " < " << irra << " = "; 
    if (real < irra) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "RealNumber < Integer" << endl;
    cout << real << " < " << integer << " = ";
    if (real < integer) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "RealNumber < NaturalNumber" << endl;
    cout << real << " < " << natural << " = ";
    if (real < natural) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Imaginary Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "ImaginaryNumber + ImaginaryNumber" << endl;
    cout << imag << " + " << imag2 << " = " << imag + imag2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "ImaginaryNumber - ImaginaryNumber" << endl;
    cout << imag << " - " << imag2 << " = " << imag - imag2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl;
    cout << "ImaginaryNumber < ImaginaryNumber" << endl;
    cout << imag << " < " << imag2 << " = ";
    if (imag < imag2) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Rational Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "RationalNumber + RationalNumber" << endl;
    cout << rational << " + " << rational2 << " = " << rational + rational2 << endl;
    cout << "RationalNumber + Integer" << endl;
    cout << rational << " + " << integer << " = " << rational + integer << endl;
    cout << "RationalNumber + NaturalNumber" << endl;
    cout << rational << " + " << natural << " = " << rational + natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "RationalNumber - RationalNumber" << endl;
    cout << rational << " - " << rational2 << " = " << rational - rational2 << endl;
    cout << "RationalNumber - Integer" << endl;
    cout << rational << " - " << integer << " = " << rational - integer << endl;
    cout << "RationalNumber - NaturalNumber" << endl;
    cout << rational << " - " << natural << " = " << rational - natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl;
    cout << "RationalNumber < RationalNumber" << endl;
    cout << rational << " < " << rational2 << " = ";
    if (rational < rational2) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "RationalNumber < Integer" << endl;
    cout << rational << " < " << integer << " = ";
    if (rational < integer) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "RationalNumber < NaturalNumber" << endl;
    cout << rational << " < " << natural << " = ";
    if (rational < natural) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Irrational Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "IrrationalNumber + IrrationalNumber" << endl;
    cout << irra << " + " << irra2 << " = " << irra + irra2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "IrrationalNumber - IrrationalNumber" << endl;
    cout << irra << " - " << irra2 << " = " << irra - irra2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl;
    cout << "IrrationalNumber < IrrationalNumber" << endl;
    cout << irra << " < " << irra2 << " = ";
    if (irra < irra) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Integer Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "Integer + Integer" << endl;
    cout << integer << " + " << integer2 << " = " << integer + integer2 << endl;
    cout << "Integer + NaturalNumber" << endl;
    cout << integer << " + " << natural << " = " << integer + natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "Integer - Integer" << endl;
    cout << integer << " - " << integer2 << " = " << integer - integer2 << endl;
        cout << "Integer - NaturalNumber" << endl;
    cout << integer << " - " << natural << " = " << integer - natural << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl;
    cout << "Integer < Integer" << endl;
    cout << integer << " < " << integer2 << " = ";
    if (integer < integer2) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "Integer < NaturalNumber" << endl;
    cout << integer << " < " << natural << " = ";
    if (integer < natural) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~ Test Natural Number ~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '+'" << endl;
    cout << "NaturalNumber + NaturalNumber" << endl;
    cout << natural << " + " << natural2 << " = " << natural + natural2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '-'" << endl;
    cout << "NaturalNumber - NaturalNumber" << endl;
    cout << natural << " - " << natural2 << " = " << natural - natural2 << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "       Test Operator '<'" << endl;
    cout << "NaturalNumber < NaturalNumber" << endl;
    cout << natural << " < " << natural2 << " = ";
    if (natural < natural2) 
        cout << "true" << endl;
    else
       cout << "false" << endl;
    return 0;
}

