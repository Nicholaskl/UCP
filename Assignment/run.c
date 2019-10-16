#include <stdio.h>
#include <stdlib.h>
#include "createTable.h"
#include "userInterface.h"

int main(int argc, char* argv[])
{
    int width= -1;
    int height = -1;
    int numMatch = -1;
    int** board;
    int i;
    board = 0;

    readSettings(argc, argv, &width, &height, &numMatch);
    if((width>0) && (height>0) && (numMatch >= 0))
    {
        board = (int**)malloc(height * sizeof(int*));
        for(i = 0; i < height; i++)
        {
            board[i] = (int*)malloc(width * sizeof(int));
        }

        mainMenu(board, width, height, numMatch);
        freeTable(board, width, height);
    }

    return 0;
}
