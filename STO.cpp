#include "STO.h"

STO::STO() {}

STO::STO(string _name, int _code, int _length, int _value) : Instruction(_name, _code, _length), value(_value) {}

void STO::setValue(int _value) { value = _value; }

int STO::getValue() { return value; }