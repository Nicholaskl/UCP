#include <stdio.h>
#include "userInterface.h"
#include "gameFunc.h"
#include "LinkedList.h"

void mainMenu(int** board, int width, int height)
{
    int option;
    int exit;
    LinkedList turns = NULL;

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
                newGame(board, width, height);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                exit = 1;
                break;
            default:
                printf("Incorrect number entered");
        }
    } while (exit != 1);
}
