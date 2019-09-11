/* Author: Nicholas Klvana-Hooper */
/* Date last Modified - 10/09/2019 */
/* Purpose: Program to do basic ascending/descending sorts */

#include <stdio.h>
#include <stddef.h>
#include "order.h"
#include "user_input.h"

int main (void)
{
    int var1 = 0;
    int var2 = 0;
    int var3 = 0;
    char var4 = 'c';
    int* x;
    int* y;
    int* z;
    char* test;
    void (*ordPointer)(int*, int*, int*);

    x = &var1;
    y = &var2;
    z = &var3;
    test = &var4;

    /* Passes values to be assigned values by user  */
    readInts(x, y, z, test);

    /* Gets method based on User input and gives it the values needed */
    ordPointer = order(*test);
    (*ordPointer)(x, y, z);

    printf("first number is: %d\n", *x);
    printf("second number is: %d\n", *y);
    printf("third number is: %d\n", *z);

    return 0;
}
