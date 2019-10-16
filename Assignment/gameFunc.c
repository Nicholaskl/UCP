#include <stdio.h>
#include "LinkedList.h"
#include "gameFunc.h"
#include "logFunc.h"

void newGame(int** board, int width, int height, int numMatch, LinkedList** gameLog)
{
    static int gameNum = 1;
    int i;
    int j;
    int gameEnd = 0;
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
        newTurn(board, gameLog, width, height, turnCount, gameNum);
        winCondition(board, width, height, numMatch, &gameEnd);
        turnCount++;
    }
    while (gameEnd != 1);
    printf("\033[1;33m");
    printf("^*^*^*^*^*^*^*^*^*^*\n");
    printf("\033[0m");
    if ((turnCount-1)%2 == 0)
    {
        printf("Player X wins!\n");
    }
    else
    {
        printf("Player O wins!\n");
    }
    printf("\033[1;33m");
    printf("^*^*^*^*^*^*^*^*^*^*\n");
    printf("\033[0m");

    gameNum++;
}

void displayBoard(int** board, int width, int height)
{
    int i;
    int j;
    int curr;
    printf("\033[2J");
    printTopBottom(width);

    for(i = 0; i < height; i++)
    {
        printf("  *");
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
               printf("\033[1;33m");
               printf(" O ");
               printf("\033[0m");
            }
            else if(curr == 0)
            {
                printf("\033[1;32m");
                printf(" X ");
                printf("\033[0m");
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

    printf("  +");
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
        printf("--------------------\n");
        printf("Player %c make a turn\n", player);
        printf("Please use format (x,y)\n");
        printf("--------------------\n");
        scanf(" (%d,%d)", &insertX, &insertY);

        if((insertY < height) && (insertY >= 0) && (insertX < width)
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
