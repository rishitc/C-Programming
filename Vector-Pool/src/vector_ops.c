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

#ifndef SAFETYCHECKS_H
    #define SAFETYCHECKS_H
    #include "safetyChecks.h"
#endif

/*
    Creating an empty vector of the required size, specified by arg_count.
    As calloc is being used all variables that have not been assigned a value are
    automatically set to 0.
*/
Vector createVector(int arg_count) {  
    Vector newVector;
    newVector.head = calloc(arg_count, sizeof(VectorElement));  // Allocating memory for the vector elements
    checkPtr(newVector.head, __FILE__, __LINE__ - 1, "newVector.head");  // Checking if the calloc memory allocation was successful or not

    newVector.length = arg_count;  // Storing the number of vector elements in the .length property

    return newVector;
}


/*
    Adds an element at the right end of the vector.
    It returns true if the addition was successful and false if not.
*/
bool appendElement(Vector vec, double element) {
    // If the vector is full
    if(vec.lengthOccupied == vec.length) {
        return false;
    }

    // The lengthOccupied property will always be 1 greater that the index of the last element in the vector
    vec.head[vec.lengthOccupied].data = element;
    ++(vec.lengthOccupied);  // Increment the lenghtOccupied property to reflect the addition of a new element

    return true;
}


/*
    Free the memory pointed to by the head property if it is not NULL
    Set the head property to NULL
    Set the lengthOccupied property to 0
    Set the length property to 0
    Return true of completion
*/
bool destoryVector(Vector *vec) {
    if(vec -> head != NULL)
        free(vec -> head);
    vec -> head = NULL;
    vec -> lengthOccupied = vec -> length = 0;
    return true;
}


/*
    
*/
Vector poolVector(Vector vec, int windowSize) {
    /*
        The number of elements in the result after the pooling operation will the
        ceil of the length of the vector and the window size
        E.g.: If the vector is of length 5 and the window size is 2 then
              there will be 3 elements in the result, 2 got from window size 2 and
              1 will be got from the window size 1
    */
    int numberOfPooledElements = (int)ceil(vec.length / windowSize);
    Vector result = createVector(numberOfPooledElements);  // Create the result vector

    for(int elementCount = 0, sum = 0; elementCount < numberOfPooledElements; ++elementCount, sum = 0) {
        /*
            The START_INDEX is got by multiplying the count for the element in the Pooled result with
            the window size.
            E.g.: The START_INDEX get the values of 0, 2, 4 for a vector of length 5 and window size of 2.
        */
        const int START_INDEX = elementCount * windowSize;

        /*
            The END_INDEX is got by multiplying the count for the element in the Pooled result with
            the value which is one greater than the window size.
            E.g.: The END_INDEX gets the values of 1, 3, 5 for a vector of length 5 and window size of 2.

            For groups that could be incomplete, as in not having enough elements as expected by the window size,
            here, we must also check that we are not exceeding the bounds of the Vector's head array itself.
        */
        const int END_INDEX = (elementCount + 1) * windowSize - 1;

        int sumCount = 0;  // To hold the number of elements in the current window sweep
        for(int ctr = START_INDEX; ctr < vec.length && ctr < END_INDEX + 1; ++ctr, ++sumCount) {
            sum += vec.head[ctr].data;
        }

        appendElement(result, (double)sum / sumCount);
    }

    return result;
}