#include "MAR.h"

MAR::MAR(){}

MAR::MAR(string _name):Register(_name), address(nullptr) {}

void MAR::setAddress(Instruction* in) { address = in; }

Instruction* MAR::getAddress() { return address; }