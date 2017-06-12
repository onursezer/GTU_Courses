#include <iostream>
#include "8080emuCPP.h"
#include "gtuos.h"
#include "unistd.h"


MemoryManUnit::MemoryManUnit(int memoryBase, int memoryLimit) {
    this->mem = (uint8_t *) malloc(0x10000);
    this->memoryBase = memoryBase;
    this->memoryLimit = memoryLimit;
}
uint8_t & MemoryManUnit::at(uint32_t ind)
{

    uint32_t  adress = getMemoryBase() + ind;
    if (adress >= getMemoryBase() && adress < getMemoryLimit()) {

        return physicalAt(adress);
    } else {
        cout << "getMemoryBase() :" << getMemoryBase() << endl;
        cout << "getMemoryLimit() : " << getMemoryLimit() << endl;
        cout << "ind : " << ind << endl;

        exit(-1);
    }
}
uint8_t & MemoryManUnit::physicalAt(uint32_t ind)
{
    if(ind < 0 || ind > 0x10000)
    {
        cout << "Error -> physicalAt" << endl;
        cout << "physicalAt is over size " << endl;
        cout << "ind : " << ind << endl;
        exit(-2);
    }
    return mem[ind];
}
int MemoryManUnit::getMemoryBase() const {
    return memoryBase;
}

void MemoryManUnit::setMemoryBase(int memoryBase) {
    MemoryManUnit::memoryBase = memoryBase;
}

int MemoryManUnit::getMemoryLimit() const {
    return memoryLimit;
}

void MemoryManUnit::setMemoryLimit(int memoryLimit) {
    MemoryManUnit::memoryLimit = memoryLimit;
}

GTUOS::GTUOS(CPU8080 &cpu, MemoryBase *mem, string filename)
{

    this->mem = (MemoryManUnit *)mem;
    processNum = 0;

    Process p1;
    // set parent process
    p1.setFilename(filename);
    p1.setPid(++processNum + 9);
    p1.setPpid(0);
    p1.setStatus(READY);
    p1.setStartTime(0);
    p1.setBase(0x0000);
    p1.setLimit(0x4000);
    p1.setPhysicalAddress(p1.getBase());

    processTable.insert(pair<int, Process>(p1.getPid(), p1)); // add process to
    order.push_back(p1.getPid());

    currentProcess = scheduler(cpu);
    memArray[0] = true;
    p1.setMemCore(0);
    p1.toString();
}
void GTUOS::fork(const CPU8080 & cpu)
{
    printf("\nSystem Call : FORK\n");

    Process parent = *currentProcess;

    if(processTable.size() < 4) {
        Process child;
        int parentBase = parent.getBase();
        int parentLimit = parent.getLimit();

        child.setBase(parentLimit);
        child.setLimit(parentLimit + 0x4000);
        bool b;
        int i = 0;
        for(; i < 4; ++i){
            b = memArray[i];
            if(b == false){
                if (i == 0) {
                    memArray[i] = true;
                    child.setBase( 0x0000);
                    child.setLimit(0x4000);
                    break;
                }
                if (i == 1) {
                    memArray[i] = true;
                    child.setBase( 0x4000);
                    child.setLimit(0x8000);
                    break;
                }
                else if (i == 2) {
                    memArray[i] = true;
                    child.setBase( 0x8000);
                    child.setLimit(0xC000);
                    break;
                }
                else if (i == 3) {
                    memArray[i] = true;
                    child.setBase( 0xC000);
                    child.setLimit(0x10000);
                    break;
                }
            }
        }

        // child set
        child.setMemCore(i-1);
        child.setPid(++processNum + 9);
        child.setPpid(parent.getPid());
        child.setStartTime(programCycleCounter);
        child.setPhysicalAddress(child.getBase());
        child.setFilename(parent.getFilename());
        child.setStatus(READY);
        child.procesStateRegisters = *cpu.state;

        // parent memory copy to child
        int childMem = child.getBase();
        for (int i = parentBase; i < parentLimit; ++i) {
            cpu.memory->physicalAt(childMem) = cpu.memory->physicalAt(i);
            ++childMem;
        }
        cpu.state->b = child.getPid();
        child.procesStateRegisters.b = 0;

        registers.insert(pair<int, State8080>(child.getPid(), child.procesStateRegisters));
        processTable.insert(pair<int, Process>(child.getPid(), child)); // add process to
        order.push_back(child.getPid());
        child.toString();
    }
    else
        cpu.state->b = 1;
}
void GTUOS::exec( const CPU8080 & cpu)
{
    printf("\nSystem Call : EXEC\n");

    char* filename = new char [100];
    int sizeOfStr = 0;

    uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
    unsigned char * code;
    code = &cpu.memory->at(bc);
    while(*code != 0x00)
    {
        filename[sizeOfStr] = cpu.memory->at(bc);
        bc++;
        sizeOfStr++;
        code = &cpu.memory->at(bc);
    }
    filename[sizeOfStr] = '\0';

    char buff[255];
    getcwd( buff, 255 );
    string cwd( buff );

    string path = cwd + "/" + filename;

    ReadFileIntoMemoryAt(path.c_str(), currentProcess->getBase());
    cpu.state->pc = 0;
}
void GTUOS::waitPid(const CPU8080 & cpu)
{
    cout << "wait_pid" << endl;
    currentProcess->setStatus(BLOCKED);
    waitProcess = cpu.state->b;
    blockProcess = currentProcess->getPid();
}
bool GTUOS::waitReadyProcess( )
{
    cout << "2 burda" << endl;
    if(waitProcess != -1 && blockProcess != -1) {
        cout << "3 burda" << endl;

        cout << "1 burda" << endl;
        waitProcess = -1;
        processTable.at(blockProcess).setStatus(READY);
        cout << "waitReadyProcess block process : " << blockProcess << endl;
        blockProcess = -1;
        return true;

    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////

Process * GTUOS::scheduler(CPU8080 & cpu ) {
    int i = 0;
    while(!done){
        if (!order.empty() && i < order.size()){
            i = i % order.size();
            Process * p = &processTable.at(order[i]);
            if (p->getStatus() == READY){

                cout << "1" << endl;
                // context switch
                currentProcess->procesStateRegisters = *cpu.state;
                if(programCycleCounter != 0) {
                    cout << "-----------------------------------------------" << endl;
                    cout << "           PROCESS SWITCH                      " << endl;
                    cout << "old process :" << endl;
                    currentProcess->toString();
                    registers.erase(currentProcess->getPid());
                    registers.insert(pair<int, State8080>(currentProcess->getPid(), currentProcess->procesStateRegisters));//currentProcess = &processTable.at(order[i]);
                    *cpu.state = registers.at(p->getPid());
                }
                cout << "2" << endl;
                mem->setMemoryBase(p->getBase());
                mem->setMemoryLimit(p->getLimit());
                p->setStatus(RUNNING);
                order.erase(order.begin() + i);
                cout << "3" << endl;
                if(programCycleCounter != 0) {
                    cout << "new process :" << endl;
                    p->toString();
                    cout << "-----------------------------------------------" << endl;
                }
                return p;
            }
            else i++;
        }
        else if (processTable.empty())
            return NULL;
    }
    return NULL;
}

void GTUOS::run(CPU8080 & cpu,int DEBUG) {

    int cycle = 0, totalCycle = 0;

    while (!done) {
        cycle = cpu.Emulate8080p(DEBUG);
        currentProcess->setTotalCycle(cycle);
        totalCycle += cycle;
        programCycleCounter += cycle;
        //cout << "$$$ " << currentProcess->getStartTime() << endl;

        if (cpu.isSystemCall()) {     // process has a syscall. we shall
            cycle = handleCall(cpu);
            totalCycle += cycle;
            programCycleCounter += cycle;
            currentProcess->setTotalCycle(cycle);
        }
        if (cpu.isHalted()){ // if process is halted, delete it from process table.
            processTable.erase(currentProcess->getPid());
            currentProcess = scheduler(cpu);
            //memArray[currentProcess->getMemCore()] = false;
            if (currentProcess == NULL)
                done = true;
        }
        //cout << "totalCycle : " << totalCycle << endl;
        if (!done && currentProcess != NULL && totalCycle >= 100) {
            cout << "**** Quantum is Over ***" << endl;
            if (currentProcess->getStatus() == RUNNING){
                order.push_back(currentProcess->getPid());
                currentProcess->setStatus(READY);
            }
            currentProcess = scheduler(cpu);
            if (currentProcess == NULL)
                done = true;

            totalCycle = 0;

        }
    }
}


///////////////////////////////////////////////////////////////////////////////
void GTUOS::printRegisters(const CPU8080 & cpu)
{
    cout << "a : "<< (int)cpu.state->a << " " <<"b : " << (int)cpu.state->b<< " ";
    cout <<"c : " << (int)cpu.state->c<< " ";
    cout    << "d : " << (int)cpu.state->d<< " " << "e : "<< (int)cpu.state->e<< " ";
    cout   << "h : "<< (int)cpu.state->h<< " " << "l : " << (int)cpu.state->l<< " ";
    cout   << "pc : "   << (int)cpu.state->pc<< " " << "sp : "<< (int)cpu.state->sp << endl;
}
void GTUOS::ReadFileIntoMemoryAt(const char* filename, uint32_t offset)
{
    FILE *f= fopen(filename, "rb");
    if (f==NULL)
    {
        printf("error: Couldn't open %s\n", filename);
        exit(1);
    }
    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    uint8_t *buffer = &mem->physicalAt(offset);
    fread(buffer, fsize, 1, f);
    fclose(f);
}


///// HW1  //////
uint64_t GTUOS::handleCall(const CPU8080 & cpu)
{
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
        case 7 :
            fork( cpu );
            cycle = 50;
            break;
        case 8 :
            exec( cpu );
            cycle = 80;
            break;
        case 9 :
            waitPid( cpu );
            cycle = 80;
            break;
    }

    return cycle;
}
void GTUOS::print_b(const CPU8080 & cpu)
{
    printf("\nSystem Call : PRINT_B\n");
    printf("B: %d\n",cpu.state->b);
    //cout << "print_b :: currentProcess->getPid() " << currentProcess->getPid() << endl;
}
void GTUOS::print_mem(const CPU8080 & cpu)
{
    printf("\nSystem Call : PRINT_MEM\n");
    uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
    printf("BC: %d\n”", cpu.memory->at(bc));
}
void GTUOS::read_b(const CPU8080 & cpu)
{
    printf("\nSystem Call : READ_B\n");
    int num;
    scanf("%d",&num);
    cpu.state->b = num;
}
void GTUOS::read_mem(const CPU8080 & cpu)
{
    printf("\nSystem Call : READ_MEM\n");
    int num;
    char c;
    scanf("%d%c",&num,&c);
    uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
    cpu.memory->at(bc) = num;
}
void GTUOS::print_str(const CPU8080 & cpu)
{
    printf("\nSystem Call : PRINT_STR\n");
    uint16_t bc = (cpu.state->b << 8) | cpu.state->c;
    unsigned char * code;
    code = &cpu.memory->at(bc);
    while(*code != 0x00)
    {
        printf("%c",cpu.memory->at(bc));
        bc++;
        code = &cpu.memory->at(bc);
    }
}
void GTUOS::read_str(const CPU8080 & cpu)
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
        cpu.memory->at(bc) = str[i];
        ++bc;
    }
    cpu.memory->at(bc) = 0x00;
}
void GTUOS::printMem(const CPU8080 & cpu) {
    FILE *inp = fopen("exe.mem", "w");
    int count = 0;
    for (int i = 0x0000; i < 0xffff; ++i) {
        if (count == 16)
            count = 0;
        if (count == 0)
            fprintf(inp, "%.4x: ", i);
        if (count == 15) {
            fprintf(inp, "%.2x\n", cpu.memory->physicalAt(i));
        }
        if (count != 15)
            fprintf(inp, "%.2x ", cpu.memory->physicalAt(i));
        count++;
    }
    fclose(inp);
}

