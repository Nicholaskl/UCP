#ifndef READ_H
#define READ_H

void menu(int argc, char* argv[]);
void copyByOneChar(FILE* inFile, FILE* outFile);

typedef struct {
    int year;
    int month;
    int day;
    char msg[100];
} Entry;

#endif
