#include "VirtualMachine.h"

VirtualMachine::VirtualMachine() {}

VirtualMachine::VirtualMachine(Register *r, ALU alu, CU cu)
{
    _registers = r;
    _arithmeticLogicalUnit = alu;
    _controlUnit = cu;

    for (int i = 0; i < 9; i++)
        _registers[i].setValue(0);
}

VirtualMachine::~VirtualMachine() {}

void VirtualMachine::showRegisters()
{
    cout << "PC:  " << _registers[0].getValue() << "\t";
    cout << "AL:  " << _registers[5].getValue() << "\n";
    cout << "IR:  " << _registers[1].getValue() << "\t";
    cout << "AH:  " << _registers[6].getValue() << "\n";
    cout << "ACC: " << _registers[2].getValue() << "\t";
    cout << "BL:  " << _registers[7].getValue() << "\n";
    cout << "MAR: " << _registers[3].getValue() << "\t";
    cout << "BH:  " << _registers[8].getValue() << "\n";
    cout << "MBR: " << _registers[4].getValue();
   
}