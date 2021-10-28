#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

      int res;
      int value1 = 30, value2 = 10, rem;

      __asm("addl %%ebx, %%eax;"
            : "=a"(res)
            : "a"(value1), "b"(value2));
      printf("\nadd = %i\n", res);

      __asm("subl %%ebx, %%eax;"
            : "=a"(res)
            : "a"(value1), "b"(value2));
      printf("sub = %i\n", res);
      
      __asm("imull %%ebx, %%eax;"
            : "=a"(res)
            : "a"(value1), "b"(value2));
      printf("mult = %i\n", res);

      __asm("movl $0x0, %%edx;"
            "movl %2, %%eax;"
            "movl %3, %%ebx;"
            "idivl %%ebx;"
            : "=a"(res), "=d"(rem)
            : "g"(value1), "g"(value2));

      printf("div = %i\n\n", res);

      return 0;
}