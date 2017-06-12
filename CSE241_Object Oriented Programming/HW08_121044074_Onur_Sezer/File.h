/* 
 * File:   File.h
 * Author: OnurSezer
 *
 * Created on 18 Aralık 2015 Cuma, 06:16
 */

#ifndef FILE_H
#define	FILE_H
#include <iostream>
#include <string>
using std::string;
namespace SEZER{
    class File{
    public:
        File();
        File(string _name, string _owner, int _size, string _lastModificaiton);
        
        //getters
        string getName() const;
        string getOwner()const;
        int getSize()const;
        string getLastModificaiton()const;
        string getPathName();
        
        //setters
        void setName(string _name) ;
        void setOwner(string _owner);
        void setSize(int _size);
        void setPathName(string _pathName);
        void setLastModificaiton(string _lastModificaiton);
        
        //pure virtual functions
        virtual string path() = 0;
        virtual void ls(string str) = 0; 
        virtual File& cd(File* obje) = 0;
        virtual bool cp(File* obje) = 0;
    private:
        string name;
        string owner;
        int size;
        string lastModificaiton;
        string pathName; 
    };
}
#endif	/* FILE_H */

