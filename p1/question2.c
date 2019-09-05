/*
** Program determines if an integer is fully divisible by another. If zero is
** entered as either, program exits, as you cannot divide by 0.
**
** Authour: Nicholas Klvana-Hooper (19782944@curtin.edu.au)
** Date:    31st July 2019
** Modified: Nicholas Klvana-Hooper
** Date:     4th August 2019
*/

#include <stdio.h>

int main (void)
{
    int num1, num2;

    printf("Enter value for 1st number: ");
    scanf("%d", &num1);
    printf("Enter value for 2nd number: ");
    scanf("%d", &num2);

    /* If either number is 0, program would break. so exit*/
    if ((num1 != 0) && (num2 != 0))
    {
        /* Checks to see if the number is divisible */
        if (num1%num2==0)
        {
            printf("divisible");
        }
        else
        {
            printf("not divisible");
        }
    }
    else
    {
        printf("Number cannot be 0! Exiting...");
    }
    return 0;
}
