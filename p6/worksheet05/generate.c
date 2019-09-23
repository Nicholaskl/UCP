#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "randomarray.h"

int main(int argc, char* argv[])
{
    FILE* inFile;
    double** array;
    int rows, cols, i, j;

    if (strcmp(argv[1], "-") == 0)
    {
        inFile = stdout;
    }
    else
    {
        inFile = fopen(argv[1], "w");
    }

    if(inFile == NULL)
    {
        perror("Error: could not open File1\n");
    }
    else if(ferror(inFile))
    {
        perror("Error reading from File1\n");
    }

    rows = atoi(argv[2]);
    cols = atoi(argv[3]);

    array = (double**)malloc(rows * sizeof(double*));
    for(i = 0; i < rows; i++)
    {
        array[i] = (double*)malloc(cols * sizeof(double*));
    }

    randomArray(array, rows, cols, 2);

    fprintf(inFile, "%d %d \n", rows, cols);
    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            fprintf(inFile, "%f", array[i][j]);
        }
        fprintf(inFile, "\n");
    }

    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    else
    {
        fclose(inFile);
    }

    free(array);

    return 0;
}

void standardOut(int argc, char* argv[])
{

}
