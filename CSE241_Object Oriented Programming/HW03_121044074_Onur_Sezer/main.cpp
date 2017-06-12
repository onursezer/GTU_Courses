// HW03_121044074_Onur_Sezer
// main.c
//
// Created on 22/10/2015 by Onur_Sezer
//
// Description
//
// Triangle classs'i ile ucgenin acilari, cevresi, alani hesaplanir.
// Triangle class 'inin her fonksiyonu test edilir.

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const double PI = 3.14159265;

class Triangle
{
public:
    Triangle(double lA, double lB, double lC);
    Triangle(double lA, double lB);
    Triangle(double lA);
    Triangle();
    void setTriangle(double lA, double lB, double lC);
    double getA() const;
    double getB() const;
    double getC() const;
    void input();
    void output() const;
    double angleA() const;
    double angleB() const;
    double angleC() const;
    bool controlOfRightAngle(double angle) const;
    double perimater() const;
    double area() const;
private:
    double A,B,C;
    void testTriangle();
};
Triangle::Triangle(double lA, double lB, double lC): A(lA), B(lB), C(lC)
{
    testTriangle();
}
Triangle::Triangle(double lA, double lB): A(lA), B(lB), C(1.0)
{
    testTriangle();
}
Triangle::Triangle(double lA): A(lA), B(1.0), C(1.0)
{
    testTriangle();
}
Triangle::Triangle(): A(1.0), B(1.0), C(1.0)
{
// Empty
}
void Triangle::setTriangle(double lA, double lB, double lC)
{
    A = lA;
    B = lB;
    C = lC;

    testTriangle();

}
double Triangle::getA() const
{
    return A;
}
double Triangle::getB() const
{
	return B;

}
double Triangle::getC() const
{
    return C;

}
void Triangle::input()
{
    cout << "Enter a sides of triangle: " << endl;
    cin >> A >> B >> C ;
    setTriangle(A,B,C);
}
void Triangle::output() const
{
    cout <<"Sides : " << A << ", " << B << ", " << C << endl;
    cout << "Angle of A : " << angleA() << endl;
    if( true == controlOfRightAngle( angleA()) )
            cout << "  " << "Angle of A" << " is a right angel." << endl;
    cout << "Angle of B : " << angleB() << endl;
    if( true == controlOfRightAngle(angleB()) )
            cout << "  " << "Angle of B" << " is a right angel." << endl; 
    cout << "Angle of C : " << angleC() << endl;
    if( true == controlOfRightAngle(angleC()) )
            cout << "  " << "Angle of C" << " is a right angel." << endl;
    cout << "Perimater of Triangle : " << perimater() << endl; 
    cout << "Area of Triangle : " << area() << endl;
 
}
double Triangle::angleA() const
{
    return acos((B*B + C*C - A*A) / ( 2.0 * B * C )) * 180.0 / PI;
}
double Triangle::angleB() const
{
    return acos((A*A + C*C - B*B) / ( 2.0 * A * C )) * 180.0 / PI;	
}
double Triangle::angleC() const
{
    return acos((A*A + B*B - C*C) / ( 2.0 * A * B )) * 180.0 / PI ;		
}
bool Triangle::controlOfRightAngle(double angle) const
{
    if(90 == static_cast<int>(angle))
            return true;
    else
            return false;
}
double Triangle::perimater() const
{
    return A + B + C;
}
double Triangle::area() const
{
    double s = perimater() / 2.0; 
    return sqrt ( s * (s - A) * (s - B) * (s - C) ); // ucgenin alanini hesaplar
}
void Triangle::testTriangle()
{
    if ( !( (B < A + C && B > fabs(A-C)) && (A < B + C && A > fabs(B-C)) && (C < B + A && C > fabs(B-A) ) ) ){
            cout << "NO Triangle !" << endl;
            cout << A << " " << B << " " << C << endl;
            exit(0);
    }
}

// call by value & call by value functions
void callByValue(Triangle t)
{
    t.setTriangle(5, 12, 13);
}
void callByReference(Triangle &t)
{
    t.setTriangle(8, 15, 17);
}
int main() {
    Triangle T1(7,24,25), T2(1.5,1.2), T3(1.4), T4;
    cout << "A three parameter constructor is initialized:" << endl;
    T1.output();
    cout << endl;
    cout << "A two parameter constructor is initialized:" << endl;
    T2.output();
    cout << endl;
    cout << "A one parameter constructor is initialized:" << endl;
    T3.output();
    cout << endl;
    cout << "A no parameter constructor is initialized:" << endl;
    T4.output();
    cout << endl;
    cout << "******************** TEST1 *********************\n" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for input()" << endl;
    T4.input();
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl; 
    cout << "	  Testing for output()" << endl;
    T4.output();
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl; 
    cout << "	  Testing for getA()" << endl;
    cout << "Side of A : " << T4.getA() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for getB()" << endl;
    cout << "Side of B : " << T4.getB() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for getC()" << endl;
    cout << "Side of C : " << T4.getC() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for angleA()" << endl;
    cout << "Angle of A : " << T4.angleA() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for angleB()" << endl;
    cout << "Angle of B : " << T4.angleB() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for angleC()" << endl;
    cout << "Angle of C : " << T4.angleC() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for controlOfRightAngle()" << endl;
    if (T4.controlOfRightAngle(T4.angleA()))
        cout << "Angle of A is a right angle." << endl;
    else if (T4.controlOfRightAngle(T4.angleB()))
        cout << "Angle of B is a right angle." << endl;
    else if (T4.controlOfRightAngle(T4.angleC()))
        cout << "Angle of C is a right angle." << endl;
    else
        cout << "NO Right Angel" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for perimater()" << endl;
    cout << "Perimater of Triangle is : " << T4.perimater() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for area()" << endl;
    cout << "Area of Triangle is : " << T4.area() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << endl;
    cout << "******************** TEST2 *********************\n" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for input()" << endl;
    T3.input();
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl; 
    cout << "	  Testing for output()" << endl;
    T3.output();
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl; 
    cout << "	  Testing for getA()" << endl;
    cout << "Side of A : " << T3.getA() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for getB()" << endl;
    cout << "Side of B : " << T3.getB() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for getC()" << endl;
    cout << "Side of C : " << T3.getC() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for angleA()" << endl;
    cout << "Angle of A : " << T3.angleA() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for angleB()" << endl;
    cout << "Angle of B : " << T3.angleB() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for angleC()" << endl;
    cout << "Angle of C : " << T3.angleC() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for controlOfRightAngle()" << endl;
    if (T3.controlOfRightAngle(T3.angleA()))
        cout << "Angle of A is a right angle." << endl;
    else if (T3.controlOfRightAngle(T3.angleB()))
        cout << "Angle of B is a right angle." << endl;
    else if (T3.controlOfRightAngle(T3.angleC()))
        cout << "Angle of C is a right angle." << endl;
    else
        cout << "NO Right Angel" << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for perimater()" << endl;
    cout << "Perimater of Triangle is : " << T3.perimater() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << "	  Testing for area()" << endl;
    cout << "Area of Triangle is : " << T3.area() << endl;
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl;
    cout << endl;
    cout << "------ CALL BY VALUE, CALL BY REFERENCE ------" << endl;
    cout << endl;
    cout << "callByValue fonksiyonu 5-12-13 ucgenini set eder." << endl;
    callByValue(T1);
    T1.output();
    cout << endl;
    cout << "callByReference fonksiyonu 8-15-17 ucgenini set eder." << endl;
    callByReference(T2);
    T2.output();
    return 0;
}

while(1){
        int endOfGame = play(1);
        if(endOfGame == 1)
            break;
        displayBoard();
        controlElements();
        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;

        endOfGame = play();
        if(endOfGame == 1)
            break;
        displayBoard();
        controlElements();
        cout << "\n  YOU : " << circular << "   CPU : " << cross << endl;
    }