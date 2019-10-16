#ifndef GAMEFUNC_H
#define GAMEFUNC_H

#define YLLW "\033[1;33m"
#define GRN "\033[1;32m"
#define CLR "\033[0m"
#define ERRCLR "\033[1;31m"

void newGame(int** board, int width, int height, int numMatch, LinkedList** gameLog);
void displayBoard(int** board, int width, int height);
void printTopBottom(int width);
void newTurn(int** board, LinkedList** gameLog, int width, int height, int turnCount, int gameNum);
void winCondition(int** board, int width, int height, int numMatch, int* gameEnd);
void checkWin(int** board, int width, int height, int numMatch, int i, int j, int* numO, int* numX, int* gameEnd);

#endif
