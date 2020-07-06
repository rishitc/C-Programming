/*
    This is done to prevent multiple inclusions of the same header file in the project
*/
#ifndef STDBOOL_H
    #define STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef TYPES_H
    #define TYPES_H
    #include "types.h"
#endif


Vector createVector(const int arg_count);  // vector_ops.c
bool appendElement(Vector *vec, const double element);  // vector_ops.c
bool destoryVector(Vector *vec);  // vector_ops.c
Vector poolVector(Vector vec, const int windowSize);  // vector_ops.c
void checkPtr(VectorElement *vec, const char *fileName, const int lineNo, const char *ptrName);  // safetyChecks.c