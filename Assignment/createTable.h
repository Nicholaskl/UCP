#ifndef CREATETABLE_H
#define CREATETABLE_H

void readSettings(int argc, char* argv[], int* width, int* height, int* numMatch);
void readFile(FILE* settFile, int* width, int* height, int* numMatch);
void initialiseTable(int** array, int width, int height);
void freeTable();

#endif
