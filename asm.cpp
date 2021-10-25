#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

      int res;
      int value1 = 10, value2 = 3, rem;
      /* __asm("movl $10, %%eax;"
            "movl	$4, %%ebx;"
            "subl %%ebx, %%eax;"
            : "=a"(res));

      printf("res = %i\n", res);

      __asm("movl $10, %%eax;"
            "movl	$4, %%ebx;"
            "addl %%ebx, %%eax;"
            : "=a"(res));

      printf("add = %i\n", res);

      __asm("movl $10, %%eax;"
            "movl	$4, %%ebx;"
            "imull %%ebx, %%eax;"
            : "=a"(res));

      printf("mult = %i\n", res); */

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