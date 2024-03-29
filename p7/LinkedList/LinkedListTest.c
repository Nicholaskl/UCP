/*
 * File: LinkedListTest.c
 * File Created: Friday, 6th September 2019 11:40:35 am
 * Author: Jonathon Winter
 * -----
 * Last Modified: Tuesday, 24th September 2019 2:29:59 pm
 * Modified By: Jonathon Winter
 * -----
 * Purpose: Semi complete Test harness for a Generic Linked List in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "LinkedListTest.h"

int main(int argc, char const *argv[])
{
   LinkedList* list = NULL;
   char* data;
   Entry print1 = {2010, 04, 12, "Interview went well I think, though was told to wear shoes."};
   Entry print2 = {2010, 04, 18, "Doc advised me to concentrate on something... I forget."};
   char* input1 = (char*)malloc(sizeof(char)*6);
   char* input2 = (char*)malloc(sizeof(char)*4);

   strncpy(input1,"hello",6);
   strncpy(input2,"bye",6);

   /*CREATING*/
   printf("Creating List: ");
   list = createLinkedList();
   if(list == NULL || list->head != NULL)
   {
      printf("FAILED\n");
   }
   else
   {
      printf("PASSED\n");
   }

   /*INSERTING FIRST*/
   printf("Inserting First: ");
   insertStart(list,input1);
   if(list->head == NULL)
   {
      printf("FAILED\n");
   }
   else if(strncmp((char*)list->head->data, input1, strlen(input1)+1)==0)
   {
      printf("PASSED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   printf("Inserting First (2): ");
   insertStart(list,input2);
   if(list->head == NULL)
   {
      printf("FAILED\n");
   }
   else if(strncmp((char*)list->head->data, input2, strlen(input2)+1)==0 &&
            strncmp((char*)list->tail->data, input1, strlen(input1)+1)==0)
   {
      printf("PASSED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   /*REMOVING FIRST*/
   printf("Remove First: ");
   data = (char*)removeStart(list);

   if(strncmp(data, input2, strlen(input2)+1) == 0)
   {
      printf("PASSED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   /*REMOVING LAST*/
   printf("Remove Last: ");
   insertStart(list,input2);

   data = (char*)removeLast(list);

   if(strncmp(data, input1, strlen(input1)+1) == 0)
   {
      printf("PASSED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   printf("Remove Last (2): ");

   data = (char*)removeLast(list);

   if(strncmp(data, input2, strlen(input2)+1) == 0)
   {
      printf("PASSED\n");
   }
   else if(list->head == NULL)
   {
      printf("FAILED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   /*INSERTING LAST*/
   printf("Inserting Last: ");
   insertLast(list,input1);
   if(list->head == NULL)
   {
      printf("FAILED\n");
   }
   else if(strncmp((char*)list->head->data, input1, strlen(input1)+1)==0)
   {
      printf("PASSED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   printf("Inserting Last (2): ");
   insertLast(list,input2);
   if(list->head == NULL)
   {
      printf("FAILED\n");
   }
   else if(strncmp((char*)list->head->data, input1, strlen(input1)+1)==0 &&
            strncmp((char*)list->tail->data, input2, strlen(input2)+1)==0)
   {
      printf("PASSED\n");
   }
   else
   {
      printf("FAILED\n");
   }

   /*PRINTING*/
   removeStart(list);
   removeStart(list);
   insertStart(list, &print1);
   insertLast(list, &print2);

   printLinkedList(list, &printEntry);

   /*FREEING*/
   free(input1);
   free(input2);
   freeLinkedList(list, &freeEntry);

   /* ANY OTHER TESTS YOU WANT TO DO*/

   return 0;
}

void printEntry(LListNode* node)
{
    Entry* data;

    data = node->data;
    printf("%d-%d-%d: %s\n", (int)(data->year), (int)(data->month), (int)(data->day), (char*)(data->msg));
}

void freeEntry(LListNode* node)
{
}
