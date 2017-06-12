#include "Executable.h"
using namespace std;
namespace SEZER{
    string Executable::path()
    {
        return getPathName();
    }
    void Executable::ls(string str)
    {
        if(str == "l")
        {
            cout << "-rwxrwxr-x " << getName() << " " << getOwner() << " " 
                   << getSize() << " " << getLastModificaiton() << endl;
        }
        else if(str == "a")
        {
            cout << getName() << endl;
        }
        else if(str == "al")
        {
            cout << "-rwxrwxr-x " << getName() << " " << getOwner() << " " 
                  << getSize() << " " << getLastModificaiton() << endl;
        }
        else if(str == "aR")
        {
            cout << getName() << endl;
        } 
        else if(str == "R")
        {
            cout << getName() << endl;
        }   
        else if(str == "Rl")
        {
            cout << "-rwxrwxr-x " << getName() << " " << getOwner() << " " 
                   << getSize() << " " << getLastModificaiton() << endl;
        }   
        else
            cout << "Error Entery" << endl
                 <<"You should enter 'a', 'l', 'R', 'al', 'aR', 'Rl'" << endl;
    }
    File& Executable::cd(File *obje)
    {
        cout << "Not a directory!" << endl;
    }
    bool Executable::cp(File* obje)
    {
        return false;
    }
}
