#include "MULT.h"

MULT::MULT() {}

MULT::MULT(string _name, int _code, int _length, int _theOperand1, int _theOperand2) : Instruction(_name, _code, _length), operand1(_theOperand1), operand2(_theOperand2)
{
}

int MULT::getOperand1() { return operand1; }

int MULT::getOperand2() { return operand2; }