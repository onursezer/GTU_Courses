/* 
 * File:   Executable.h
 * Author: OnurSezer
 *
 * Created on 18 Aralık 2015 Cuma, 06:17
 */

#ifndef EXECUTABLE_H
#define	EXECUTABLE_H

#include "File.h"
using std::cout;
namespace SEZER{
    class Executable : public File{
    public:
    Executable():File(){}
    Executable(string _name, string _owner, int _size, string _lastModificaiton):
        File(_name,_owner,_size,_lastModificaiton){}
    virtual string path();
    virtual void ls(string str); 
    virtual File& cd(File* obje);
    virtual bool cp(File* obje);
    private:

    };
}
#endif	/* EXECUTABLE_H */

