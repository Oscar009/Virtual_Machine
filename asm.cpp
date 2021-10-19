#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    
    register int res;
    __asm("movl $10, %%eax;"
		 "movl	$4, %%ebx;"
		 "subl %%ebx, %%eax;" : "=a" (res) 
    );

    printf("res = %i\n", res);

    register int value1, value2;
    __asm("movl $10, %%eax;"
		 "movl	$4, %%ebx;"
		 "subl %%ebx, %%eax;" : "=a" (res)
    );

    printf("res = %i\n", res);

    return 0;
}