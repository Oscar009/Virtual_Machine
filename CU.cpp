#include "CU.h"

CU::CU() {}

CU::CU(string s, ALU _alu) : status(s), alu(_alu) {}

Instruction *CU::fetch(Program *program, int index)
{
    setStatus("Fetch");
    displayStatus();
    return program->getInstruction(index);
}

int CU::decode(Instruction *in)
{
    setStatus("Decode");
    displayStatus();
    return in->getCode();
}

void CU::execute(int _code, Instruction *in)
{
    setStatus("Execute");
    displayStatus();
    switch (_code)
    {
    case 50:
        cout << "START" << endl;
        break;
    case 51:
        cout << "END" << endl;
        break;
    case 80:
    {
        cout << in->getName();
        auto *ptr_add = static_cast<ADD *>(in);
        cout << " " << ptr_add->getOperand1() << ", ";
        cout << ptr_add->getOperand2() << endl;
        alu.Add(ptr_add->getOperand1(), ptr_add->getOperand1());
    }
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

void CU::setStatus(string _status){
    status = _status;
}
    
void CU::displayStatus(){ 
    cout << "\n" << status << "\n";
}