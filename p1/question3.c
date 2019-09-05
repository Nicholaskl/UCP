/*
** Factorial program that finds the factorial of an integer Entered
** until a negative is entered.
**
** Authour: Nicholas Klvana-Hooper (19782944@curtin.edu.au)
** Date:    31st July 2019
** Modified: Nicholas Klvana-Hooper
** Date:     4th August 2019
*/

#include <stdio.h>

/* tells C that a submodule with this type will come up later */
int factorial(int num);

int main(void)
{
    int num;
    int exit;
    exit = 0;

    /* menu to continue program until exit provided */

    while (exit!=1)
    {
        printf("Please enter an integer 0 or above: ");
        scanf("%d", &num);

        /* num cannot be negative. will exit */
        if(num >= 0)
        {
            num = factorial(num);
            printf("result: %d\n", num);
        }
        else
        {
            printf("Entered a negative! Exiting");
            exit=1;
        }
    }
    return 0;
}

/* calculates the factorial */
int factorial(int num)
{
    int i, fact;
    fact = 1;

    /* Calculates the factorial number - multiplying from 1
    to the number entered*/
    for(i=1; i<(num+1); i++)
    {
        fact *= i;
    }

    return fact;
}
