#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plot.h"

int main(int argc, char* argv[])
{
    int rows, cols, i, j;
    double assign;
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

    fscanf(inFile, "%d %d", &rows, &cols);
    printf("works");
    array = (double**)malloc(rows * sizeof(double*));
    for(i = 0; i < rows; i++)
    {
        array[i] = (double*)malloc(cols * sizeof(double*));
    }

    for(i = 0; i < rows; i++)
    {
        fgets(line, 250, inFile);
        for(j = 0; j < cols; i++)
        {
            sscanf(line, "%lf ", &assign);
            array[i][j] = assign;
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
