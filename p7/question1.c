#include <stdio.h>

#include "menu.h"

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Error. not enough arguments entered\n");
    }
    else
    {
        menu(argc, argv);
    }
    return 0;
}
