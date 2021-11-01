#ifndef MOV_h
#define MOV_h

#include "Instruction.h"
#include <string>

using namespace std;

class MOV: public Instruction
{
    int value;
    string nameOfRegister;
public:
    MOV();
    MOV(string, int, int, int, string);

    void setValue(int);
    int getValue();

    void setNameOfRegister(string);
    string getNameOfRegister();
};

#endif