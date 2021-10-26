#ifndef IR_h
#define IR_h

#include "Register.h"
#include <string>
#include "Instruction.h"

using namespace std;

class IR : public Register
{

    Instruction* instruction;

public:
    IR();
    IR(string);

    Instruction* getInstruction();
    void setInstruction(Instruction*);
};
#endif