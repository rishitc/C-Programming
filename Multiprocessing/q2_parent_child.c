/**
 * Name: Rishit Chaudhary
 * SRN: PES1201800316
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


/*
Write a C program that uses the child to compute partial sums and parent to compute the partial products of an array of integers.
Both child and parent should print the respective total sum and product values. Use an array with a minimum of 5 elements.
*/


int main(int argc, char *argv[]) {
	int count;
	char buf[200] = {};
	pid_t pid;
	
	printf("Enter the size of the array: \033[36m\033[1m(Minimum size of 5)\033[0m\n");
	scanf("%d", &count);
	if (count < 5) {
		printf("Invalid input for \"size of the array\". (Expected: 5 or more, Received: \033[31m%d\033[0m)\n", count);
		return 1;	
	}
	
	int *testArr = malloc(sizeof(int) * count);
	if (testArr == NULL) {
		perror("Memory allocation for \'testArr\' failed!");
        	return 2;
	}
	
	printf("Enter the %d elements of the array:\n", count);
	for (int i = 0; i < count; ++i)
		scanf("%d", &testArr[i]);
	
	printf("The elements of the array are: {");
	for (int i = 0, n = count; i < n; ++i) {
		printf("%d", testArr[i]);
		if (i != n - 1)
			printf(", ");
	}
	printf("}\n");
	
	pid = fork();
	
	if (pid < 0) {  // Error Occurred
		perror("Fork Failed");
		return 1;
	} else if (pid == 0) {  // Child Process
		int sum = 0;
				
		for (int i = 0, n = count; i < n; ++i) {
			sum += testArr[i];
		}
		sprintf(buf, "The total sum calculated in the \033[34m\033[1mChild process\033[0m (pid: %d) = %d\n", getpid(), sum);
		write(1, buf, strlen(buf));
		
		free(testArr);
	} else {  // Parent Process
		int product = 1;
				
		for (int i = 0, n = count; i < n; ++i) {
			product *= testArr[i];
		}
		wait(NULL);
		sprintf(buf, "The total product calculated in the \033[95m\033[1mParent process\033[0m (pid: %d) = %d\n", getpid(), product);
		write(1, buf, strlen(buf));
		
		free(testArr);
	}
	
	
	return 0;
}

