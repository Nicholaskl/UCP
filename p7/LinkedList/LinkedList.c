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

    if(isEmpty(list) == 0)
    {
        (*list).head = newNode;
        (*list).tail = newNode;
        (*(*list).head).next = NULL;
    }
    else
    {
        (*newNode).next = (*list).head;
        (*list).head = newNode;
    }
}

int isEmpty(LinkedList* list)
{
    int empty;

    if((*list).head == NULL)
    {
        empty = 0;
    }
    else
    {
        empty = 1;
    }
    return empty;
}

void* removeStart(LinkedList* list)
{
    LListNode* toRemove;
    void* value;

    toRemove = (*list).head;
    (*list).head = (*(*list).head).next;

    value = (*toRemove).data;
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
    if(list->head->next != NULL)
    {
        while ((*curr).next != NULL)
        {
            prev = curr;
            curr = (*curr).next;
        }

        (*list).tail = prev;
        (*(*list).tail).next = NULL;
    }

    value = curr->data;

    freeNode(curr);
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

    curr = list->head;

    if(list->head->next == NULL)
    {
        printf("%s\n", (char*)curr->data);
    }
    else
    {
        while(curr != NULL)
        {
            printf("%s\n", (char*)(curr->data));
            curr = curr->next;
        }
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
