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

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

#define EXPECTED_NO_OF_ARGS 2

char *concatenateStrings(char *argv[], const int startIndex, const int endIndex);

int main(int argc, char *argv[]) {
    
    if (argc <= 1) {
        printf("Incorrect number of arguments provided. (Expected: %d or more, Received: \033[31m%d\033[0m) \033[36m[This includes the file name argument]\033[0m\n", EXPECTED_NO_OF_ARGS, argc);
        return 2;
    }

    pid_t pid;

    pid = fork();

    if (pid < 0) {  /* Error occurred */
        perror("Fork Failed");
        return 1;
    } else if (pid == 0) {  /* Child Process */
        // Concatenate all strings from index 1 and beyond
        const int startIndex = 1;
        const int endIndex = argc - 1;
        char *const userCommand = (char *const) concatenateStrings(argv, startIndex, endIndex);

        // printf("\nuserCommand: |%s|\n", userCommand);

        char *const command[] = {
            "/bin/bash",
            "-c",
            userCommand,
            NULL
        };

        execvp(command[0], command);
    } else {  /* Parent Process */
        int status = 0;
        wait(&status);

        if (status == 0) {
            printf("\nParent Process(PID: %d): \033[32mSuccessful\033[0m execution of the program!\n", getpid());
        } else {
            printf("\nParent Process(PID: %d): \033[31mError\033[0m occurred while working with your inputs!\n", getpid());
            printf("\033[36mNOTE: Make sure all the necessary escape sequences you apply are also visible to the program and not just the Shell.\033[0m\n");
            printf("\033[36m\033[1mEXAMPLE:\033[0m \033[36mWhen passing in paths as arguments without any quotes,\033[0m\n");
            printf("\033[36m\t../../Operating\\ Systems\\ Lab/helloworld \033[1m====>\033[0m \033[31mThis is \033[1mINCORRECT!\033[0m\n");
            printf("\033[36m\t../../Operating\\\\ Systems\\\\ Lab/helloworld \033[1m====>\033[0m \033[32mThis is \033[1mCORRECT!\033[0m\n");
        }
    }

    return 0;
}

char *concatenateStrings(char *argv[], const int startIndex, const int endIndex) {
    if (startIndex == endIndex)
        return argv[startIndex];

    int totalStringLength = 0;

    // First get the length of the final concatenated string
    for (int i = startIndex; i <= endIndex; ++i) {
        // Add the number of characters per argument
        totalStringLength += strlen(argv[i]);

        // Add a space or '\0' after the current argument
        ++totalStringLength;
    }

    char *concatenatedString = malloc(sizeof(char) * totalStringLength);
    if (concatenatedString == NULL) {
        perror("Memory allocation for \'concatenateString\' failed!");
        exit(1);
    }

    // Get the length of the first argument
    const int argv_1_Length = strlen(argv[startIndex]);
    // Copy the first argument into concatenatedString
    strncpy(concatenatedString, argv[startIndex], argv_1_Length);
    // Add the '\0' character at the end of the copied string
    concatenatedString[argv_1_Length] = '\0';

    for (int i = startIndex + 1; i <= endIndex; ++i) {
        // Add a space after the previous argument
        strcat(concatenatedString, " ");
        // Concatenate the next argument to concatenatedString
        strncat(concatenatedString, argv[i], strlen(argv[i]));
    }

    return concatenatedString;
}

