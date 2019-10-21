/*
 * File: UserInterface.c
 * File Created: Friday, 4th October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Wednesday, 16th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes menu for program
 */

#include <stdio.h>
#include <stdlib.h>
#include "UserInterface.h"
#include "LinkedList.h"
#include "GameFunc.h"
#include "LogFunc.h"
#include "CreateTable.h"

/*
 * SUBMODULE: mainMenu
 * IMPORT: board(int**), width(int), height(int), numMatch(int)
 * EXPORT: void
 * ASSERTION: Contains main menu for game
 */
void mainMenu(int** board, int width, int height, int numMatch)
{
    int option;
    int exit;
    LinkedList* gameLog;

    /* If compiled with editor, needs i for for loop */
    #ifdef EDITOR
    int i;
    #endif

    /* Initalise the linked list of game data */
    gameLog = NULL;
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
        #ifdef EDITOR
        printf("5: Change settings\n");
        #endif
        printf("----------------------------------------\n");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                /* New game is created and started */
                newGame(board, width, height, numMatch, &gameLog);
                break;
            case 2:
                /* Prints the current Settings */
                printSettings(width, height, numMatch);
                break;
            case 3:
                /* Prints settings and all of the game logs */
                printSettings(width, height, numMatch);
                printLinkedList(gameLog, &printList);
                break;
            case 4:
                /* If secret is given when compiled, cannot save logs */
                #ifndef SECRET
                saveLog(gameLog, width, height, numMatch);
                #else
                /* Cannot use this number if not defined */
                printf(ERRCLR "Incorrect number entered\n" CLR);
                #endif
                break;
            case 5:
                /* If editor is given when compiled, can change settings now */
                #ifdef EDITOR
                /* Changes the settings by user */
                changeSettings(board, &width, &height, &numMatch);

                /* Recreates the board with new height and width */
                board = (int**)malloc(height * sizeof(int*));
                for(i = 0; i < height; i++)
                {
                    board[i] = (int*)malloc(width * sizeof(int));
                }
                #else
                printf(ERRCLR "Incorrect number entered\n" CLR);
                #endif
                break;
            case 0:
                /* When program quits, free list of games */
                freeLists(&gameLog);
                exit = 1;
                break;
            default: /* In case invalid number is entered */
                printf(ERRCLR "Incorrect number entered" CLR);
        } /* eEd of switch */
    } while (exit != 1);
} /* End of mainMenu */

/*
 * SUBMODULE: printSettings
 * IMPORT: width(int), height(int), numMatch(int)
 * EXPORT: void
 * ASSERTION: Prints the settings
 */
void printSettings(int width, int height, int numMatch)
{
    printf("SETTINGS:\n");
    printf("   M: %d\n", height);
    printf("   N: %d\n", width);
    printf("   K: %d\n", numMatch);
}

/*
 * SUBMODULE: changeSettings
 * IMPORT: board(int**), width(int), height(int), numMatch(int)
 * EXPORT: void
 * ASSERTION: Prints and collects new setting data from user
 */
void changeSettings(int** board, int* width, int* height, int* numMatch)
{
    freeTable(board, *width, *height);
    printf("Enter value for M\n");
    scanf("%d", height);
    printf("Enter value for N\n");
    scanf("%d", width);
    printf("Enter value for K\n");
    scanf("%d", numMatch);
}
