#ifndef GAMEFUNC_H
#define GAMEFUNC_H

void newGame(int** board, int width, int height, LinkedList** gameLog);
void displayBoard(int** board, int width, int height);
void printTopBottom(int width);
void newTurn(int** board, LinkedList** gameLog, int width, int height);

#endif
