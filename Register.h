#ifndef Register_h
#define Register_h

#include <string>

using namespace std;

class Register
{
    string name;
    int value;

public:
    Register();
    Register(string);

    int getValue();
    void setValue(int);

    string getName();
    void setName(string);
};

#endif