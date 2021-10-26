#ifndef MAR_h
#define MAR_h

#include "Register.h"
#include <string>
#include "Instruction.h"

using namespace std;

class MAR : public Register
{
    Instruction *address;
public:
    MAR();
    MAR(string);

    void setAddress(Instruction*);
    Instruction* getAddress();
};

#endif