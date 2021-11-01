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
#include "MULT.h"
#include "DIV.h"
#include "MOV.h"
#include "STO.h"
#include "REST.h"

using namespace std;

class CU
{
    string status;
    ALU alu;
    Register *registers;

public:
    CU();
    CU(string, Register *, ALU);

    Instruction *fetch(Program *, int, int);
    int decode(Instruction *);
    void execute(int, Instruction *);

    void displayStatus();
    void setStatus(string);
};

#endif