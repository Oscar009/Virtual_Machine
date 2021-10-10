#include "Instruction.h"

Instruction::Instruction() {}

Instruction::Instruction(string _name, short int _code, short int _length) : name(_name), code(_code), length(_length) {}

void Instruction::display()
{
    cout << name << ", " << code << ", " << length << endl;
}

int Instruction::getCode()
{
    return code;
}

string Instruction::getName()
{
    return name;
}