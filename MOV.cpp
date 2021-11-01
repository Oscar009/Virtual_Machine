#include "MOV.h"

MOV::MOV() {}

MOV::MOV(string _name, int _code, int _length, int _value, string _nameOfRegister) : Instruction(_name, _code, _length), value(_value), nameOfRegister(_nameOfRegister) {}

void MOV::setValue(int _value) { value = _value; }

int MOV::getValue() { return value; }

void MOV::setNameOfRegister(string _nameOfRegister) { nameOfRegister = _nameOfRegister; }

string MOV::getNameOfRegister() { return nameOfRegister; }