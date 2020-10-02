/**
 * Name: Rishit Chaudhary
 * SRN: PES1201800316
**/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define EXPECTED_NO_OF_CMDLINE_INPUTS 2
#define EXPECTED_TYPE_OF_CMDLINE_INPUTS "int"
#define TRUE 1
#define FALSE 0


/*
The Fibonacci sequence is the series of numbers 0, 1, 1, 2, 3, 5, 8, ... Write a C program using the fork() system call that generates the Fibonacci sequence in the child process. The number of the sequence should be provided in the command line. For example, if 5 is provided as an input to the program, the first five numbers in the Fibonacci sequence should be output by the child process.
*/


int isNum(char*);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Incorrect number of arguments provided (Expected %d, Received \033[31m%d\033[0m) \033[36m[This counts the file name argument]\033[0m\n", EXPECTED_NO_OF_CMDLINE_INPUTS, argc);
		return 1;
	}
	
	if (!isNum(argv[1])) {
		printf("Incorrect type of argument provided (Expected \033[31m%s\033[0m)\n", EXPECTED_TYPE_OF_CMDLINE_INPUTS);
		return 2;
	}

	pid_t pid;
	
	pid = fork();
	
	if (pid < 0) {  // Error Occurred
		perror("Fork Failed");
		return 1;
	} else if (pid == 0) {  // Child Process
		char * const args[] = {"./q1_child", argv[1], NULL};
		execv((const char *)args[0], args);
	} else {  // Parent Process
		wait(NULL);
	}
	
	
	return 0;
}

int isNum(char *text) {
	for (int i = 0, n = strlen(text); i < n; ++i) {
		if (!isdigit(text[i]))
			return FALSE;
	}
	return TRUE;
}
