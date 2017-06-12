#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include <fstream>

uint64_t GTUOS::handleCall(const CPU8080 & cpu){


	int registerA =  cpu.state->a;
	//printf("registerA :  %d \n",registerA);
    int cycle;
	switch(registerA)
	{
		case 1 :
			print_b( cpu );
            cycle = 10;
			break;
		case 2 :
			print_mem( cpu );
            cycle = 10;
			break;
		case 3 :
			read_b( cpu );
            cycle = 10;
			break;
		case 4 :
			read_mem( cpu );
            cycle = 10;
			break;
		case 5 :
			print_str( cpu );
            cycle = 100;
			break;
		case 6 :
			read_str( cpu );
            cycle = 100;
			break;
	}

	return cycle;
}

void GTUOS::print_b(const CPU8080 & cpu)
{
    printf("\nSystem Call : PRINT_B\n");
	printf("B: %d",cpu.state->b);
}
void GTUOS::print_mem(const CPU8080 &cpu)
{
    printf("\nSystem Call : PRINT_MEM\n");
	uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
	printf("BC: %d", cpu.memory[bc]);
}
void GTUOS::read_b(const CPU8080 &cpu)
{
    printf("\nSystem Call : READ_B\n");
	int num;
	scanf("%d",&num);
	cpu.state->b = num;
}
void GTUOS::read_mem(const CPU8080 &cpu)
{
    printf("\nSystem Call : READ_MEM\n");
	int num;
    char c;
	scanf("%d%c",&num,&c);
	uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
	cpu.memory[bc] = num;
}
void GTUOS::print_str(const CPU8080 &cpu)
{
    printf("\nSystem Call : PRINT_STR\n");
	uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
    unsigned char * code;
    code = &cpu.memory[bc];
    while(*code != 0x00)
    {
        printf("%c",cpu.memory[bc]);
        bc++;
        code = &cpu.memory[bc];
    }
}
void GTUOS::read_str(const CPU8080 &cpu)
{
    printf("\nSystem Call : READ_STR\n");
    int length = 10;
    char * str = (char *)calloc(length , sizeof(char));
    int count = 0, i;
    char c;

    while((c = getchar()) != '\n'){

        if(count >= length){
            str = (char *)realloc(str, (length += 10) * sizeof(char));
        }
        str[count++] = c;
    }

    uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
    for(i = 0; str[i] != '\0'; ++i)
    {
        cpu.memory[bc] = str[i];
        ++bc;
    }
    cpu.memory[bc] = 0x00;
}
void GTUOS::printMem(const CPU8080 & cpu)
{
    FILE *inp = fopen("exe.mem","w");
    int count = 0;
    for (int i = 0x0000; i <= 0xffff ; ++i) {
        if(count == 16)
            count = 0;
        if(count == 0)
            fprintf(inp,"%.4x: ",i);
        if(count == 15) {
            fprintf(inp, "%.2x\n", cpu.memory[i]);
        }
        if(count != 15)
            fprintf(inp, "%.2x ", cpu.memory[i]);
        count++;
    }

}













