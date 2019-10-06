#include <stdio.h>
#include "gameFunc.h"


void newGame(int** board, int width, int height)
{
    int i;
    int j;
    int gameEnd;

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
            newTurn(board, width, height);
        }
        gameEnd = 1;
    }
    while (gameEnd != 1);
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

void newTurn(int** board, int width, int height)
{
    int doneTurn;
    static int numTurn;
    char player;
    char line[9];
    int readAtt;
    int insertX;
    int insertY;

    doneTurn = 0;
    if (numTurn%2 == 0)
    {
        player = 'X';
    }
    else
    {
        player = 'O';
    }

    do
    {
        printf("Player %c make a turn\n", player);
        fgets(line, 9, stdin);
        readAtt = sscanf(line, "(%d,%d)", &insertX, &insertY);

        if((insertY < width) && (insertY >= 0) && (insertX < height)
            && (readAtt = 2) && (insertX >= 0))
        {
            if (board[insertY][insertX] == -1)
            {
                board[insertY][insertX] = player%2;
                doneTurn = 1;
            }
            else
            {
                printf("ERROR! Already filled here\n");
                insertX = 0;
                insertY = 0;
            }
        }
        else
        {
            printf("ERROR! Co-ordinates out of board\n");
        }
    }
    while(doneTurn != 1);
    displayBoard(board, width, height);
    numTurn++;
}
