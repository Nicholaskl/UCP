#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"

void menu(int argc, char* argv[])
{
    FILE* inFile = fopen("input", "r");
    Entry* ent;
    int size;
    char line[100];

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
        size = fgetc(inFile);
        ent = (Entry*)malloc(sizeof(Entry)*size);

    }

    /* if error during copy or writing print error */
    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    /* otherwise close both files */
    else
    {
        free(ent);
        fclose(inFile);
    }
}

void readJournal(FILE* inFile)
{
    fgets(line, 100, inFile);
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
