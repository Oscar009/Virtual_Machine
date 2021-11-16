#ifndef STO_h
#define STO_h

#include "Instruction.h"
#include <string>

using namespace std;

class STO: public Instruction
{
    int value;
    string nameOfRegister;
public:
    STO();
    STO(string, int, int, int);

    void setValue(int);
    int getValue();

};

#endif