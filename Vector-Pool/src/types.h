/*
    This struct is used to create an element of the vector
*/
typedef struct {
    double data;  // Holds the data value of the vector element
} VectorElement;


/*
    This struct is used to create a vector
*/
typedef struct {
    VectorElement *head;  // Points to the elements array of the vector
    int lengthOccupied;   // Stores the length of the vector occupied
    int length;           // Stores the length of the vector
} Vector;