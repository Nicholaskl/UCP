#ifndef LOGFUNC_H
#define LOGFUNC_H

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
