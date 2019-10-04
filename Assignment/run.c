#include <stdio.h>
#include "createTable.h"
#include "userInterface.h"

int main(int argc, char* argv[])
{
    int width;
    int height;
    int numMatch;
    int** array;
    array = 0;

    readSettings(argc, argv, &width, &height, &numMatch);
    initialiseTable(array, width, height);
    mainMenu();
    freeTable(array);

    return 0;
}
