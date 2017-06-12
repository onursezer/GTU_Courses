/* 
 * File:   Directory.h
 * Author: OnurSezer
 *
 * Created on 18 Aralık 2015 Cuma, 06:17
 */

#ifndef DIRECTORY_H
#define	DIRECTORY_H

#include "File.h"
#include <vector>
using std::vector; 
namespace SEZER{
    class Directory : public File{
    public:
        Directory():File(){}
        Directory(string _name, string _owner, int _size, string _lastModificaiton):
            File(_name,_owner,_size,_lastModificaiton){}
        virtual string path();
        virtual void ls(string str); 
        virtual File& cd(File* obje);
        virtual bool cp(File* obje);
    private:     
        vector <File*> v;  //directory'e icindeki file ya da directorler atilir.
        int lsR(File *obje); // ls -R de kullanilir.
        int lsRl(File *obje); // ls -Rl de kullanilir.
        int lsaR(File *obje); // ls -aR de kullanilir.
    };
}
#endif	/* DIRECTORY_H */

