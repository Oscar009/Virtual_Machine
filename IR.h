#ifndef IR_h
#define IR_h

#include "Register.h"
#include <string>

using namespace std;

class IR : public Register
{

public:
    IR();
    IR(string);
};
#endif