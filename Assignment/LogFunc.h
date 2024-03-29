/*
 * File: LogFunc.h
 * File Created: Sunday, 13th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Saturday, 19th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes method definitions for LogFunc.c
 */

#ifndef LOGFUNC_H
#define LOGFUNC_H

/* Normal Text colour definition */
#define CLR "\033[0m"
/* Red text definitions - for error printing */
#define ERRCLR "\033[1;31m"

/* Game Node Struct defintion
*  Used for putting game/turn data for logging*/
typedef struct {
    int gameNum;
    int turnNum;
    char player;
    int xCoord;
    int yCoord;
} gameEntry;

void insertTurn(LinkedList** game, int numTurn, char player, int insertX, int insertY, int gameNum);
void freeLists(LinkedList** gameList);
void freeGameList(LListNode* node);
void printList(LListNode* node);
void writeList(LListNode* node, FILE* file);
void saveLog(LinkedList* list, int width, int height, int numMatch);

#endif
