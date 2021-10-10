#include "ADD.h"

ADD::ADD() {}

ADD::ADD(string _name, int _code, int _length, int _theOperand1, int _theOperand2) : Instruction(_name, _code, _length), operand1(_theOperand1), operand2(_theOperand2)
{
}

int ADD::getOperand1() { return operand1; }

int ADD::getOperand2() { return operand2; }