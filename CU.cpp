#include "CU.h"

CU::CU() {}

CU::CU(string s, ALU _alu) : status(s), alu(_alu) {}

void CU::machineCycle(Instruction **_instructions, Register *registros)
{
    int j = 0;
    //instancia PC
    auto *ptr_PC = static_cast<PC *>(&registros[0]);
    //instancia MAR
    auto *ptr_MAR = static_cast<MAR *>(&registros[2]);
    //instancia IR
    auto *ptr_IR = static_cast<IR *>(&registros[1]);

     for (int i = 0; i < 3; i++)
    {
        cout << "fetch\n";
        //fetch
        //PC apunta a la primera instruccion
        ptr_PC->setAddress(_instructions[i]);
        //PC pasa a la MAR la dirección de la instruction
        ptr_MAR->setAddress(ptr_PC->getAddress());
        //guardar instruccion en el IR
        ptr_IR->setInstruction(ptr_MAR->getAddress());
        //la instruccion siguiente en el fetch aumenta con el indice j
        //Decode
        cout << "Decode\n";
        int code = ptr_IR->getInstruction()->getCode();

        ptr_IR->getInstruction()->display();

        cout << "Execute\n";
        //Execute
        execute(code, ptr_IR->getInstruction());
    }

}

void CU::execute(int _code, Instruction *in)
{

    switch (_code)
    {
    case 50:
        cout << "START" << endl;
        break;
    case 51:
        cout << "END" << endl;
        break;
    case 80:
        cout << "ADD" << endl;
        /* auto* ptr_add = static_cast<ADD*>(in);
        cout << endl << alu.Add(ptr_add->getOperand1(), ptr_add->getOperand2()) << endl; */
        break;
    case 81:
        cout << "DIV" << endl;
        break;
    case 82:
        cout << "MULT" << endl;
        break;
    case 83:
        cout << "DIV" << endl;
        break;
    case 84:
        cout << "MOV" << endl;
        break;
    case 85:
        cout << "STO" << endl;
        break;
    default:
        break;
    }
}