#ifndef START_h
#define START_h

#include "Instruction.h"
#include <string>

using namespace std;

class START : public Instruction
{
public:
    START();
    START(string, int, int);
};

#endif