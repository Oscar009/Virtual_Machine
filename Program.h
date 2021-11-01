#ifndef Program_h
#define Program_h

#include "Instruction.h"
#include <iostream>
#include "ADD.h"

using namespace std;

class Program
{
    Instruction *instructions[10];
    int size;
    int length;

public:
    Program(){}
    Program(int);

    void addInstruction(Instruction *);
    Instruction *getInstruction(int);
    Instruction **getInstructions();

    int getSize();
};

#endif