#ifndef END_h
#define END_h

#include "Instruction.h"
#include <string>

class END : public Instruction
{
public:
    END();
    END(string, int, int);
};

#endif