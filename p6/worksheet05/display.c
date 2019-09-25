#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plot.h"

int main(int argc, char* argv[])
{
    int rows, cols, i, j;
    double ch;
    char firstLine[10];
    char* chs;
    char* end;
    char line[500];
    double** array;
    FILE* inFile;

    /* RUN WITH PIPING: ./generate - 15 25 | ./display - */
    /* run with filename or direct output */
    if (strcmp(argv[1], "-") == 0)
    {
        inFile = stdin;
    }
    else
    {
        inFile = fopen(argv[1], "r");
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
        /* takes first line for 2D array size */
        fgets(firstLine, 10, inFile);
        sscanf(firstLine, "%d %d", &rows, &cols);
        fflush(stdin);
        array = (double**)malloc(rows * sizeof(double*));
        for(i = 0; i < rows; i++)
        {
            array[i] = (double*)malloc(cols * sizeof(double*));
        }

        /* Takes values from file and puts them in the array */
        for(i = 0; i < rows; i++)
        {
            fgets(line, 250, inFile);
            chs = strtok(line, " ");
            for(j = 0; j < cols; j++)
            {
                if(chs != NULL)
                {
                  ch = strtod(chs, &end);
                  array[i][j] = ch;
                  chs = strtok(NULL, " ");
                }
            }
        }

        /* passes array to be plotted */
        plot(array, rows, cols);
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
