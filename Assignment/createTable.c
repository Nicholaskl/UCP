#include <stdio.h>
#include "createTable.h"

void makeTable(int argc, char* argv[])
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
        /* CODE HERE */
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

void readFile(FILE* settFile)
{
    char line[5];

    fgets(line, 5, settFile);
    sscanf(line, "%c=%d", &char, &value)
}

void initialiseTable()
{

}

void freeTable()
{
    /* FOR FREEING THE TABLE MALLOCS */
}
