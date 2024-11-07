#include <stdio.h>
#include <math.h>
#define SIZE 5

// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
//     //printf("The values of swapped values are: %d %d\n", *a,*b);
// }



void swap(int arr[], int index1, int index2) 
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int main()
{
    int n, pos1, pos2;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int vector[n];
    int i;

    printf("Enter %d numbers: ",n);

    for(i=0; i<n;i++)
        scanf("%d", &vector[i]);
    int *ptr = vector;
    //int *ptr = &vector[0];

    for(i=0; i<n;i++)
        printf("%d   ", vector[i]);
    printf("\n");

    printf("\nNow with pointers\n");
    for(i=0; i<n;i++)
        printf("%d   ", *(ptr+i));

    printf("\nNow we wil calculate the maximum value\n");

    int max = vector[0];

    for(i=1; i<n; i++)
    {   
        if (vector[i] > max)
            max = vector[i];
    }    

    printf("The maximum value is %d\n", max);


    printf("\nNow we wil calculate the maximum value\n");
    printf("But with pointers\n");
    
    //max = -9999999;
    max = *ptr;
    for(i=1; i<n;i++)
    {
            if (*(ptr+i) > max)
            max = *(ptr+i);
    }
    printf("The maximum value is %d\n", max);
    
    printf("\nNow we weill swap values \n");

    printf("Give me the 2 positions that you want to change: \n");
    scanf("%d %d", &pos1, &pos2);
    
    swap(vector, pos1, pos2);

    printf("\nVeamos los cambios:\n");
    for(i=0; i<n;i++)
        printf("%d   ", vector[i]);
    printf("\n");

    //printf("The numbers swapped are %d %d\n", cat1, cat2);
    

}
