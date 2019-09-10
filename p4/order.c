//* Author: Nicholas Klvana-Hooper *//
//* Date last Modified - 10/09/2019 *//
//* Purpose: Methods to sort data given *//

#include <stddef.h>
#include "numbers.h"
#include "order.h"

//* Puts the 2 numbers given into ascending order*//
void ascending2 (int* p1, int* p2)
{
    int temp;

    if (*p1 > *p2)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}

//* Puts the 3 numbers given into ascending order*//
void ascending3 (int* p1, int* p2, int* p3)
{
    ascending2(p2, p3);
    ascending2(p1, p2);
    ascending2(p2, p3);
}

//* Puts the 2 numbers given into descending order*//
void descending2(int* p1, int* p2)
{
    int temp;

    if (*p1 < *p2)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}

//* Puts the 4 numbers given into descending order*//
void descending3(int* p1, int* p2, int* p3)
{
    descending2(p2, p3);
    descending2(p1, p2);
    descending2(p2, p3);
}

//* Returns pointer containing method based on user input *//
//* Either Ascending or Descending *//
void (*order(char letter))(int*, int*, int*)
{
    void (*sortType)(int*, int*, int*);
    switch(letter)
    {
        case 'A':
            sortType = &ascending3;
            break;
        case 'D':
            sortType = &descending3;
            break;
        default:
            sortType = NULL;
    }
    return sortType;
}
