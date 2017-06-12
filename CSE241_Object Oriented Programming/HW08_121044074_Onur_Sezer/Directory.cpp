#include "Directory.h"
#include "Executable.h"
#include "TextFile.h"
using namespace std; 
namespace SEZER{
    string Directory::path()
    {
        return getPathName();
    }
    void Directory::ls(string str)
    {
        if(str == "l")
        {
            for (int i = 0; i < v.size(); i++) 
            {
                Directory* d = dynamic_cast<Directory*>(v[i]);
                if(d != NULL)
                {
                    cout << "drwxr-xr-x " << v[i]->getName() << " " << v[i]->getOwner() << " " 
                            << v[i]->getSize() << " " << v[i]->getLastModificaiton() << endl;
                }
                Executable* e = dynamic_cast<Executable*>(v[i]);
                if(e != NULL)
                {
                    cout << "-rwxrwxr-x " << v[i]->getName() << " " << v[i]->getOwner() << " " 
                            << v[i]->getSize() << " " << v[i]->getLastModificaiton() << endl;
                }
                TextFile* t = dynamic_cast<TextFile*>(v[i]);
                if(t != NULL)
                {
                    cout << "-rw-rw-r--" << v[i]->getName() << " " << v[i]->getOwner() << " " 
                            << v[i]->getSize() << " " << v[i]->getLastModificaiton() << endl;
                }
            }

        }
        else if(str == "a")
        {
            cout << ". .. " ;
            for (int i = 0; i < v.size(); i++) 
            {
                cout << v[i]->getName() << " ";
            }
            cout << endl;
        }
        else if(str == "al")
        {
            cout << "drwxr-xr-x onur onur 4096 19.12.2015 ." << endl; 
            cout << "drwxr-xr-x onur onur 4096 20.12.2015 .." << endl; 
            for (int i = 0; i < v.size(); i++) 
            {
                Directory* d = dynamic_cast<Directory*>(v[i]);
                if(d != NULL)
                {
                    cout << "drwxr-xr-x " << v[i]->getName() << " " << v[i]->getOwner() << " " 
                            << v[i]->getSize() << " " << v[i]->getLastModificaiton() << endl;
                }
                Executable* e = dynamic_cast<Executable*>(v[i]);
                if(e != NULL)
                {
                    cout << "-rwxrwxr-x " << v[i]->getName() << " " << v[i]->getOwner() << " " 
                            << v[i]->getSize() << " " << v[i]->getLastModificaiton() << endl;
                }
                TextFile* t = dynamic_cast<TextFile*>(v[i]);
                if(t != NULL)
                {
                    cout << "-rw-rw-r--" << v[i]->getName() << " " << v[i]->getOwner() << " " 
                            << v[i]->getSize() << " " << v[i]->getLastModificaiton() << endl;
                }
            }
        }
        else if(str == "aR")
            lsaR(this);
        else if(str == "R")
            lsR(this);
        else if(str == "Rl")
            lsRl(this);
        else
            cout << "Error Entery" << endl
                 <<"You should enter 'a', 'l', 'R', 'al', 'aR', 'Rl'" << endl;

    }
    File& Directory::cd(File *obje)
    {
        int st=0;
        for (int i = 0; i < v.size(); i++) 
        {
            if(v[i]->getName() == obje->getName())
            {
                st = 1;
                break;
            }
        }
        if(st != 1)
        {
            cout << "CD can not." << endl;
            return *this;
        }
        
        Directory* d = dynamic_cast<Directory*>(obje);
        if(d != NULL)
            return *obje;
        else
        {
            cout << "Not a directory !" << endl; 
            return *this;
        }
    }
    bool Directory::cp(File* obje)
    {    
        v.push_back(obje);
        obje->setPathName(getPathName()+ obje->getPathName()); 
        Directory* d = dynamic_cast<Directory*>(obje);
        if(d != NULL){            
            for(int i=0; i < d->v.size(); ++i){
                d->v[i]->setPathName(getPathName()+ d->v[i]->getPathName());
            }
        }
        return true;
    }
    int Directory::lsR(File *obje)
    {
        Directory* d = dynamic_cast<Directory*>(obje);
        if(d != NULL)
        {
            cout << endl;
            cout << "." << d->getPathName() << ":" << endl;
            for (int i = 0; i < d->v.size(); i++) 
            {         
                cout << d->v[i]->getName() << endl;
            }
            for (int i = 0; i < d->v.size(); i++) 
            {   
                Directory* d2 = dynamic_cast<Directory*>(d->v[i]);
                if(d2 != NULL)
                    lsR(d2);
                else
                    return 0;
            }
        }
    }
    int Directory::lsRl(File *obje)
    {
        Directory* d = dynamic_cast<Directory*>(obje);
        if(d != NULL)
        {
            cout << endl;
            cout << "." << d->getPathName() << ":" << endl;
            for (int i = 0; i < d->v.size(); i++) 
            {         
                Directory* di = dynamic_cast<Directory*>(d->v[i]);
                if(di != NULL)
                {
                    cout << "drwxr-xr-x " << d->v[i]->getName() << " " << d->v[i]->getOwner() << " " 
                            << d->v[i]->getSize() << " " << d->v[i]->getLastModificaiton() << endl;
                }
                Executable* e = dynamic_cast<Executable*>(d->v[i]);
                if(e != NULL)
                {
                    cout << "-rwxrwxr-x " << d->v[i]->getName() << " " << d->v[i]->getOwner() << " " 
                            << d->v[i]->getSize() << " " << d->v[i]->getLastModificaiton() << endl;
                }
                TextFile* t = dynamic_cast<TextFile*>(d->v[i]);
                if(t != NULL)
                {
                    cout << "-rw-rw-r--" << d->v[i]->getName() << " " << d->v[i]->getOwner() << " " 
                            << d->v[i]->getSize() << " " << d->v[i]->getLastModificaiton() << endl;
                }
            }
            for (int i = 0; i < d->v.size(); i++) 
            {   
                Directory* d2 = dynamic_cast<Directory*>(d->v[i]);
                if(d2 != NULL)
                    lsRl(d2);
                else
                    return 0;
            }
        }
    }
    int Directory::lsaR(File *obje)
    {
        Directory* d = dynamic_cast<Directory*>(obje);
        if(d != NULL)
        {
            cout << endl;
            cout << "." << d->getPathName() << ":" << endl;
            cout << ". .. ";
            for (int i = 0; i < d->v.size(); i++) 
            {         
                cout << d->v[i]->getName() << " ";
            }
            cout << endl;
            for (int i = 0; i < d->v.size(); i++) 
            {   
                Directory* d2 = dynamic_cast<Directory*>(d->v[i]);
                if(d2 != NULL)
                    lsaR(d2);
                else
                    return 0;
            }
        }
    }
}