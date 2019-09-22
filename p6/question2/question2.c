#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "read.h"

/* TEST CASE PROVIDED. RUN USING ./question2 logfile */
/* gets errors consisting of fail */

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
