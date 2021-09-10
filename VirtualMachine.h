#ifndef VirtualMachine_h
#define VirtualMachine_h

#include <iostream>
#include "Register.h"
#include "ALU.h"
#include "CU.h"

using namespace std;

class VirtualMachine
{
    Register *_registers;
    ALU _arithmeticLogicalUnit;
    CU _controlUnit;

public:
    VirtualMachine(Register *, ALU, CU);
    ~VirtualMachine();

    void showRegisters();
};

#endif