#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "randomarray.h"

int main(int argc, char* argv[])
{
    FILE* inFile;
    double** array;
    int rows, cols, i, j;

    /* RUN WITH PIPING: ./generate - 15 25 | ./display - */
    /* run with filename or direct output */
    if (strcmp(argv[1], "-") == 0)
    {
        inFile = stdout;
    }
    else
    {
        inFile = fopen(argv[1], "w");
    }

    /* Print error if error occurs on open */
    if(inFile == NULL)
    {
        perror("Error: could not open File1\n");
    }
    else if(ferror(inFile))
    {
        perror("Error reading from File1\n");
    }
    else
    {
        /* Creates an array given command line values */
        rows = atoi(argv[2]);
        cols = atoi(argv[3]);
        array = (double**)malloc(rows * sizeof(double*));
        for(i = 0; i < rows; i++)
        {
            array[i] = (double*)malloc(cols * sizeof(double*));
        }

        /* passes array to be filled with random values */
        randomArray(array, rows, cols, 2);

        /* writes the array to a file with size on first line */
        fprintf(inFile, "%d %d \n", rows, cols);
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                fprintf(inFile, "%f", array[i][j]);
            }
            fprintf(inFile, "\n");
        }
    }

    /* if error happens in writing print it */
    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    /* otherwise close the file */
    else
    {
        fclose(inFile);
    }

    free(array);

    return 0;
}
