#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mainMenu.h"

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
        /* index for printing array */
        index = atoi(argv[1]);
        /* gets first line of file which has size of struct array */
        size = fgetc(inFile);

        /* creates an entry array with size specified */
        ent = (Entry*)malloc(sizeof(Entry)*size);
        /* reads file into array */
        readJournal(inFile, size, ent);
        /* prints specified struct */
        printf("%d-%d-%d: %s", ent[index].year, ent[index].month, ent[index].day, ent[index].msg);


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

    /* puts details in array of structs */
    for(ii=0; ii < size; ii++)
    {
        /* put all details except message in struct */
        fscanf(inFile, "%d/%d/%d\n", &ent[ii].day, &ent[ii].month, &ent[ii].year);
        /* put message in struct */
        fgets(ent[ii].msg, 100, inFile);
    }

}
