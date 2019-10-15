#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "logFunc.h"

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
    printf("  Turn: %d\n", curr->turnNum);
    printf("  Player: %c\n", curr->player);
    printf("  Location: %d,%d\n\n", curr->xCoord, curr->yCoord);
}
