#include <stdio.h>
#include <stdlib.h>
#include "userInterface.h"
#include "LinkedList.h"
#include "gameFunc.h"
#include "logFunc.h"
#include "createTable.h"

void mainMenu(int** board, int width, int height, int numMatch)
{
    int option;
    int exit;
    LinkedList* gameLog = NULL;
    #ifdef EDITOR
    int i;
    #endif

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
        #ifdef SECRET
        printf("4: Save logs to file\n");
        #endif
        #ifdef EDITOR
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
                #ifdef SECRET
                saveLog(gameLog, width, height, numMatch);
                #else
                printf("Incorrect number entered\n");
                #endif
                break;
            case 5:
                #ifdef EDITOR
                freeTable(board, width, height);

                printf("Enter value for M\n");
                scanf("%d", &height);
                printf("Enter value for N\n");
                scanf("%d", &width);
                printf("Enter value for K\n");
                scanf("%d", &numMatch);

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
