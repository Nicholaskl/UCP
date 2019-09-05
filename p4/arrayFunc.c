#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LENGTH 3

void menu(int argc, char* argv[]);
int sum(int array[], int length);
int max(int array[], int length);
void reverse(int array[], int length);
void parseArray(char** str, int array[], int length);
void printStr(int array[], int length);
void upperString(char* funcName);

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Error. not enough arguments entered\n");
    }
    else
    {
        menu(argc, argv);
    }
    return 0;
}

void menu(int argc, char* argv[])
{
    int output;
    int* array = (int*)malloc(LENGTH * sizeof(int));
    int i;
    char** str = (char**)malloc(LENGTH * sizeof(char));
    char* funcName = (char*)malloc(8 * sizeof(char));
    
    for(i = 2; i < argc; i++)
    {
        str[i-2] = argv[i];
    }

    strncpy(funcName, argv[1], 8);   

    upperString(funcName);
    parseArray(str, array, LENGTH);
    output = 0;

    if(strcmp(funcName, "SUM") == 0)
    {
        output = sum(array, LENGTH);
        printf("sum is %d\n", output);

    }
    else if(strcmp(funcName, "MAX") == 0)
    {
        output = max(array, LENGTH);
        printf("max index is %d\n", output);

    }
    else if(strcmp(funcName, "REVERSE") == 0)
    {
        reverse(array, LENGTH);
        printStr(array, LENGTH);
    }
    else
    {
        printf("Error, wrong function name entered\n");
    }
    free(array);
    free(str);
    free(funcName);
}

int sum(int array[], int length)
{
    int i;
    int output;
    output = 0;
    for(i = 0; i < length; i++)
    {
        output += array[i];   
    }
    return output;
}

int max(int array[], int length)
{
    int i;
    int maxNum;
    int output;
    output = 0;
    maxNum = array[0];
    for(i = 0; i < length; i++)
    {
        if(array[i] > maxNum)
        {
            output = i;
        }
    }   
    return output;
}

void reverse(int array[],int length)
{
    int i;
    int arrayTemp[LENGTH];
    for(i = 0; i < length; i++)
    {
        arrayTemp[i] = array[length-1-i];
    }   
    for(i = 0; i < length; i++)
    {
        array[i] = arrayTemp[i];
    }
}

void parseArray(char** str, int array[], int length)
{
    int i;
    for(i = 0; i < length; i++)
    {
        array[i] = atoi(str[i]);
    }
}

void printStr(int array[], int length)
{
    int i;
    printf("{");
    for(i = 0; i < (length-1); i++)
    {
        printf("%d, ", array[i]);
    }
    printf("%d}\n", array[length-1]);
}

void upperString(char* funcName)
{
    int i;
    for(i = 0; i < strlen(funcName); i++)
    {
        if(funcName[i] >= 'a')
        {
            funcName[i] = funcName[i] - 32;
        }
    }
}
