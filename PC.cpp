#include "PC.h"

PC::PC() {}

PC::PC(string _name) : Register(_name), address(nullptr) {}

void PC::setAddress(Instruction* in) { address = in; }

Instruction* PC::getAddress() { return address; }