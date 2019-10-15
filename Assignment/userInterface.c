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
        printf("1: Start a new game\n");
        printf("2: View settings of game\n");
        printf("3: View current logs\n");
        printf("4: Save logs to file\n");
        printf("5: Exit game\n");
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
                saveLog(gameLog, width, height, numMatch);
                break;
            case 5:

                freeLists(&gameLog);
                exit = 1;
                break;
            default:
                printf("Incorrect number entered");
        }
    } while (exit != 1);
}
