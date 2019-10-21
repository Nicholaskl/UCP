/*
 * File: CreateTable.h
 * File Created: Friday, 4th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Wednesday, 16th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes method definitions for CreateTable.c
 */

#ifndef CREATETABLE_H
#define CREATETABLE_H

/* Normal Text colour definition */
#define CLR "\033[0m"
/* Red text definitions - for error printing */
#define ERRCLR "\033[1;31m"

void readSettings(int argc, char* argv[], int* width, int* height, int* numMatch);
void readFile(FILE* settFile, int* width, int* height, int* numMatch);
void freeTable(int** board, int width, int height);

#endif
