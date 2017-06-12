#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include <iostream>

int main (int argc, char**argv)
{
	if (argc != 3){
		std::cerr << "Usage: prog exeFile debugOption\n";
		exit(1); 
	}
	int DEBUG = atoi(argv[2]);

	CPU8080 theCPU;
	GTUOS	theOS;
    int totalCycle = 0;
	theCPU.ReadFileIntoMemoryAt(argv[1], 0x0000);	


	do	
	{
        totalCycle += theCPU.Emulate8080p(DEBUG);
		if(theCPU.isSystemCall())
            totalCycle += theOS.handleCall(theCPU);
        if (DEBUG == 2)
            std::cin.get();
	}	while (!theCPU.isHalted());

    printf("\nTotal Number of Cycle : %d\n", totalCycle);

    theOS.printMem(theCPU);

	return 0;
}

