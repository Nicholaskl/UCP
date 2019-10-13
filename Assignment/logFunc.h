#ifndef LOGFUNC_H
#define LOGFUNC_H

typedef struct {
    int turnNum;
    char player;
    int xCoord;
    int yCoord;
} gameEntry;

void insertTurn(LinkedList** game, int numTurn, char player, int insertX, int insertY);
void freeLists(LinkedList** logs);
void freeGameList(LListNode* node);
void freeEntry(LListNode* node);

#endif
