#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "read.h"

/* TEST CASE PROVIDED. RUN USING ./question1 text new */
/* copies text from 'text' to 'new' */

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Error. not enough arguments entered\n");
    }
    else
    {
        menu(argc, argv);
    }
    return 0;
}
