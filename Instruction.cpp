#include "Instruction.h"

Instruction::Instruction() {}

void Instruction::setRegistro(int newValue){
    _registro = newValue;
}

void Instruction::setAddress(int newValue){
    _address = newValue;
}