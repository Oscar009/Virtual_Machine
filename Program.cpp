#include "Program.h"

Program::Program(int _length)
{
    size = 0;
    length = _length;
}

void Program::addInstruction(Instruction *newInstruction)
{
    instructions[size++] = newInstruction;
}

Instruction *Program::getInstruction(int index)
{
    return instructions[index];
}

Instruction **Program::getInstructions() { return instructions; }

int Program::getSize() { return size; }