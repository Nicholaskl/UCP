#ifndef READ_H
#define READ_H

void readMenu();
int getSize(FILE* inFile);

typedef struct {
    int year;
    int month;
    int day;
    char msg[100];
} Entry;

#endif
