#ifndef H_GTUOS
#define H_GTUOS

#include "8080emuCPP.h"
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


enum Status { READY, BLOCKED, RUNNING };
const char * const StatusStrings[] = { "READY", "BLOCKED", "RUNNING"};
//#define DEBUGG

class Process
{
public:
    Process(){totalCycle = 0;}
    inline void toString(){
        cout << getFilename() << "     ";
        printf("%8d",getPid());
        printf("%8d",getPpid());
        printf("%8d",getStartTime());
        printf("  %8d",getTotalCycle() );
        printf("  %8d",getBase()  );
        printf("  %8d    ",getLimit());
        cout << StatusStrings[getStatus()] ;
        cout << endl;
    }

    int getBase() { return base; }
    inline void setBase(int base)   { this->base = base; }

    int getLimit()  { return limit; }
    void setLimit(int limit) { this->limit = limit; }

    int getPhysicalAddress() { return physicalAddress; }
    void setPhysicalAddress(int addr) { this->physicalAddress = addr; }

    void setStatus(Status s) { this->status = s; }
    Status getStatus()       { return status; }

    const string &getFilename() const { return filename; }
    void setFilename(string s) { this->filename = s; }

    int getPid() const { return pid; }
    void setPid(int pid) { Process::pid = pid; }

    int getPpid() const { return ppid; }
    void setPpid(int ppid) { Process::ppid = ppid; }

    int getStartTime() const { return startTime; }
    void setStartTime(int startTime) { this->startTime = startTime; }

    int getTotalCycle() const { return totalCycle; }
    void setTotalCycle(int totalCycle) { this->totalCycle += totalCycle ; }

    int getMemCore() const { return memCore; }
    void setMemCore(int memCore) { this->memCore = memCore; }

    State8080 procesStateRegisters;
private:
    int stackPtr;

    /* data */
    string filename;
    int base;
    int limit;
    int pid;
    int ppid;
    int startTime;
    int totalCycle;
    Status status;
    uint32_t physicalAddress;
    int memCore;
};


class MemoryManUnit :public MemoryBase{
public:
    MemoryManUnit(int memoryBase, int memoryLimit);
    virtual uint8_t & at(uint32_t ind);
    virtual uint8_t & physicalAt(uint32_t ind);
    int getMemoryBase() const;
    void setMemoryBase(int memoryBase);
    int getMemoryLimit() const;
    void setMemoryLimit(int memoryLimit);

private:
    uint8_t * mem;
    int memoryBase;
    int memoryLimit;
};



class GTUOS{
public:

    // constructor
    GTUOS(CPU8080 &cpu, MemoryBase *mem, string filename,int DEBUG);

    // systemCall
    uint64_t handleCall(const CPU8080 & cpu);
    void print_b(const CPU8080 & cpu);
    void print_mem(const CPU8080 & cpu);
    void read_b(const CPU8080 & cpu);
    void read_mem(const CPU8080 & cpu);
    void print_str(const CPU8080 & cpu);
    void read_str(const CPU8080 & cpu);
    void printMem(const CPU8080 & cpu);
    void fork(const CPU8080 & cpu);
    void exec(const CPU8080 & cpu);
    void waitPid(const CPU8080 & cpu);

    // round robin
    Process* roundRobin();
    void run(CPU8080 & cpu);
    // set - get
    inline int getQUANTUM() const { return QUANTUM; }
    inline void setQUANTUM(int QUANTUM) { GTUOS::QUANTUM = QUANTUM; }


private:
    //helper functions
    void ReadFileIntoMemoryAt(const char* filename, uint32_t offset);
    void deleteFromProcessTable(int pid);
    Process findFromProcessTable(int pid);
    void setContext(CPU8080 & cpu,int i);
    void printRegisters(const CPU8080 & cpu);
    bool waitReadyProcess();
    Process * scheduler(CPU8080 & cpu);

    // Data Members
    Process *currentProcess;
    map<int,Process> processTable;
    map<int,State8080> registers;
    vector<int> order;
    int waitProcess ;
    int blockProcess ;
    MemoryManUnit *mem;
    int processNum;
    int QUANTUM ;
    int programCycleCounter ;
    const bool *getMemArray() const;
    bool done ;
    vector<bool> memCore;
    int indexOrder;
    int DEBUG;
};

#endif
