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


int main() {
    int lengthOfTheVector, lengthOfTheWindow;
    scanf("%d", &lengthOfTheVector);
    scanf("%d", &lengthOfTheWindow);

    Vector vec = createVector(lengthOfTheVector);  // Create the vector

    for(int ctr = 0; ctr < lengthOfTheVector; ++ctr) {
        double ele = 0;
        scanf("%lf", &ele);

        if(!appendElement(&vec, (double)ele)) // If the addition of an element fails, then break out of the loop
            break;
    }

    for(int i = 0; i < vec.length; ++i) {
        printf("%lf\n", vec.head[i].data);
    }

    Vector result = poolVector(vec, lengthOfTheWindow);

    for(int i = 0; i < result.length; ++i) {
        printf("%lf\n", result.head[i].data);
    }

    destoryVector(&vec);
    return 0;
}