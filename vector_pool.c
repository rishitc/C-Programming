#include<stdio.h>
#include<stdlib.h>

int main() {
    int vector_size, window_size, number_of_slides;
    float *vector = NULL, *pooledVector = NULL;
    scanf("%d", &vector_size);
    scanf("%d", &window_size);

    number_of_slides = vector_size - window_size + 1;

    vector = malloc(sizeof(float)*vector_size);
    if(vector == NULL) {
        printf("Falied to allocate %lu bytes of memory!\n", sizeof(int)*vector_size);
        exit(1);
    }

    pooledVector = malloc(sizeof(float)*number_of_slides);
    if(pooledVector == NULL) {
        printf("Falied to allocate %lu bytes of memory!\n", sizeof(int)*number_of_slides);
        exit(1);
    }


    for(int numCount = 0; numCount < vector_size; ++numCount) {
        scanf("%f", &vector[numCount]);
    }

    int sum;
    for(int slideCount = 0; slideCount < number_of_slides; ++slideCount) {
        sum = 0;
        int count = 0;
        for(int numCount = slideCount; numCount < (window_size+slideCount) && numCount < vector_size; ++numCount) {
            sum += vector[numCount];
        }
        pooledVector[slideCount] = sum/count;
    }

    for(int numCount = 0; numCount < number_of_slides; ++numCount) {
        printf("%lf ", (double)pooledVector[numCount]);
    }
    printf("\n");
    return 0;
}