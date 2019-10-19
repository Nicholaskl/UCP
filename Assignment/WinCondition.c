/*
 * File: LogFunc.c
 * File Created: Thursday, 17th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Saturday, 19th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Checks board to see if a player has won
 */
#include <stdio.h>
#include "WinCondition.h"

/*
 * SUBMODULE: winCondition
 * IMPORT: game(int**), width(int). height(int), numMatch(int), gameEnd(int*)
 * EXPORT: void
 * ASSERTION: Traversals of the board to see if a player has won
 */
void winCondition(int** board, int width, int height, int numMatch, int* gameEnd)
{
    int i;
    int j;
    int numX;
    int numO;

    /* Checks through each row */
    for(i = 0; i < height; i++)
    {
        numX = 0;
        numO = 0;
        /* and then every subsequent column */
        for(j=0; j < width; j++)
        {
            /* Then checks if a win condition has been made */
            checkWin(board, width, height, numMatch, i, j, &numO, &numX, gameEnd);
        }
    }

    /* Checks through each column */
    for(j = 0; j < width; j++)
    {
        numX = 0;
        numO = 0;
        /* and then every subsequent column */
        for(i=0; i < height; i++)
        {
            /* Then checks if a win condition has been made */
            checkWin(board, width, height, numMatch, i, j, &numO, &numX, gameEnd);
        }
    }

    /* Goes through the rows */
    for(i=0; i < height; i++)
    {
        numX = 0;
        numO = 0;
        /* Checks diagonally downwards from the first index of the row */
        for(j = 0; ((i+j)<height) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i+j, j, &numO, &numX, gameEnd);
        }

        numX = 0;
        numO = 0;
        /* Checks diagonally upwards from the first index of the row */
        for(j = 0; ((i-j)>=0) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i-j, j, &numO, &numX, gameEnd);
        }
    }

    /* Goes through the rows */
    for(i=0; i < height; i++)
    {
        numX = 0;
        numO = 0;
        /* Checks diagonally downwards from the last index of the row */
        for(j = 0; ((i+j)<height) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i+j, width-j-1, &numO, &numX, gameEnd);
        }

        numX = 0;
        numO = 0;
        /* Checks diagonally upwards from the last index of the row */
        for(j = 0; ((i-j)>=0) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i-j, width-j-1, &numO, &numX, gameEnd);
        }
    }
}

/*
 * SUBMODULE: checkWin
 * IMPORT: game(int**), width(int). height(int), numMatch(int), i(int), j(int), num(int*), numX(int*), gameEnd(int*)
 * EXPORT: void
 * ASSERTION: Checks board index given and increased the number of them in a row. if not sets to 0
 *            if one of the numbers is equal to the number needed to win, then send gameEnd to true
 */
void checkWin(int** board, int width, int height, int numMatch, int i, int j, int* numO, int* numX, int* gameEnd)
{
    /* If index is a 0 then number of X's in a row is increased and number of O set to 0 */
    if(board[i][j] == 0)
    {
        *numO = 0;
        *numX += 1;
    }
    /* If index is a 1 then number of O's in a row is increased and number of X set to 0 */
    else if(board[i][j] == 1)
    {
        *numX = 0;
        *numO += 1;
    }
    /* Otherwise encountered empty space and therefore nothing in a row now */
    else
    {
        *numO = 0;
        *numX = 0;
    }

    /* If the number of a player in a row matches needed to win then gameEnd should be set to true */
    if((*numO == numMatch) || (*numX == numMatch))
    {
        *gameEnd = 1;
    }

}
