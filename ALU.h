#ifndef ALU_h
#define ALU_h

#include "Register.h"

class ALU
{
public:
    ALU();

    int Add(int, int);
    int Rest(int, int);
    int Mult(int, int);
    int Div(int, int);
    void Mov(int, Register*);
    void Sto(int, Register*);

};

#endif