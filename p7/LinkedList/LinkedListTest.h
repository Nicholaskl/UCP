#ifndef LINKEDLISTTEST_H
#define LINKEDLISTTEST_H

typedef struct {
    int year;
    int month;
    int day;
    char msg[100];
} Entry;

void printEntry(LListNode* node);
void freeEntry(LListNode* node);

#endif
