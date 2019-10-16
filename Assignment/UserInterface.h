/*
 * File: UserInterface.h
 * File Created: Friday, 4th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Wednesday, 16th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes method definitions for UserInterface.c
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

/* Normal Text colour definition */
#define CLR "\033[0m"
/* Red text definitions - for error printing */
#define ERRCLR "\033[1;31m"

void mainMenu(int** board, int width, int height, int numMatch);
void printSettings(int width, int height, int numMatch);
void changeSettings(int** board, int* width, int* height, int* numMatch);

#endif
