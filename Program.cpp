#include "Program.h"

Program::Program(int _length)
{
    instructions = new Instruction*[_length];
    for (int i = 0; i < _length; i++) {
		instructions[i] = new Instruction[_length];
	}
    size = 0;
    length = _length;
}

Program::~Program()
{
    for (int i = 0; i < length; i++) {
		delete[] instructions[i];
	}
	delete[] instructions;
}

void Program::addInstruction(Instruction *newInstruction)
{
    instructions[size++] = newInstruction;
}

Instruction *Program::getInstruction(int index)
{
    return instructions[index];
}

int Program::getSize() { return size; }