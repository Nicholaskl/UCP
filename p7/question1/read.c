#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read.h"

void readMenu()
{
    FILE* inFile = fopen("input", "r");
    int size;

    /* open both files */
    /* if error opening, print error */
    if(inFile == NULL)
    {
        perror("Error: could not open File1\n");
    }
    else if(ferror(inFile))
    {
        perror("Error reading from File1\n");
    }
    /* if opened correctly copy file */
    else
    {
        size = getSize(inFile, outFile);
        ent = (Entry*)malloc(sizeof(size*Entry));
    }

    /* if error during copy or writing print error */
    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    /* otherwise close both files */
    else
    {
        fclose(inFile);
    }
}

int getSize(FILE* inFile)
{
    int size;

    /* reads next character from file one and writes it into second */
    size = fgetc(inFile);
}
