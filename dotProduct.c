#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For pow function
#include <time.h>
#include <cblas.h>
//#include <cblas.h> // Include the BLAS library

double dotProduct(int n, double x[], double y[])
{
    int i;
    double sum = 0;
    for(i=0; i<n; i++)
    {
        sum = sum + x[i]*y[i];
    }

    return sum;
}



int main(int argc, char *argv[]) 
{
    // Define the size of the vectors
    int n = atoi(argv[1]); 
    printf("The value of n is: %d",n);
    // Allocate memory for vectors x and y
    double* x = (double*)malloc(n * sizeof(double));
    double* y = (double*)malloc(n * sizeof(double));

    if (x == NULL || y == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize vectors x and y
    for (int i = 0; i < n; i++) {
        x[i] = pow(-1, i);       // (-1)^i
        y[i] = pow(-1, i + 1);   // (-1)^(i+1)
    }

    // Print vectors for reference
    // printf("Vector x: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%lf ", x[i]);
    // }
    // printf("\n");

    // printf("Vector y: ");
    // for (int i = 0; i < n; i++) {
    //     printf("%lf ", y[i]);
    // }
    printf("\n");

    clock_t start, end;
    double cpu_time_used;
     
    start = clock();
     /* Do the work. */
     // Compute the dot product 
    double result = dotProduct(n, x, y);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // Print the result
    printf("Dot product of x and y WITHOUT BLAS: %lf\n", result);  
    // print the time
    printf("This task took %f seconds to execute WITHOUT BLAS\n", cpu_time_used);



    start = clock();
    double result2 = cblas_ddot(n, x, 1, y, 1);
    // Print the result
    printf("Dot product of x and y WITH BLAS: %lf\n", result2);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    // print the time
    printf("This task took %f seconds to execute WITH BLAS\n", cpu_time_used);


    // Free allocated memory
    free(x);
    free(y);

    return 0;
}