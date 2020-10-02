/**
 * Name: Rishit Chaudhary
 * SRN: PES1201800316
**/

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>


/*
The Fibonacci sequence is the series of numbers 0, 1, 1, 2, 3, 5, 8, ... Write a C program using the fork() system call that generates the Fibonacci sequence in the child process. The number of the sequence should be provided in the command line. For example, if 5 is provided as an input to the program, the first five numbers in the Fibonacci sequence should be output by the child process.
*/

int main(int argc, char *argv[]) {
	int noOfElements = atoi(argv[1]);
	int first = 0;
	int second = 1;
	int temp = -1;
	
	for (int i = 1; i <= noOfElements; ++i) {
		printf("%d", first);
		if (i != noOfElements)
			printf(", ");
		
		temp = first + second;
		first = second;
		second = temp;
	}
	printf("\n");
	return 0;
}

