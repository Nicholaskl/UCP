#include <stdio.h>
#include <stdlib.h>
#include "createTable.h"

void readSettings(int argc, char* argv[], int* width, int* height, int* numMatch)
{
    FILE* settFile = fopen(argv[1], "r");

    if(settFile == NULL)
    {
        perror("Error: could not open Settings\n");
    }
    else if(ferror(settFile))
    {
        perror("Error reading from Settings\n");
    }
    else
    {
        readFile(settFile, width, height, numMatch);
    }

    if(ferror(settFile))
    {
        perror("Error when reading from Settings\n");
    }
    /* otherwise close both files */
    else
    {
        fclose(settFile);
    }
}

void readFile(FILE* settFile, int* width, int* height, int* numMatch)
{
    char line[5];
    int value;
    char setting;
    int i;

    i = 0;
    do
    {
        fgets(line, 5, settFile);
        sscanf(line, "%c=%d", &setting, &value);

        if(setting == 'M')
        {
            *width = value;
        }
        else if(setting == 'N')
        {
            *height = value;
        }
        else if(setting == 'K')
        {
            *numMatch = value;
        }
        else
        {
            printf("Error in Setting layout");
        }
        i++;
    }
    while(i < 4);
}

void initialiseTable(int** array, int width, int height)
{
    int i;

    array = (int**)malloc(height * sizeof(int*));
    for(i = 0; i < height; i++)
    {
        array[i] = (int*)malloc(width * sizeof(int*));
    }
}

void freeTable(int** array, int width, int height)
{
    int i;
    int j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            free(array[i][j]);
        }
    }

    free(array);
}
