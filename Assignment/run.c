#include <stdio.h>
#include <stdlib.h>
#include "createTable.h"
#include "userInterface.h"

int main(int argc, char* argv[])
{
    int width;
    int height;
    int numMatch;
    int** board;
    int i;
    board = 0;

    readSettings(argc, argv, &width, &height, &numMatch);
    board = (int**)malloc(height * sizeof(int*));
    for(i = 0; i < height; i++)
    {
        board[i] = (int*)malloc(width * sizeof(int));
    }

    mainMenu(board, width, height);
    freeTable(board, width, height);

    return 0;
}
