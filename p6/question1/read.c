#include <stdio.h>
#include <string.h>
#include "read.h"

void menu(int argc, char* argv[])
{
    FILE* inFile = fopen(argv[1], "r");
    FILE* outFile = fopen(argv[2], "w");

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
    else if(ferror(outFile))
    {
        perror("Error writing File2\n");
    }
    /* if opened correctly copy file */
    else
    {
        copyByOneChar(inFile, outFile);
    }

    /* if error during copy or writing print error */
    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    else if (ferror(outFile))
    {
        perror("Error when writing from File2\n");
    }
    /* otherwise close both files */
    else
    {
        fclose(inFile);
        fclose(outFile);
    }
}

void copyByOneChar(FILE* inFile, FILE* outFile)
{
    int ch;

    /* reads next character from file one and writes it into second */
    do
    {
        ch = fgetc(inFile);
        if(ch != EOF)
        {
            fputc((char)ch, outFile);
        }
    }
    while(ch != EOF);
}
