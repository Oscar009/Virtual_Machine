#include "ALU.h"

ALU::ALU() {}

int ALU::Add(int value1, int value2)
{
    int res;

    __asm("addl %%ebx, %%eax;"
          : "=a"(res)
          : "a"(value1), "b"(value2));

    return res;
}

int ALU::Rest(int value1, int value2)
{
    int res;

    __asm("subl %%ebx, %%eax;"
          : "=a"(res)
          : "a"(value1), "b"(value2));

    return res;
}

int ALU::Mult(int value1, int value2)
{
    int res;

    __asm("imull %%ebx, %%eax;"
          : "=a"(res)
          : "a"(value1), "b"(value2));

    return res;
}

int ALU::Div(int value1, int value2)
{
    int res;

    __asm("movl $0x0, %%edx;"
          "movl %2, %%eax;"
          "movl %3, %%ebx;"
          "idivl %%ebx;"
          : "=a"(res), "=d"(rem)
          : "g"(value1), "g"(value2));

    return res;
}

void ALU::Mov(int value, Register *r)
{
    r->setValue(value);
}

void ALU::Sto(int value, Register *r)
{
    r->setValue(value);
}