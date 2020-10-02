/**
 * Name: Rishit Chaudhary
 * SRN: PES1201800316
**/

/*
 Write a C program to demonstrate the use of fork(), exec() and wait() all in one program.
 Use any one of the family of exec system calls such as execl() or execvp().
 Example: If the input/argument to the program is one of these
    ls, ls –l, find, <executable_program>
then your program should display the output of the same command (like the output of “ls –l” command) or 
the executable_program that was passed as an argument.
*/

// This program is the sample executable program  (i.e code for the <executable_program>) for the above question

#include <stdio.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < i; ++j)
            printf("*");
        printf("\n");
    }
    return 0;
}

