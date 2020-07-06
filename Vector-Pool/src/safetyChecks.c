/*
    This is done to prevent multiple inclusions of the same header file in the project
*/
#ifndef STDIO_H
    #define STDIO_H
    #include <stdio.h>
#endif

#ifndef STDLIB_H
    #define STDLIB_H
    #include <stdlib.h>
#endif

#ifndef TYPES_H
    #define TYPES_H
    #include "types.h"
#endif

#ifndef VECFUNC_H
    #define VECFUNC_H
    #include "vecfunc.h"
#endif


void checkPtr(VectorElement *vec, const char *fileName, const int lineNo, const char *ptrName) {
    if(vec == NULL) {
        printf("Dynamic Memory Allocation Failed!\n");
        printf("File Name.: %s\n", fileName);
        printf("Line No.: %4d\n", lineNo);
        printf("Pointer Name: %s\n", ptrName);
        exit(EXIT_FAILURE);
    }
}