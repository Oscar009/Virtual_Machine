#ifndef Program_h
#define Program_h

#include "Instruction.h"
#include <iostream>
#include "ADD.h"

using namespace std;

class Program
{
    Instruction **instructions;
    int size;
    int length;

public:
    Program(){}
    Program(int);
    ~Program();

    void addInstruction(Instruction *);
    Instruction *getInstruction(int);

    int getSize();
};

#endif