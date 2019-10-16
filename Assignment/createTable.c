#include <stdio.h>
#include <stdlib.h>
#include "createTable.h"

void readSettings(int argc, char* argv[], int* width, int* height, int* numMatch)
{
    FILE* settFile = fopen(argv[1], "r");

    if(settFile == NULL)
    {
        perror("Error: could not open Settings File\n");
    }
    else
    {
        readFile(settFile, width, height, numMatch);

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
            *height = value;
        }
        else if(setting == 'N')
        {
            *width = value;
        }
        else if(setting == 'K')
        {
            *numMatch = value;
        }
        else
        {
            printf("Wrong character found in Settings\n");
        }
        i++;
    }
    while(i < 4);

    if(*height <= 0)
    {
        printf("Error with height (M) value (could be missing)\n");
    }
    if(*width <= 0)
    {
        printf("Error with width (N) value (could be missing)\n");
    }
    if(*numMatch < 0)
    {
        printf("Error with number match (K) value (could be missing)\n");
    }
}

void freeTable(int** board, int width, int height)
{
    int i;

    for(i = 0; i < height; i++)
    {
        free(board[i]);
    }

    free(board);
}
