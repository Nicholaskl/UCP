#include "numbers.h"
#include <stdio.h>

void readInts(int* x, int* y, int* z, char* test)
{
    printf("Please enter the first integer\n");
    scanf("%d", x);
   
    printf("Please enter the second integer\n");
    scanf("%d", y);
    
    printf("Please enter the third integer\n");
    scanf("%d", z);

    printf("A for ascending, D for descending\n");
    scanf(" %c", test);
}
