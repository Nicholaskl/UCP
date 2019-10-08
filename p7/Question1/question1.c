#include <stdio.h>
#include <stdlib.h>

#include "mainMenu.h"

int main(int argc, char* argv[])
{
    /* Makes sure index entered for reading the Entry struct */
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
