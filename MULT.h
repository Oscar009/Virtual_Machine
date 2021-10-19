#ifndef MULT_h
#define MULT_h

#include <string>
#include <iostream>
#include "Instruction.h"

using namespace std;

class MULT : public Instruction
{
    int operand1;
    int operand2;

public:
    MULT();
    MULT(string, int, int, int, int);
    int getOperand1();
    int getOperand2();
};


#endif