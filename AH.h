#ifndef AH_h
#define AH_h

#include "Register.h"
#include <string>

using namespace std;

class AH : public Register
{

public:
    AH();
    AH(string);
};
#endif