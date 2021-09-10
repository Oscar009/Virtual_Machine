#ifndef Instruction_h
#define Instruction_h

class Instruction
{
    int _registro;
    int _address;

public:
    Instruction();

    void setRegistro(int);
    void setAddress(int);
};

#endif