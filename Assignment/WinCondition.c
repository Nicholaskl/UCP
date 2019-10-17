#include <stdio.h>
#include "WinCondition.h"

void winCondition(int** board, int width, int height, int numMatch, int* gameEnd)
{
    int i;
    int j;
    int numX;
    int numO;

    for(i = 0; i < height; i++)
    {
        numX = 0;
        numO = 0;
        for(j=0; j < width; j++)
        {
            checkWin(board, width, height, numMatch, i, j, &numO, &numX, gameEnd);
        }
    }

    for(j = 0; j < width; j++)
    {
        numX = 0;
        numO = 0;
        for(i=0; i < height; i++)
        {
            checkWin(board, width, height, numMatch, i, j, &numO, &numX, gameEnd);
        }
    }

    for(i=0; i < height; i++)
    {
        numX = 0;
        numO = 0;
        for(j = 0; ((i+j)<height) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i+j, j, &numO, &numX, gameEnd);
        }

        numX = 0;
        numO = 0;
        for(j = 0; ((i-j)>=0) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i-j, j, &numO, &numX, gameEnd);
        }
    }

    for(i=0; i < height; i++)
    {
        numX = 0;
        numO = 0;
        for(j = 0; ((i+j)<height) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i+j, width-j-1, &numO, &numX, gameEnd);
        }

        numX = 0;
        numO = 0;
        for(j = 0; ((i-j)>=0) && (j<width) && (j<numMatch); j++)
        {
            checkWin(board, width, height, numMatch, i-j, width-j-1, &numO, &numX, gameEnd);
        }
    }
}

void checkWin(int** board, int width, int height, int numMatch, int i, int j, int* numO, int* numX, int* gameEnd)
{
    if(board[i][j] == 0)
    {
        *numO = 0;
        *numX += 1;
    }
    else if(board[i][j] == 1)
    {
        *numX = 0;
        *numO += 1;
    }
    else
    {
        *numO = 0;
        *numX = 0;
    }

    if((*numO == numMatch) || (*numX == numMatch))
    {
        *gameEnd = 1;
    }

}
