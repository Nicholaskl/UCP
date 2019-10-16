/*
 * File: Run.c
 * File Created: Friday, 4th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Wednesday, 16th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Runs program for Tic Tac Toe Game
 */
#include <stdio.h>
#include <stdlib.h>
#include "CreateTable.h"
#include "UserInterface.h"

int main(int argc, char* argv[])
{
    int width;
    int height;
    int numMatch;
    int** board;
    int i;
    width = -1;
    height = -1;
    numMatch = -1;
    board = 0;

    /* Command-Line Arguments are passed to get data from settings file */
    readSettings(argc, argv, &width, &height, &numMatch);

    /* If all data was gathered run rest of program */
    if((width>0) && (height>0) && (numMatch >= 0))
    {
        /* Initalise 2D int array for board */
        board = (int**)malloc(height * sizeof(int*));
        for(i = 0; i < height; i++)
        {
            board[i] = (int*)malloc(width * sizeof(int));
        }

        /* Calls main menu interface that deals with the program */
        mainMenu(board, width, height, numMatch);

        /* Frees the malloc'd table after use */
        freeTable(board, width, height);
    } /* else don't run program */

    return 0;
}
