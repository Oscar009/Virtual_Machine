#ifndef PC_h
#define PC_h

#include "Register.h"
#include <string>

using namespace std;

class PC : public Register
{

public:
    PC();
    PC(string);
};

#endif