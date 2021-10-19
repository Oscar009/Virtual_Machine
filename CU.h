#ifndef CU_h
#define CU_h

#include "Instruction.h"
#include "Register.h"

class CU 
{
public:
    CU();

    void machineCycle(Instruction*, Register*);
};

#endif