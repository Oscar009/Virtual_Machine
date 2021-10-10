#include "Program.h"

Program::Program(int _length)
{
    instructions = new Instruction[_length];
    size = 0;
}

void Program::addInstruction(Instruction newInstruction)
{
    instructions[size++] = newInstruction;
}

Instruction Program::getInstruction(int index)
{
    if (index < size && index > -1)
        return instructions[index];
    else
        return Instruction("Instruction no exists", -1, -1);
}

int Program::getSize() { return size; }