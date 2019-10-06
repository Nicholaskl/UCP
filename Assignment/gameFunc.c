#include <stdio.h>
#include "gameFunc.h"

void newGame(int** board, int width, int height)
{
    int i;
    int j;

    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
        {
            board[i][j] = -1;
        }
    }
    displayBoard(board, width, height);
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
            else if(curr == 0)
            {
                printf(" O ");
            }
            else if(curr == 1)
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
