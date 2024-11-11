#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For pow function
#include <cblas.h> // Include the BLAS library

int main() {
    // Define the size of the vectors
    int n = 10; // Example size; you can modify this

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
    printf("Vector x: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", x[i]);
    }
    printf("\n");

    printf("Vector y: ");
    for (int i = 0; i < n; i++) {
        printf("%lf ", y[i]);
    }
    printf("\n");

    // Compute the dot product using BLAS ddot function
    double result = cblas_ddot(n, x, 1, y, 1);

    // Print the result
    printf("Dot product of x and y: %lf\n", result);

    // Free allocated memory
    free(x);
    free(y);

    return 0;
}
