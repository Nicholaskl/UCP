#include "numbers.h"
#include "order.h"

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

void ascending3 (int* p1, int* p2, int* p3)
{
    ascending2(p2, p3);
    ascending2(p1, p2);
    ascending2(p2, p3);    
}

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

void descending3(int* p1, int* p2, int* p3)
{
    descending2(p2, p3);
    descending2(p1, p2);
    descending2(p2, p3);
}
