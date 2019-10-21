/*
 * File: WinCondition.h
 * File Created: Thursday, 17th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Saturday, 19th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes method definitions for WinCondition.c
 */

#ifndef WINCONDITION_H
#define WINCONDITION_H

void winCondition(int** board, int width, int height, int numMatch, int* gameEnd);
void checkWin(int** board, int width, int height, int numMatch, int i, int j, int* numO, int* numX, int* gameEnd);

#endif
