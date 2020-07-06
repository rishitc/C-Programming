/**
 * This program was derived from the NPTEL course on GPU Architectures and Programming,
 * Week 0 Programming Assignment, after many modifications and bug fixes, regarding the
 * evaluation of expressions according to the order of precedence and memory management issues
 * in the original code.
 * 
 * All the code written in the other files and folders were made to mimic the below code,
 * but by taking a different approach with test-driven development, with makefiles to
 * ease the process of writing multiple files for the program, to separate all the code 
 * into more understandable pieces.
 * 
 * My code has not copied any of the functions or lines of code from this program.
 * My code has been tested against the below program for verfication of output.
 * 
 * This code is not compiled or linked during the running of the Makefile.
 * This program is completely isolated from the rest of the code.
 * 
 * The best way to compile and run this program is by running the following commands:
 * $ gcc -g -o ./bin/basic_solution basic_solution.c
 * $ ./bin/basic_solution
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t=1,n,k;
	while(t--)
	{
        scanf("%d%d",&n,&k);
        double *A = malloc(n*sizeof(double));

        int size_b = n/k + ((n%k)?1:0);
        double *B = malloc(size_b*sizeof(double));

        for(int i=0;i<n;i++)
            scanf("%lf", &A[i]);

        int counter = 0;
        for(int i=0;i<n;i+=k)
        {
            double sum=0.0;
            int num_elems = 0;
            
            for(int j=0;j<k && i+j<n;j++)
            {
                sum+=A[i+j];
                num_elems++;
            }
            sum=sum/num_elems;
            if(counter < size_b)
                B[counter]=sum;
            counter++;
        }

        for(int j=0;j<counter;j++)
            printf("%.6lf ",B[j]);
        printf("\n");

        free(A);
        free(B);		
	}
}