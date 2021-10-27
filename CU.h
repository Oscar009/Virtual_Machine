#ifndef CU_h
#define CU_h

#include <string>
#include <iostream>
#include "Instruction.h"
#include "Register.h"
#include "Program.h"
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

    Instruction * fetch(Program*, int); 
    int decode(Instruction*);
    void execute(int, Instruction*);

    void displayStatus();
    void setStatus(string);
};

#endif