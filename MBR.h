#ifndef MBR_h
#define MBR_h

#include "Register.h"
#include <string>

using namespace std;

class MBR : public Register
{

public:
    MBR();
    MBR(string);
};
#endif