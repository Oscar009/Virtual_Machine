#ifndef Program_h
#define Program_h

#include "Instruction.h"
#include <iostream>

class Program
{
    Instruction* instructions;
    int size;

public:
    Program(int);

    void addInstruction(Instruction);
    Instruction getInstruction(int);

    int getSize();
};

#endif