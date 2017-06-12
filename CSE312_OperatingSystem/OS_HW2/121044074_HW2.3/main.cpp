#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"

int main (int argc, char**argv)
{
	if (argc != 3){
		std::cerr << "Usage: prog exeFile debugOption\n";
		exit(1); 
	}
	int DEBUG = atoi(argv[2]);

    MemoryManUnit mem(0x0000, 0x4000);
	CPU8080 theCPU(&mem);
	theCPU.ReadFileIntoMemoryAt(argv[1], 0x0000);
	cout << "mainnnaaa" << endl;

	GTUOS theOS(theCPU, &mem, argv[1]);
	cout << "mainnn" << endl;
    theOS.run(theCPU, DEBUG);
    theOS.printMem(theCPU);


	return 0;
}

