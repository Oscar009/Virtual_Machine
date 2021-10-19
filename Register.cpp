#include "Register.h"

Register::Register() {}

Register::Register(string _name) : name(_name) {}

int Register::getValue() { return value; }

void Register::setValue(int newValue) { value = newValue; }

string Register::getName() { return name; }

void Register::setName(string _name) { name = _name; }
