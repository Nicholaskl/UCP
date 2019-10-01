#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "read.h"

void menu(int argc, char* argv[])
{
    FILE* inFile = fopen("input", "r");
    Entry* ent;
    int size;
    int index;

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
        index = atoi(argv[1]);
        size = fgetc(inFile);

        ent = (Entry*)malloc(sizeof(Entry)*size);
        readJournal(inFile, size, ent);
        printf("%d-%d-%d: %s\n", ent[index].year, ent[index].month, ent[index].day, ent[index].msg);


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

void readJournal(FILE* inFile, int size, Entry* ent)
{
    int ii;

    for(ii=0; ii < size; ii++)
    {
        fscanf(inFile, "%d/%d/%d\n", &ent[ii].day, &ent[ii].month, &ent[ii].year);
        fgets(ent[ii].msg, 100, inFile);
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
