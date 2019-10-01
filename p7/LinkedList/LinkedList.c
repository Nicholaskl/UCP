#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList* createLinkedList()
{
    LinkedList* list;

    list = (LinkedList*)malloc(sizeof(LinkedList));
    (*list).head = NULL;
    (*list).tail = NULL;

    return list;
}

void insertStart(LinkedList* list, void* entry)
{
    LListNode* newNode;
    newNode = (LListNode*)malloc(sizeof(LListNode));

    (*newNode).data = entry;
    (*newNode).next = (*list).head;
    (*list).head = newNode;
}

void* removeStart(LinkedList* list)
{
    LListNode* toRemove;
    void* value;

    toRemove = (*list).head;
    (*list).head = (*(*list).head).next;

    value = (*toRemove).data;
    free((*toRemove).data);
    free(toRemove);
    return value;
}

void insertLast(LinkedList* list, void* entry)
{
    LListNode* newNode;
    newNode = (LListNode*)malloc(sizeof(LListNode));

    (*newNode).data = entry;
    (*newNode).next = NULL;
    (*(*list).tail).next = newNode;
    (*list).tail = newNode;
}

void* removeLast(LinkedList* list)
{
    LListNode* curr;
    LListNode* prev;
    void* value;

    curr = (*list).head;
    while ((*curr).next != NULL)
    {
        prev = curr;
        curr = (*curr).next;
    }

    (*(*list).tail).next = NULL;
    (*list).tail = prev;
    value = (*curr).next;
    free((*curr).data);
    free(curr);
    return value;
}

int listLength(LListNode* node)
{
    int length = 0;
    if(node!= NULL)
    {
        length = 1 + listLength((*node).next);
    }
    return length;
}

void printLinkedList(LinkedList* list)
{
    LListNode* curr;

    curr = (*list).head;

    if((*curr).data != NULL)
    {
        printf("%p\n", (*curr).data);
    }
    while((*curr).next != NULL)
    {
        curr = (*curr).next;
        printf("%p\n", (*curr).data);
    }
}

void freeLinkedList(LinkedList* list)
{
    freeNode((*list).head);
    free(list);
}

void freeNode(LListNode *node)
{
    if(node != NULL)
    {
        freeNode((*node).next);

        free((*node).data);
        free(node);
    }
}
