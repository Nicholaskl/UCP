#ifndef READ_H
#define READ_H

typedef struct {
    int year;
    int month;
    int day;
    char msg[100];
} Entry;

void menu(int argc, char* argv[]);
void readJournal(FILE* inFile, int size, Entry* ent);
void copyByOneChar(FILE* inFile, FILE* outFile);

#endif
