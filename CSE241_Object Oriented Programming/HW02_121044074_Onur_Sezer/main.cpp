// HW02_121044074_Onur_Sezer
// main.c
//
// Created on 23/10/2015 by Onur_Sezer
//
// Description
//
// Farklı tiplerdeki arraylerde void * kullanarak mode bulur.

#include <iostream>
#include <cstring>

using namespace std;

class DayOfYear
{
public:
	int year;
	int month;
	int day;
};

class Person
{
public:
	char name[20];
	char surname[20];
	int age;
};

bool equalInt(const void *el1, const void *el2);
bool equalDouble(const void *el1, const void *el2);
bool equalChar(const void *el1, const void *el2);
bool equalDayOfYear(const void *el1, const void *el2);
bool equalPerson(const void *el1, const void *el2);
int return_mode (const void * base, size_t num, size_t size, bool (* equals) (const void *, const void *));


int main() {

    cout << endl;
    cout << "***********     TEST1 FOR INTEGER    ******************\n";	
    int intArr[]={1, 3, 6, 1, 8, 9, 3, 3, 3, 3};
    int sizeOfArr = sizeof(intArr) / sizeof(int);
    int resault = return_mode(intArr, sizeOfArr, sizeof(int), equalInt);
    cout << "Array : ";
    for (int i = 0; i < sizeOfArr; ++i){
            cout << intArr[i];
            if(i != sizeOfArr -1)
                    cout << ", ";
    }
    cout << endl;
    cout << "Mode is " << intArr[resault] << endl;
    cout << "Index of mode : " << resault << endl;

    cout << endl;
    cout << "*************     TEST2 FOR DOUBLE     ******************\n";
    double doubleArr[]={0.1, 0.9, 1.1, 1.5, 5.8, 4.1, 1.1, 1.9, 1, 2, 1.1};
    sizeOfArr = sizeof(doubleArr) / sizeof(double);
    resault = return_mode(doubleArr, sizeOfArr, sizeof(double), equalDouble);
    cout << "Array : ";
    for (int i = 0; i < sizeOfArr; ++i){
            cout << doubleArr[i];
            if(i != sizeOfArr -1)
                    cout << ", ";
    }	
    cout << endl;
    cout << "Mode is " << doubleArr[resault] << endl;
    cout << "Index of mode : " << resault << endl;

    cout << endl;
    cout << "*************     TEST3 FOR CHAR     ******************\n";
    char charArr[]={'g','e','b','z','e','t','e','k','n','i','k','u','n','i','v','e','r','s','i','t','e','s','i'};
    sizeOfArr = sizeof(charArr) / sizeof(char);
    resault = return_mode(charArr, sizeOfArr, sizeof(char), equalChar);
    cout << "Array : ";
    for (int i = 0; i < sizeOfArr; ++i){
            cout << charArr[i];
            if(i != sizeOfArr -1)
                    cout << ", ";	
    }
    cout << endl;
    cout << "Mode is " << charArr[resault] << endl;
    cout << "Index of mode : " << resault << endl;

    cout << endl;
    cout << "*************     TEST4 FOR DayOfYear   ******************\n";
    DayOfYear date[]={{1994,3,21},{1453,5,29},{1414,10,9},{1453,5,30},{1400,6,20},{2008,2,22},{1414,10,9}};
    sizeOfArr = sizeof(date) / sizeof(DayOfYear);
    resault = return_mode(date, sizeOfArr, sizeof(DayOfYear), equalDayOfYear);
    cout << "Array : ";
    for (int i = 0; i < sizeOfArr; ++i){
            cout << "{" << date[i].year << "," << date[i].month << "," << date[i].day << "}"; 
            if(i != sizeOfArr -1)
                    cout << ", ";
    }		
    cout << endl;
    cout << "Mode is " << "{" << date[resault].year << "," << date[resault].month << "," << date[resault].day << "}" << endl;
    cout << "Index of mode : " << resault << endl;


    cout << endl;
    cout << "*************     TEST5 FOR Person   ******************\n";
    Person man[]={{"birinci","suleyman",71},{"ikinci","mehmet",49},
                                    {"sultan","selim",49},{"sultan","abdulhamit",75},{"halid","binvelid",52},{"sultan","abdulhamit",75}};
    sizeOfArr = sizeof(man) / sizeof(Person);
    resault = return_mode(man, sizeOfArr, sizeof(Person), equalPerson);
    cout << "Array : ";
    for (int i = 0; i < sizeOfArr; ++i){
            cout << "{" << "'" << man[i].name << "'" << "," << "'" << man[i].surname << "'" << ","
                     << man[i].age << "}";
            if(i != sizeOfArr -1)
                    cout << ", ";
    }	
    cout << endl;
    cout << "Mode is " << "{" << "'" << man[resault].name << "'" << "," << "'" << man[resault].surname << "'" << ","
                     << man[resault].age << "}" << endl;
    cout << "Index of mode : " << resault << endl;
    cout << endl;
    return 0;
}
bool equalInt(const void *el1, const void *el2) 
{
int *p1 = (int*) el1;
int *p2 = (int*) el2;

if(*p1 == *p2)
    return true;
else
    return false;
}
bool equalDouble(const void *el1, const void *el2)
{
    if( (*(double *)el1) == (*(double *)el2))
        return true;
    else
        return false;
}	
bool equalChar(const void *el1, const void *el2)
{
    if( *(char *)el1 == *(char *)el2)
        return true;
    else
        return false;
}
bool equalDayOfYear(const void *el1, const void *el2)
{
    if( ((*(DayOfYear *)el1).day == (*(DayOfYear *)el2).day) && ( (*(DayOfYear *)el1).month == (*(DayOfYear *)el2).month) 
                    && ( (*(DayOfYear *)el1).year == (*(DayOfYear *)el2).year) )
        return true;
    else
        return false;
}
bool equalPerson(const void *el1, const void *el2)
{
    if( ( (*(Person *)el1).age == (*(Person *)el2).age ) && !( strcmp( (*(Person *)el1).name,(*(Person *)el2).name ) )
            && !( strcmp( (*(Person *)el1).surname,(*(Person *)el2).surname ) ) )
        return true;
    else
        return false;
}
int return_mode (const void * base, size_t num, size_t size, bool (* equals) (const void *, const void *))
{ 
    int count, maxCount = 0;
    int res, i, j, find;
    void *b;
    cout << "num : " << num << endl;

    unsigned char* arr = (unsigned char*) base;
    unsigned char* arr2 = (unsigned char*) base;
    unsigned char* arr3;
    unsigned char* arrEnd = (unsigned char*) base + (num * size);


    for (; arr < arrEnd; arr += size)
    {
        count = 1;
        for ( arr2 = arr + size ; arr2 < arrEnd; arr2 += size)   // en fazla tekrar edilen sayinin miktari bulunur
            if (equals(arr, arr2)) {
                count++;
            }
        if (count > maxCount){
            maxCount = count;
        }
    }
    i = 0;
    arr = (unsigned char*) base; // base tekrar arr' e atilir
    arr2 = (unsigned char*) base;
    for (; arr < arrEnd; arr += size) // tekrari en fazla olan sayiyi ve ilk gectigi indexi bulur
    {
        count = 1;
        for ( arr2 = arr + size ; arr2 < arrEnd; arr2 += size)
           if (equals(arr, arr2)) {
                count++;
        }
        if (count == maxCount)
        {
            find = i;
            break;
        }
        i++;
    } 
    return find;
}