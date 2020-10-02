/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("Hello World\n");
    printf("%d\n", getpid());
        printf("%d\n", getppid());
    printf("%d\n", getuid());

    return 0;
}

