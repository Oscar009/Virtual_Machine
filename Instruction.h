#ifndef Instruction_h
#define Instruction_h

#include <string>
#include <iostream>

using namespace std;

class Instruction
{
    string name;
	short int code;
	short int length;
public:
    Instruction();
    Instruction(string, short int, short int);
    void display();
    int getCode();
    string getName();
};

#endif