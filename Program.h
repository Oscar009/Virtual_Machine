#ifndef Program_h
#define Program_h

#include "Instruction.h"
#include <iostream>

class Program
{
    Instruction* instructions;
    int size;
    int length;

public:
    Program(int);

    void addInstruction(Instruction*);
    Instruction getInstruction(int);
    Instruction* getInstructions();

    int getSize();
};

#endif