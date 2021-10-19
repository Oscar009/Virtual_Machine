#ifndef BL_h
#define BL_h

#include "Register.h"
#include <string>

using namespace std;

class BL : public Register
{

public:
    BL();
    BL(string);
};
#endif