#include <stdio.h>
#include "LinkedList.h"
#include "gameFunc.h"
#include "logFunc.h"

void newGame(int** board, int width, int height, LinkedList** gameLog)
{
    static int gameNum = 1;
    int i;
    int j;
    int gameEnd;
    int turnCount = 1;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            board[i][j] = -1;
        }
    }

    displayBoard(board, width, height);
    do
    {
        for(i = 0; i < 2; i++)
        {
            newTurn(board, gameLog, width, height, turnCount, gameNum);
            turnCount++;
        }
        gameEnd = 1;
    }
    while (gameEnd != 1);
    gameNum++;
}

void displayBoard(int** board, int width, int height)
{
    int i;
    int j;
    int curr;

    printTopBottom(width);

    for(i = 0; i < height; i++)
    {
        printf("*");
        for(j = 0; j < width; j++)
        {
            curr = board[i][j];
            if(j!=0)
            {
                printf("|");
            }

            if (curr == -1)
            {
                printf("   ");
            }
            else if(curr == 1)
            {
                printf(" O ");
            }
            else if(curr == 0)
            {
                printf(" X ");
            }
        }
        printf("*\n");
    }

    printTopBottom(width);
}

void printTopBottom(int width)
{
    int i;
    int num;

    num = (width*3)+(width-1);

    printf("+");
    for (i = 0; i < num; i++)
    {
        printf("*");
    }
    printf("+\n");
}

void newTurn(int** board, LinkedList** gameLog, int width, int height, int turnCount, int gameNum)
{
    int doneTurn;
    char player;
    int readAtt;
    int insertX = -1;
    int insertY = -1;

    doneTurn = 0;
    if (turnCount%2 == 0)
    {
        player = 'X';
    }
    else
    {
        player = 'O';
    }

    while(doneTurn != 1)
    {
        printf("Player %c make a turn\n", player);
        scanf(" (%d,%d)", &insertX, &insertY);

        if((insertY <= width) && (insertY >= 0) && (insertX <= height)
            && (readAtt = 2) && (insertX >= 0))
        {
            if (board[insertY][insertX] == -1)
            {
                board[insertY][insertX] = player%2;
                doneTurn = 1;
            }
            else
            {
                printf("ERROR! Already filled here \n");
                insertX = 0;
                insertY = 0;
            }
        }
        else
        {
            printf("ERROR! Co-ordinates out of board\n");
        }
    }
    displayBoard(board, width, height);
    insertTurn(gameLog, turnCount, player, insertX, insertY, gameNum);
}
