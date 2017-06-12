/* 
 * File:   TextFile.h
 * Author: OnurSezer
 *
 * Created on 18 Aralık 2015 Cuma, 06:18
 */

#ifndef TEXTFILE_H
#define	TEXTFILE_H

#include "File.h"

namespace SEZER{
    class TextFile : public File{
    public:
        TextFile():File(){}
        TextFile(string _name, string _owner, int _size, string _lastModificaiton):
            File(_name,_owner,_size,_lastModificaiton){}
        virtual string path();
        virtual void ls(string str); 
        virtual File& cd(File* obje);
        virtual bool cp(File* obje);
    private:
        
    };
}
#endif	/* TEXTFILE_H */

