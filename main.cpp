/*
Autor: Oscar Noe Ortiz Barba
*/
//--------------------------
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
//--------------------------
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
#include "MULT.h"
#include "DIV.h"
#include "MOV.h"
#include "STO.h"
#include "REST.h"

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
    CU controlUnit("status", registers, arithmeticLogicalUnit);
    Memory memory;
    ProgramLoader programLoader;
    CPU cpu(registers, arithmeticLogicalUnit, controlUnit);

    system("clear");
    cout << "----- VIRTUAL MACHINE -----\n\n";

    cout << "----- Lexical analyzer -----\n\n";

    

    START *start = new START("START", 50, 1);
    ADD *add = new ADD("ADD", 80, 3, 30, 10);
    MULT *mult = new MULT("MULT", 81, 3, 30, 10);
    DIV *div = new DIV("DIV", 82, 3, 30, 10);
    REST *rest = new REST("REST", 83, 3, 30, 10);
    MOV *mov = new MOV("MOV", 84, 3, 30, "BL");
    //STO *sto = new STO("STO", 85, 3, 30, 10);
    END *end = new END("END", 51, 1);

    Program program(10);

    program.addInstruction(start);
    program.addInstruction(add);
    program.addInstruction(mult);
    program.addInstruction(div);
    program.addInstruction(rest);
    program.addInstruction(mov);
    program.addInstruction(end);

    cpu.machineCycle(&program);

    cout << "\n\n";

    return 0;
}
