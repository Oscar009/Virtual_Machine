#ifndef REST_h
#define REST_h

#include <string>
#include <iostream>
#include "Instruction.h"

using namespace std;

class REST : public Instruction
{
    int operand1;
    int operand2;

public:
    REST();
    REST(string, int, int, int, int);
    int getOperand1();
    int getOperand2();
};

#endif