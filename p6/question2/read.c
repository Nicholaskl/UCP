#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "read.h"

void menu(int argc, char* argv[])
{
    FILE* inFile = fopen(argv[1], "r");

    /* opens file, if error it prints it */
    if(inFile == NULL)
    {
        perror("Error: could not open File1\n");
    }
    else if(ferror(inFile))
    {
        perror("Error reading from File1\n");
    }
    /* if opened without error, print fail lines */
    else
    {
        read(inFile);
    }

    /* if error writing print it */
    if(ferror(inFile))
    {
        perror("Error when reading from File1\n");
    }
    /* otherwise close the file */
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
        /* get and set first part of the line */
        nRead = fscanf(inFile, "%s %d %d:%d:%d %s:",  month, &day, &hour, &min, &sec, process);

        if(nRead != 6)
        {
            done = 1;
        }
        else
        {
            /* get rest of line which is error message */
            fgets(message, 800, inFile);
            if (strstr(message, "fail"))
            {
                /* calculate time since midnight */
                hour *= (60*60);
                min *= 60;
                time = hour + min + sec;
                printf("Time: %d, Message: %s", time, message);
            }
        }
    }
    while(done != 1);
}
