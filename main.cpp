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
#include "Program.h"
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
#include "Instruction.h"
#include "Memory.h"
#include "ProgramLoader.h"
//
#include "START.h"
#include "END.h"
#include "ADD.h"

using namespace std;

int main()
{
    //instancia de maquina virtual
    //registros
    PC programCounter("PC");
    IR instructionRegister("IR");
    MAR memoryAddressRegister("MAR");
    MBR memoryBufferRegister("MBR");
    ACC accumulator("ACC");
    AL aLow("AL");
    AH aHigh("AH");
    BL bLow("BL");
    BH bHigh("BH");
    //arreglo de registros
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
    //Elementos de VirtualMachine
    ALU arithmeticLogicalUnit;
    CU controlUnit;
    Memory memory;
    ProgramLoader programLoader;
    VirtualMachine VM;

    system("clear");
    cout << "----- VIRTUAL MACHINE -----\n\n";
    //Cargar el programa
    cout << "----- INSTRUCTIONS -----\n\n";

    START start("START", 50, 1);
    ADD add("ADD", 80, 3, 40, 10);
    END end("END", 51, 1);

    Program program(3);

    program.addInstruction(&start);
    program.addInstruction(&add);
    program.addInstruction(&end);

    //cout << "Size: " << program.getSize() << endl;

    //mostrar instrucciones
    for (int i = 0; i < program.getSize(); i++)
    {
        Instruction in = program.getInstruction(i);
        if (in.getName() == "START")
        {
            cout << in.getName() << endl;
        }
        else if (in.getName() == "END")
        {
            cout << in.getName() << endl;
        }
        else if (in.getName() == "ADD")
        {

            cout << in.getName() << " ";

            auto *ptr_add = static_cast<ADD *>(&in);
            cout << ptr_add->getOperand1() << ", ";
            cout << ptr_add->getOperand2() << endl;

            /* auto* ptr_add = dynamic_cast<ADD*>(&add);
            cout << ptr_add->getOperand1() << ", ";
            cout << ptr_add->getOperand2() << endl; */
        }
    }

    //machine cycle

    controlUnit.machineCycle(program.getInstructions(), registers);

    cout << "\n\n";

    return 0;
}
