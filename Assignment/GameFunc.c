/*
 * File: GameFunc.c
 * File Created: Friday, 4th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Saturday, 19th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Contains functions that allows the game to be played (games, turns and winning)
 */
#include <stdio.h>
#include "LinkedList.h"
#include "GameFunc.h"
#include "LogFunc.h"
#include "WinCondition.h"

/*
 * SUBMODULE: newGame
 * IMPORT: board(int**), width(int), height(int), numMatch(int), gameLog(LinkedList*)
 * EXPORT: void
 * ASSERTION: Starts a new game of Tic Tac Toe, finishing when a player wins
 */
void newGame(int** board, int width, int height, int numMatch, LinkedList** gameLog)
{
    static int gameNum;
    int i;
    int j;
    int gameEnd;
    int turnCount;
    gameNum = 1;
    gameEnd = 0;
    turnCount = 1;

    /* Initalises the board array as full of -1 (non-valid user entries) */
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            board[i][j] = -1;
        }
    }

    /* Displays board to user to then place their turns in */
    displayBoard(board, width, height);
    do
    {
        /* Keep creating new turns until a player wins */
        newTurn(board, gameLog, width, height, turnCount, gameNum);
        winCondition(board, width, height, numMatch, &gameEnd);
        turnCount++;
    }
    while (gameEnd != 1); /* Stops when playe has won */

    /* Displays player that has won with player colour */
    if ((turnCount-1)%2 == 0)
    {
        printf(GRN "^*^*^*^*^*^*^*^*^*^*\n");
        printf("   Player X wins!\n");
        printf("^*^*^*^*^*^*^*^*^*^*\n" CLR);
    }
    else
    {
        printf(YLLW "^*^*^*^*^*^*^*^*^*^*\n");
        printf("   Player O wins!\n");
        printf("^*^*^*^*^*^*^*^*^*^*\n" CLR);
    }
    gameNum++; /* Increases number of games made to */
} /* End Game */

/*
 * SUBMODULE: displayBoard
 * IMPORT: board(int**), width(int), height(int)
 * EXPORT: void
 * ASSERTION: Takes in the board and displays it to the user
 */
void displayBoard(int** board, int width, int height)
{
    int i;
    int j;
    int curr;

    /* Prints top part of board onto a clear screen */
    printf("\033[2J");
    printTopBottom(width);

    /* Prints board characters dependent on what player has placed their turn */
    for(i = 0; i < height; i++)
    {
        /* Prints new row */
        printf("  *");
        for(j = 0; j < width; j++)
        {
            /* Now prints each column of array with dividing board lines */
            curr = board[i][j];
            if(j!=0)
            {
                printf("|");
            }

            if (curr == -1)
            {
                printf("   ");
            }
            /* 1 is equal to player 0 */
            else if(curr == 1)
            {
                printf(YLLW " O " CLR);
            }
            /* X is equal to player X */
            else if(curr == 0)
            {
                printf(GRN " X " CLR);
            }
        }
        printf("*\n"); /* Print end of row */
    }
    printTopBottom(width); /* print bottom of board */
} /* Finished printing board */

/*
 * SUBMODULE: printTopBottom
 * IMPORT: width(int)
 * EXPORT: void
 * ASSERTION: The top and bottom of the board have special formatting, printed by this function
 */
void printTopBottom(int width)
{
    int i;
    int num;

    /* Number of * that need to be printed for board format */
    num = (width*3)+(width-1);

    /* prints the top/bottom line of the board */
    printf("  +");
    for (i = 0; i < num; i++)
    {
        printf("*");
    }
    printf("+\n");
}

/*
 * SUBMODULE: newTurn
 * IMPORT: board(int**), gameLog(LinkedList*), width(int), height(int), turnCount(int), gameNum(int)
 * EXPORT: void
 * ASSERTION: Starts a new turn of the Tic Tac Toe Game. ending when a move is successfuly made
 */
void newTurn(int** board, LinkedList** gameLog, int width, int height, int turnCount, int gameNum)
{
    int clr;
    int doneTurn;
    char player;
    int insertX;
    int insertY;
    insertX = -1;
    insertY = -1;

    /* Players turn is based on whether the turn count is even or odd */
    if (turnCount%2 == 0)
    {
        player = 'X';
    }
    else
    {
        player = 'O';
    }

    /* Keeps looping until user successfully finishes a turn */
    doneTurn = 0;
    while(doneTurn != 1)
    {
        printf("--------------------\n");
        printf("Player %c make a turn\n", player);
        printf("Please use format (x,y)\n");
        printf("--------------------\n");

        /* Clears stdin to allow for successful scan */
        clr = getchar();
        while(clr != '\n' && clr != EOF)
        {
            clr = getchar();
        }

        /* Scans with format (x,y) */
        scanf(" (%d,%d)", &insertX, &insertY);

        /* Checks that co-ordinates entered are valid */
        if((insertY < height) && (insertY >= 0) && (insertX < width)
            && (insertX >= 0))
        {
            /* If cell is free insert player turn */
            if (board[insertY][insertX] == -1)
            {
                board[insertY][insertX] = player%2;
                doneTurn = 1;
            }
            /* Otherwise it is already filled */
            else
            {
                printf(ERRCLR "ERROR! Already filled here \n" CLR);
            }
        }
        /* Checks if the data wasn't read at all from scanf */
        else if ((insertX == -1) || (insertY == -1))
        {
            printf(ERRCLR "ERROR! Wrong format input \n" CLR);
        }
        /* Otherwise co-ordinates don't fit on the board */
        else
        {
            printf(ERRCLR "ERROR! Co-ordinates out of board\n" CLR);
        }
    }
    /* display the turn and put turn data into linkedlist */
    displayBoard(board, width, height);
    insertTurn(gameLog, turnCount, player, insertX, insertY, gameNum);
}/* End of player turn */
