#include <stdio.h>
#include <stdlib.h>
#include "userInterface.h"
#include "LinkedList.h"
#include "gameFunc.h"
#include "logFunc.h"

void mainMenu(int** board, int width, int height, int numMatch)
{
    int option;
    int exit;
    LinkedList* gameLog = NULL;

    gameLog = createLinkedList();

    exit = 0;
    do
    {
        printf("----------------------------------------\n");
        printf("Select menu option:\n");
        printf("0: Exit game\n");
        printf("1: Start a new game\n");
        printf("2: View settings of game\n");
        printf("3: View current logs\n");
        #ifndef SECRET
        printf("4: Save logs to file\n");
        #endif
        #ifndef EDITOR
        printf("5: Change settings\n");
        #endif
        printf("----------------------------------------\n");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                newGame(board, width, height, numMatch, &gameLog);
                break;
            case 2:
                printf("SETTINGS:\n");
                printf("   M: %d\n", height);
                printf("   N: %d\n", width);
                printf("   K: %d\n", numMatch);
                break;
            case 3:
                printf("SETTINGS:\n");
                printf("   M: %d\n", height);
                printf("   N: %d\n", width);
                printf("   K: %d\n", numMatch);
                printLinkedList(gameLog, &printList);
                break;
            case 4:
                #ifndef SECRET
                saveLog(gameLog, width, height, numMatch);
                #else
                printf("Incorrect number entered\n");
                #endif
                break;
            case 5:
                #ifndef SECRET
                printf("Enter value for M");
                
                freeTable(board, width, height);
                board = (int**)malloc(height * sizeof(int*));
                for(i = 0; i < height; i++)
                {
                    board[i] = (int*)malloc(width * sizeof(int));
                }
                #else
                printf("Incorrect number entered\n");
                #endif
                break;
            case 0:
                freeLists(&gameLog);
                exit = 1;
                break;
            default:
                printf("Incorrect number entered");
        }
    } while (exit != 1);
}
