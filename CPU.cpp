#include "CPU.h"

CPU::CPU() {}

CPU::CPU(Register *_r, ALU _alu, CU _cu) : alu(_alu), cu(_cu)
{
    rcpu = _r;
    printRegisters();
    for (int i = 0; i < 9; i++)
        rcpu[i].setValue(0);
}

CPU::~CPU() { delete[] rcpu; }

void CPU::machineCycle(Program *program)
{

    //registros para machinecyle
    //instancia PC
    auto *ptr_PC = static_cast<PC *>(&rcpu[0]);
    //instancia MAR
    auto *ptr_MAR = static_cast<MAR *>(&rcpu[2]);
    //instancia IR
    auto *ptr_IR = static_cast<IR *>(&rcpu[1]);
    //instancia MBR
    auto *ptr_MBR = static_cast<MBR *>(&rcpu[3]);
    //registro de ayuda
    Register *auxAcc = new Register();

    //machineCycle
    Instruction *in = new Instruction();
    Instruction *aux = new Instruction();
    for (int i = 0; i < program->getSize(); i++)
    {
        //fetch
        in = cu.fetch(program, i, 1);
        //PC apunta a la primera instruccion
        ptr_PC->setAddress(in);
        //PC pasa a la MAR la dirección de la instruction
        ptr_MAR->setAddress(ptr_PC->getAddress());
        //MBR
        ptr_MBR->setValue(ptr_PC->getValue());
        //guardar instruccion en el IR
        ptr_IR->setInstruction(ptr_MAR->getAddress());
        printRegisters();

        //decode
        //obtener el codigo a traves del IR
        aux = cu.fetch(program, i + 1, 0);
        ptr_PC->setAddress(aux);
        int code = cu.decode(ptr_IR->getInstruction());
        printRegisters();

        //Execute
        auxAcc = cu.execute(code, ptr_IR->getInstruction());
        if (in->getName() == "MOV")
        {
            //instancia MOV
            auto *ptr_mov = static_cast<MOV *>(in);

            if (ptr_mov->getNameOfRegister() == "AL")
            {
                rcpu[5].setValue(ptr_mov->getValue());
            }
            else if (ptr_mov->getNameOfRegister() == "AH")
            {
                rcpu[6].setValue(ptr_mov->getValue());
            }
            else if (ptr_mov->getNameOfRegister() == "BL")
            {
                rcpu[7].setValue(ptr_mov->getValue());
            }
            else if (ptr_mov->getNameOfRegister() == "BH")
            {
                rcpu[8].setValue(ptr_mov->getValue());
            }
        }
        else if (in->getName() == "STO")
        {
            //instancia STO
            //auto *ptr_sto = static_cast<STO *>(in);
        }
        else
        {
            rcpu[4].setValue(auxAcc->getValue());
        }
        printRegisters();
    }
}

void CPU::printRegisters()
{
    auto *ptr_PC = static_cast<PC *>(&rcpu[0]);
    //instancia MAR
    auto *ptr_MAR = static_cast<MAR *>(&rcpu[2]);
    //instancia IR
    auto *ptr_IR = static_cast<IR *>(&rcpu[1]);
    cout << "\n-----------------------------------------";
    cout << "\nPC: " << ptr_PC->getAddress();
    cout << "\t\tAL: " << rcpu[5].getValue();
    cout << "\nIR: " << ptr_IR->getInstruction();
    cout << "\tAH: " << rcpu[6].getValue();
    cout << "\nACC: " << rcpu[4].getValue();
    cout << "\t\t\tBL: " << rcpu[7].getValue();
    cout << "\nMAR: " << ptr_MAR->getAddress();
    cout << "\tBH: " << rcpu[8].getValue();
    cout << "\nMBR: " << rcpu[3].getValue();
    cout << "\n-----------------------------------------\n";
}