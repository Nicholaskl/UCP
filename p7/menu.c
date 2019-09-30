#include <stdio.h>

#include "read.h"

void main(int argc, char* argv[])
{
    Entry* ent;

    read(argc, argv, ent);

    free(ent);
}
