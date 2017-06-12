#include "TextFile.h"
using namespace std;
namespace SEZER{
    string TextFile::path()
    {
        return getPathName();
    }
    void TextFile::ls(string str)
    {
        if(str == "l")
        {
            cout << "-rw-rw-r-- " << getName() << " " << getOwner() << " " 
                   << getSize() << " " << getLastModificaiton() << endl;
        }
        else if(str == "a")
        {
            cout << getName() << endl;
        }
        else if(str == "al")
        {
            cout << "-rw-rw-r-- " << getName() << " " << getOwner() << " " 
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
            cout << "-rw-rw-r-- " << getName() << " " << getOwner() << " " 
                   << getSize() << " " << getLastModificaiton() << endl;
        }   
        else
            cout << "Error Entery" << endl
                 <<"You should enter 'a', 'l', 'R', 'al', 'aR', 'Rl'" << endl;
    }
    File& TextFile::cd(File *obje)
    {
        cout << "Not a directory !" << endl;
    }
    bool TextFile::cp(File* obje)
    {
        return false;
    }
}
