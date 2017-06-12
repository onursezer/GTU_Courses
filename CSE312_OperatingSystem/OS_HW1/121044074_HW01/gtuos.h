#ifndef H_GTUOS
#define H_GTUOS

#include "8080emuCPP.h"


class GTUOS{
public:
	uint64_t handleCall(const CPU8080 & cpu);
	void print_b(const CPU8080 & cpu);
	void  print_mem(const CPU8080 & cpu);
	void read_b(const CPU8080 & cpu);
	void read_mem(const CPU8080 & cpu);
	void print_str(const CPU8080 & cpu);
	void read_str(const CPU8080 & cpu);
	void printMem(const CPU8080 & cpu);

};

#endif