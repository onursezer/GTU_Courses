/* 
 * File:   main.cpp
 * Author: OnurSezer
 *
 * Created on 18 Aralık 2015 Cuma, 06:15
 */

#include <cstdlib>
#include "Directory.h"
#include "Executable.h"
#include "File.h"
#include "TextFile.h"

using namespace std;
using namespace SEZER;
/*
 * 
 */
int main() {
    Directory home("home","onur",5233,"18.12.2014");
    Directory user("user","onur",4123,"7.12.2015");
    Directory physics("physics","onur",221,"2.12.2015");
    Directory math("math","onur",953,"3.7.2015");
    Directory chemistry("chemistry","onur",135,"2.2.2015");
    Directory lessons("lessons","onur",1547,"12.8.2015");
    
    TextFile addition("addition","onur",23,"21.3.2015");
    TextFile subtraction("subtraction","onur",31,"12.3.2015");
    TextFile atom("atom","onur",19,"9.6.2015");
    TextFile na("na","onur",22,"8.12.2015");
    TextFile hidrojen("hidrojen","onur",34,"1.12.2015");
    TextFile oksijen("oksijen","onur",56,"2.12.2015");
    TextFile kinetic("kinetic","onur",26,"9.11.2015");
    TextFile jeo("jeo","onur",78,"12.12.2015");
 
    Executable exe("exe","onur",39,"11.12.2015");
    Executable exe2("exe2","onur",34,"9.12.2014");
    Executable exe3("exe3","onur",37,"12.12.2015");
    Executable exe4("exe4","onur",46,"28.10.2015");
    Executable exe5("exe5","onur",54,"18.12.2015");
    Executable exe6("exe6","onur",55,"18.10.2015");
    Executable exe7("exe7","onur",67,"18.11.2015");
    
    cout << "~~~~~~~~ Test Directory ~~~~~~~~~~~~~" << endl;
    cout << "**** Test cp & path  Fuctions **** " << endl;
    home.cp(&user);
    user.cp(&lessons);
    lessons.cp(&math);
    lessons.cp(&physics);
    lessons.cp(&chemistry);
    math.cp(&addition);
    math.cp(&subtraction);
    physics.cp(&kinetic);
    physics.cp(&jeo);
    chemistry.cp(&atom);
    chemistry.cp(&hidrojen);
    chemistry.cp(&na);
    chemistry.cp(&oksijen);
    home.cp(&exe);
    home.cp(&exe2);
    user.cp(&exe3);
    lessons.cp(&exe4);
    lessons.cp(&exe5);
    math.cp(&exe6);
    physics.cp(&exe7);
    
    cout << home.path() << endl;
    cout << user.path() << endl;
    cout << lessons.path() << endl;
    cout << math.path() << endl;
    cout << chemistry.path() << endl;
    cout << physics.path() << endl;
    cout << addition.path() << endl;
    cout << subtraction.path() << endl;
    cout << atom.path() << endl;
    cout << na.path() << endl;
    cout << hidrojen.path() << endl;
    cout << oksijen.path() << endl;
    cout << kinetic.path() << endl;
    cout << jeo.path() << endl;
    cout << exe.path() << endl;
    cout << exe2.path() << endl;
    cout << exe3.path() << endl;
    cout << exe4.path() << endl;
    cout << exe5.path() << endl;
    cout << exe6.path() << endl;
    cout << exe7.path() << endl;
    
    cout << "\n**** Test ls  Fuction ****" << endl;
    cout << "\n~~~~~~~ Test '-l' ~~~~~~~ " << endl;
    home.ls("l");
    cout << "\n~~~~~~~ Test '-a' ~~~~~~~ " << endl;
    home.ls("a");
    cout << "\n~~~~~~~ Test '-R' ~~~~~~~ " << endl;
    home.ls("R");
    cout << "\n~~~~~~~ Test '-al' ~~~~~~~ " << endl;
    home.ls("al");
    cout << "\n~~~~~~~ Test '-aR' ~~~~~~~ " << endl;
    home.ls("aR");
    cout << "\n~~~~~~~ Test '-Rl' ~~~~~~~ " << endl;
    home.ls("Rl");
    
    cout << "\n**** Test cd  Fuction ****" << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << home.getName() << endl;
    cout << "After cd" << endl;
    cout << home.cd(&user).getName() << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << user.getName() << endl;
    cout << "After cd" << endl;
    cout << user.cd(&lessons).getName() << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << lessons.getName() << endl;
    cout << "After cd" << endl;
    cout << lessons.cd(&math).getName() << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << math.getName() << endl;
    cout << "After cd" << endl;
    cout << math.cd(&user).getName() << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << math.getName() << endl;
    cout << "After cd" << endl;
    cout << math.cd(&addition).getName() << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << user.getName() << endl;
    cout << "After cd" << endl;
    cout << user.cd(&lessons).getName() << endl;
    cout << endl;
    cout << "Before cd" << endl;
    cout << lessons.cd(&math).getName() << endl;
    cout << "After cd" << endl;
    cout << lessons.getName() << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "\n~~~~~~~~ Test Executable ~~~~~~~~~~~~~" << endl;
    cout << "**** Test cp & path  Fuctions **** " << endl;
    exe.cp(&exe2);
    exe.cp(&math);
    exe.cp(&addition);
    
    cout << exe.path() << endl;
    cout << "\n**** Test ls  Fuction ****" << endl;
    cout << "\n~~~~~~~ Test '-l' ~~~~~~~ " << endl;
    exe.ls("l");
    cout << "\n~~~~~~~ Test '-a' ~~~~~~~ " << endl;
    exe.ls("a");
    cout << "\n~~~~~~~ Test '-R' ~~~~~~~ " << endl;
    exe.ls("R");
    cout << "\n~~~~~~~ Test '-aR' ~~~~~~~ " << endl;
    exe.ls("aR");
    cout << "\n~~~~~~~ Test '-al' ~~~~~~~ " << endl;
    exe.ls("al");
    cout << "\n~~~~~~~ Test '-Rl' ~~~~~~~ " << endl;
    exe.ls("Rl");
    cout << "\n******** Test cd  Fuction ********" << endl;
    exe.cd(&exe2);
    exe.cd(&math);
    exe.cd(&addition);
    
    cout << "-----------------------------------------------" << endl;
    cout << "\n~~~~~~~~ Test TextFile ~~~~~~~~~~~~~" << endl;
    cout << "**** Test cp & path  Fuctions **** " << endl;
    atom.cp(&exe2);
    atom.cp(&math);
    atom.cp(&addition);
    
    cout << exe.path() << endl;
    cout << "\n**** Test ls  Fuction ****" << endl;
    cout << "\n~~~~~~~ Test '-l' ~~~~~~~ " << endl;
    atom.ls("l");
    cout << "\n~~~~~~~ Test '-a' ~~~~~~~ " << endl;
    atom.ls("a");
    cout << "\n~~~~~~~ Test '-R' ~~~~~~~ " << endl;
    atom.ls("R");
    cout << "\n~~~~~~~ Test '-aR' ~~~~~~~ " << endl;
    atom.ls("aR");
    cout << "\n~~~~~~~ Test '-al' ~~~~~~~ " << endl;
    atom.ls("al");
    cout << "\n~~~~~~~ Test '-Rl' ~~~~~~~ " << endl;
    atom.ls("Rl");
    cout << "\n**** Test cd  Fuction ****" << endl;
    atom.cd(&exe2);
    atom.cd(&math);
    atom.cd(&addition);
    cout << "-----------------------------------------------" << endl;
    return 0;
}

