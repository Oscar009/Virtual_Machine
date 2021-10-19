#ifndef AL_h
#define AL_h

#include "Register.h"
#include <string>

using namespace std;

class AL : public Register
{

public:
    AL();
    AL(string);
};
#endif