/*
 * File: LogFunc.c
 * File Created: Sunday, 13th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Saturday, 19th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes methods to deal with the Linked List and logging game/turns data
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"
#include "LogFunc.h"

/*
 * SUBMODULE: insertTurn
 * IMPORT: game(int**), numMatch(int), player(char), insertX(int), insertY(int). gameNum(int)
 * EXPORT: void
 * ASSERTION: Inserts turn data into the game logs
 */
void insertTurn(LinkedList** game, int numTurn, char player, int insertX, int insertY, int gameNum)
{
    /* Creates a gameEntry struct */
    gameEntry* gameEnt;
    gameEnt = (gameEntry*)malloc(sizeof(gameEntry));

    /* Sets struct data to the data from the latest turn */
    gameEnt->gameNum = gameNum;
    gameEnt->turnNum = numTurn;
    gameEnt->player = player;
    gameEnt->xCoord = insertX;
    gameEnt->yCoord = insertY;

    /* Adds the turn node into the game logs */
    insertLast(*game, gameEnt);
}

/*
 * SUBMODULE: freeLists
 * IMPORT: gameList(LinkedList*)
 * EXPORT: void
 * ASSERTION: Function frees the logs linked list given to it
 */
void freeLists(LinkedList** gameList)
{
    freeLinkedList(*gameList, &freeGameList);
}

/*
 * SUBMODULE: freeGameList
 * IMPORT: node(LListNode*)
 * EXPORT: void
 * ASSERTION: Frees what is inside the Linked List Nodes
 */
void freeGameList(LListNode* node)
{
    free(node->data);
}

/*
 * SUBMODULE: printList
 * IMPORT: node(LListNode*)
 * EXPORT: void
 * ASSERTION: Prints the game data within the linked list nodes
 */
void printList(LListNode* node)
{
    /* Get node data as a game Entry Struct */
    gameEntry* curr;
    curr = node->data;

    /* If a new game is encountered print game number*/
    if(curr->turnNum == 1)
    {
        printf("\nGame %d:\n", curr->gameNum);
    }
    /* Print the rest of the turn data */
    printf("   Turn: %d\n", curr->turnNum);
    printf("   Player: %c\n", curr->player);
    printf("   Location: %d,%d\n\n", curr->xCoord, curr->yCoord);
}

/*
 * SUBMODULE: writeList
 * IMPORT: node(LListNode*), file(FILE*)
 * EXPORT: void
 * ASSERTION: Writes the game data from the list nodes into a file that is given to it
 */
void writeList(LListNode* node, FILE* file)
{
    /* Get node data as a game Entry struct */
    gameEntry* curr;
    curr = node->data;

    /* If a new game is encountered, print game number */
    if(curr->turnNum == 1)
    {
        fprintf(file, "\nGame %d:\n", curr->gameNum);
    }
    /* Print turn data */
    fprintf(file, "   Turn: %d\n", curr->turnNum);
    fprintf(file, "   Player: %c\n", curr->player);
    fprintf(file, "   Location: %d,%d\n\n", curr->xCoord, curr->yCoord);
}

/*
 * SUBMODULE: saveLog
 * IMPORT: list(LinkedList*), width(int), height(int), numMatch(int)
 * EXPORT: void
 * ASSERTION: Writes the log linked list to a file with a specified file name
 */
void saveLog(LinkedList* list, int width, int height, int numMatch)
{
    FILE* file;
    int hour, min, day, month;
    char fileName[30];
    /* Gets time data */
    time_t now;
    struct tm *info;
    time(&now);
    info = localtime(&now);

    /* Saves current time into variables */
    hour = info->tm_hour;
    min = info->tm_min;
    day = info->tm_mday;
    month = info->tm_mon +1;

    /* Formats file name and puts it in the fileName string */
    sprintf(fileName, "MNK_%d-%d-%d_%d-%d_%d-%d.log", height, width, numMatch,
            hour, min, day, month);

    /* Opens the file */
    file = fopen(fileName, "w");
    /* If not opened, print error */
    if(file == NULL)
    {
        perror(ERRCLR "Error opening file" CLR);
    }
    /* Otherwise file opened fine */
    else
    {
        /* Print log data and settings */
        fprintf(file, "SETTINGS\n");
        fprintf(file, "   M: %d\n", height);
        fprintf(file, "   N: %d\n", width);
        fprintf(file, "   K: %d\n", numMatch);
        writeLinkedList(list, file, &writeList);

        /* If error in writing file print error */
        if(ferror(file))
        {
            perror(ERRCLR "Error reaidng from file\n" CLR);
        }/* Otherwise no issue */
        fclose(file);
    }
}
