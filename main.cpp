/*
Autor: Oscar Noe Ortiz Barba
*/
//--------------------------
#include <iostream>
#include <string>
//--------------------------
#include "VirtualMachine.h"
#include "CPU.h"
#include "Memory.h"
#include "ProgramLoader.h"
#include "ALU.h"
#include "CU.h"
#include "Register.h"
#include "PC.h"
#include "IR.h"
#include "MAR.h"
#include "MBR.h"
#include "ACC.h"
#include "AL.h"
#include "AH.h"
#include "BL.h"
#include "BH.h"

using namespace std;

int main()
{
    system("clear");
    cout << "----- VIRTUAL MACHINE -----\n\n";
    cout << "----- INSTRUCTIONS -----\n\n";

    string *instructions = new string[3];

    instructions[0] = "START";
    instructions[1] = "ADD 5, 6";
    instructions[2] = "END";

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". " << instructions[i] << endl;
    }

    //instancia de maquina virtual
    PC programCounter;
    IR instructionRegister;
    MAR memoryAddressRegister;
    MBR memoryBufferRegister;
    ACC accumulator;
    AL aLow;
    AH aHigh;
    BL bLow;
    BH bHigh;
    Register registers[] = {
        programCounter,
        instructionRegister,
        memoryAddressRegister,
        memoryBufferRegister,
        accumulator,
        aLow,
        aHigh,
        bLow,
        bHigh};
    ALU arithmeticLogicalUnit;
    CU controlUnit;
    VirtualMachine VM(registers, arithmeticLogicalUnit, controlUnit);

    //mostrar registros

    cout << "----- Registros -----\n\n";
    VM.showRegisters();

    cout << "\n\n";

    delete[] instructions;
    return 0;
}
