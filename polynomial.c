#include <stdio.h>
#include <math.h>
#include "functions.h"


int main()
{
    int option;
    float a,b;
    float x;

    printf("Enter some option \n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("Bisection !\n");
            printf("Give me the initial interval (a and b): \n ");
            scanf("%f %f",&a, &b);
            x = rootBisection(a,b); 
            printf("The root is %.6f: \n ", x);
            break;
        case 2:
            printf("Newton !\n");
            printf("Give me the initial point (x0): \n ");
            scanf("%f",&a);
            x = rootNewton(a);
            printf("The root is %.6f: \n ", x);
            break;
        case 3:
            printf("Secant !\n");
            printf("Give me the initial points (x0 and x1): \n ");
            scanf("%f %f",&a, &b);
            x = rootSecant(a,b); 
            printf("The root is %.6f: \n ", x);
            break;
        default:
            printf("Bad choice ! ");
            break;
    }
}        