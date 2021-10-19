#ifndef DIV_h
#define DIV_h

#include <string>
#include <iostream>
#include "Instruction.h"

using namespace std;

class DIV : public Instruction
{
    int operand1;
    int operand2;

public:
    DIV();
    DIV(string, int, int, int, int);
    int getOperand1();
    int getOperand2();
};

#endif