#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "read.h"

void menu(int argc, char* argv[])
{
    FILE* inFile = fopen(argv[1], "r");

    if(inFile == NULL)
    {
        perror("Error: could not open File1\n");
    }
    else if(ferror(inFile))
    {
        perror("Error reading from File1\n");
    }

    read(inFile);

    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    else
    {
        fclose(inFile);
    }
}

void read(FILE* inFile)
{
    int nRead, day, hour, min, sec, time, done;
    char month[3];
    char process[40];
    char message[800];

    done = 0;

    do
    {
        nRead = fscanf(inFile, "%s %d %d:%d:%d %s:",  month, &day, &hour, &min, &sec, process);

        if(nRead != 6)
        {
            done = 1;
        }
        else
        {
            fgets(message, 800, inFile);
            if (strstr(message, "fail"))
            {
                hour *= (60*60);
                min *= 60;
                time = hour + min + sec;
                printf("Time: %d, Message: %s", time, message);
            }
        }
    }
    while(done != 1);
}
