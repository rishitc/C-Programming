#include <stdbool.h>
#include <stdio.h>

// Header files containing the instructions and registers supported by the VM
#include "instructions.h"
#include "registers.h"

// Header file containing the program we have written
#include "program.h"


int ip = 0;  // Instruction pointer for our VM 
int sp = -1; // The stack pointer for our VM
bool running = true;

int stack[256];  // Creating a stack of integers
int registers[NUM_OF_REGISTERS];  // Creating an array of registers

// Fetch function
int fetch() {
	return program[registers[IP]];
}

// Evaluate function
void eval(int instr) {
	switch (instr) {
		case HLT: {
			running = false;
			break;
		} // End of case HLT

		case PSH: {
			++registers[SP];  // Increment the stack pointer to a fresh location
			++registers[IP];  // Increment the instruction pointer to the operand after the instruction
			stack[registers[SP]] = program[registers[IP]];  // Pushing the operand onto the stack
			break;
		} // End of case PSH

		case POP: {
			// Store the value at the top of the stack in val_popped and THEN decrement the stack pointer
			int val_popped = stack[registers[SP]--];

			// Print val_popped
			printf("Popped: %d\n", val_popped);
			
			break;
		} // End of case POP

		case ADD: {
			// First we pop the top of the stack and store it as 'a'
			int a = stack[registers[SP]--];
			// We then pop the top of the stack and store it as 'b'
			int b = stack[registers[SP]--];

			// We then add the result and push it onto the stack
			int result = b + a;
			stack[++registers[SP]] = result;  // Increment the stack pointer to point to a new location and push the result onto the stack
			break;
		} // End of case ADD

		

	}
}

int main() {
	while (running) {
		eval(fetch());
	}
	return 0;
}
