#include "File.h"

namespace SEZER{
    File::File()
    {
        name = " ";owner = " ";size = 0;lastModificaiton = " "; pathName = "/";
    }
    File::File(string _name, string _owner, int _size, string _lastModificaiton)
    {
        name = _name; owner = _owner; size = _size; 
        lastModificaiton = _lastModificaiton; pathName = "/" + _name;
    }
    string File::getName() const
    {
        return name;
    }
    string File::getOwner()const
    {
        return owner;
    }
    int File::getSize()const
    {
        return size;
    }
    string File::getLastModificaiton()const
    {
        return lastModificaiton;
    }
    string File::getPathName()
    {
        return pathName;
    }
    void File::setName(string _name) 
    { 
        name = _name;
    }
    void File::setOwner(string _owner)
    { 
        owner = _owner;
    }
    void File::setSize(int _size)
    { 
        size = _size;
    }
    void File::setPathName(string _pathName)
    { 
        pathName = _pathName;
    }
    void File::setLastModificaiton(string _lastModificaiton)
    { 
        lastModificaiton = _lastModificaiton;
    }
}

