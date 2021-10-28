/*
Autor: Oscar Noe Ortiz Barba
*/
//--------------------------
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
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
//------------------------
#include "START.h"
#include "END.h"
#include "ADD.h"

using namespace std;

void printRegisters(Register[]);

int main(int argc, char *argv[])
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

    START start("START", 50, 1);
    ADD *add = new ADD("ADD", 80, 3, 30, 10);
    END end("END", 51, 1);

    Program program(3);

    program.addInstruction(&start);
    program.addInstruction(add);
    program.addInstruction(&end);

    //registros para machinecyle
    //instancia PC
    auto *ptr_PC = static_cast<PC *>(&registers[0]);
    //instancia MAR
    auto *ptr_MAR = static_cast<MAR *>(&registers[2]);
    //instancia IR
    auto *ptr_IR = static_cast<IR *>(&registers[1]);

    //imprimir instrucciones
    //los registrosimprimirlos vacios



    //machineCycle
    Instruction *in = new Instruction();
    for (int i = 0; i < program.getSize(); i++)
    {
        //fetch
        in = controlUnit.fetch(&program, i);
        //PC apunta a la primera instruccion
        ptr_PC->setAddress(in);
        //PC pasa a la MAR la dirección de la instruction
        ptr_MAR->setAddress(ptr_PC->getAddress());
        //guardar instruccion en el IR
        ptr_IR->setInstruction(ptr_MAR->getAddress());
        registers[4].setValue(registers[4].getValue() + 1);
        printRegisters(registers);

        //decode
        //obtener el codigo a traves del IR
        int code = controlUnit.decode(ptr_IR->getInstruction());
        printRegisters(registers);

        //Execute
        controlUnit.execute(code, ptr_IR->getInstruction());
        printRegisters(registers);
    }

    cout << "\n\n";

    delete[] ptr_PC;

    return 0;
}

void printRegisters(Register r[])
{
    auto *ptr_PC = static_cast<PC *>(&r[0]);
    //instancia MAR
    auto *ptr_MAR = static_cast<MAR *>(&r[2]);
    //instancia IR
    auto *ptr_IR = static_cast<IR *>(&r[1]);
    cout << "\n-----------------------------------------";
    cout << "\nPC: " << ptr_PC->getAddress();
    cout << "\tAL: " << r[5].getValue();
    cout << "\nIR: " << ptr_IR->getInstruction();
    cout << "\tAH: " << r[6].getValue();
    cout << "\nACC: " << r[4].getValue();
    cout << "\t\t\tBL: " << r[7].getValue();
    cout << "\nMAR: " << ptr_MAR->getAddress();
    cout << "\tBH: " << r[8].getValue();
    cout << "\nMBR: " << r[3].getValue();
    cout << "\n-----------------------------------------\n";
}
