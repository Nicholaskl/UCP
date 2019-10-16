#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "LogFunc.h"

void insertTurn(LinkedList** game, int numTurn, char player, int insertX, int insertY, int gameNum)
{
    gameEntry* gameEnt;

    gameEnt = (gameEntry*)malloc(sizeof(gameEntry));

    gameEnt->gameNum = gameNum;
    gameEnt->turnNum = numTurn;
    gameEnt->player = player;
    gameEnt->xCoord = insertX;
    gameEnt->yCoord = insertY;

    insertLast(*game, gameEnt);
}

void freeLists(LinkedList** gameList)
{
    freeLinkedList(*gameList, &freeGameList);
}

void freeGameList(LListNode* node)
{
    free(node->data);
}

void printList(LListNode* node)
{
    gameEntry* curr = node->data;

    if(curr->turnNum == 1)
    {
        printf("\nGame %d:\n", curr->gameNum);
    }
    printf("   Turn: %d\n", curr->turnNum);
    printf("   Player: %c\n", curr->player);
    printf("   Location: %d,%d\n\n", curr->xCoord, curr->yCoord);
}

void writeList(LListNode* node, FILE* file)
{
    gameEntry* curr = node->data;

    if(curr->turnNum == 1)
    {
        fprintf(file, "\nGame %d:\n", curr->gameNum);
    }
    fprintf(file, "   Turn: %d\n", curr->turnNum);
    fprintf(file, "   Player: %c\n", curr->player);
    fprintf(file, "   Location: %d,%d\n\n", curr->xCoord, curr->yCoord);
}

void saveLog(LinkedList* list, int width, int height, int numMatch)
{
    FILE* file;
    time_t now;
    int hour, min, day, month;
    char fileName[30];
    struct tm *info;
    time(&now);
    info = localtime(&now);


    hour = info->tm_hour;
    min = info->tm_min;
    day = info->tm_mday;
    month = info->tm_mon +1;

    sprintf(fileName, "MNK_%d-%d-%d_%d-%d_%d-%d.log", height, width, numMatch,
            hour, min, day, month);

    file = fopen(fileName, "w");
    if(file == NULL)
    {
        perror("Error opening file");
    }
    else
    {
        fprintf(file, "SETTINGS\n");
        fprintf(file, "   M: %d\n", height);
        fprintf(file, "   N: %d\n", width);
        fprintf(file, "   K: %d\n", numMatch);

        writeLinkedList(list, file, &writeList);

        if(ferror(file))
        {
            perror("Error reaidng from file\n");
        }
        fclose(file);
    }
}
