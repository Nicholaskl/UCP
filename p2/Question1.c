#include <stdio.h>

int powerTwo();

int main (void) 
{
    int power;
    power = powerTwo();
    printf("result: %d\n", power);
    power= powerTwo();
    printf("result: %d\n", power);
    power = powerTwo();
    printf("results: %d\n", power);
    return 0;
}

int powerTwo()
{
    static int power = 1;
    power *= 2;
    return power;
}
