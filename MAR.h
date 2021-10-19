#ifndef MAR_h
#define MAR_h

#include "Register.h"
#include <string>

using namespace std;

class MAR : public Register
{

public:
    MAR();
    MAR(string);
};

#endif