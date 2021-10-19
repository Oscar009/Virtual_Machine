#include "ALU.h"

ALU::ALU() {}

int ALU::Add(int value1, int value2) { return value1 + value2; }

int ALU::Rest(int value1, int value2) { return value1 + value2; }

int ALU::Mult(int value1, int value2) { return value1 + value2; }

int ALU::Div(int value1, int value2) { return value1 + value2; }

void ALU::Mov(int value, Register* r)
{
    r->setValue(value);
}

void ALU::Sto(int value, Register* r)
{
    r->setValue(value);
}