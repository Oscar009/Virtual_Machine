#ifndef PC_h
#define PC_h

#include "Register.h"
#include <string>
#include "Instruction.h"

using namespace std;

class PC : public Register
{

    Instruction* address;

public:
    PC();
    PC(string);

    void setAddress(Instruction*);
    Instruction* getAddress();
};

#endif