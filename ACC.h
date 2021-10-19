#ifndef ACC_h
#define ACC_h

#include "Register.h"
#include <string>

using namespace std;

class ACC : public Register
{

public:
    ACC();
    ACC(string);
};

#endif