#ifndef ADD_h
#define ADD_h

#include <string>
#include <iostream>
#include "Instruction.h"

using namespace std;

class ADD : public Instruction
{
    int operand1;
    int operand2;

public:
    ADD();
    ADD(string, int, int, int, int);
    int getOperand1();
    int getOperand2();
};

#endif