#include <stdio.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    //printf("The values of swapped values are: %d %d\n", *a,*b);
}


int main()
{

    int vector[5]:
    int i;

    printf("Enter 5 numbers:")

    for(i=0; i<5;i++)
        scanf("%d ", &vector[i]);

    for(i=0; i<5;i++)
        printf("%d   ", vector[i]);

    //swap(&cat1, &cat2);

    //printf("The numbers swapped are %d %d\n", cat1, cat2);
    

}