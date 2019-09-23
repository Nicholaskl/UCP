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
    FILE* inFile = fopen(argv[1], "r");

    if(inFile == NULL)
    {
        perror("Error: could not open File1\n");
    }
    else if(ferror(inFile))
    {
        perror("Error reading from File1\n");
    }


    fgets(firstLine, 10, inFile);
    sscanf(firstLine, "%d %d", &rows, &cols);
    fflush(stdin);
    array = (double**)malloc(rows * sizeof(double*));
    for(i = 0; i < rows; i++)
    {
        array[i] = (double*)malloc(cols * sizeof(double*));
    }

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

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
        {
            printf("%f \n", array[i][j]);
        }
    }

    plot(array, rows, cols);

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
