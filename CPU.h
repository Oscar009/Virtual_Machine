#ifndef CPU_h
#define CPU_h

#include "Register.h"
#include "ALU.h"
#include "CU.h"
#include "Program.h"
#include "Instruction.h"
#include "PC.h"
#include "IR.h"
#include "MAR.h"
#include "MBR.h"
#include "ACC.h"
#include "AL.h"
#include "AH.h"
#include "BL.h"
#include "BH.h"

using namespace std;

class CPU
{
    Register* rcpu;
    ALU alu;
    CU cu;

public:
    CPU();
    CPU(Register*, ALU, CU);
    ~CPU();

    void machineCycle(Program *);
    void printRegisters();
};

#endif