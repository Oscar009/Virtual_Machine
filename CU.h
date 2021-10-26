#ifndef CU_h
#define CU_h

#include <string>
#include <iostream>
#include "Instruction.h"
#include "Register.h"
#include "PC.h"
#include "MAR.h"
#include "IR.h"
#include "ALU.h"
#include "ADD.h"

using namespace std;

class CU 
{
    string status;
    ALU alu;

public:
    CU();
	CU(string, ALU);

    void machineCycle(Instruction**, Register*);
    void execute(int, Instruction*);
};

#endif