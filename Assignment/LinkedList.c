#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

LinkedList* createLinkedList()
{
    LinkedList* list;

    list = (LinkedList*)malloc(sizeof(LinkedList));
    (*list).head = NULL;
    (*list).tail = NULL;
    list->count = 0;

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
    list->count += 1;
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
    list->count -= 1;
    return value;
}

void insertLast(LinkedList* list, void* entry)
{
    LListNode* newNode;
    newNode = (LListNode*)malloc(sizeof(LListNode));

    (*newNode).data = entry;

    if(isEmpty(list) == 0)
    {
        (*list).head = newNode;
        (*list).tail = newNode;
        (*(*list).tail).next = NULL;
    }
    else
    {
        (*newNode).next = (*list).tail;
        (*list).tail = newNode;
    }
    list->count += 1;
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

    free(curr);
    list->count -= 1;
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

void printLinkedList(LinkedList* list, void (*funcPointer)(LListNode*))
{
    LListNode* curr;

    curr = list->head;

    if(list->head->next == NULL)
    {
        if(curr->data != NULL)
        {
            (*funcPointer)(curr);
        }
    }
    else
    {
        if(curr->data != NULL)
        {
            while(curr != NULL)
            {
                (*funcPointer)(curr);
                curr = curr->next;
            }
        }
    }

}

void freeLinkedList(LinkedList* list, void (*funcPointer)(LListNode*))
{
    freeNode((*list).head, funcPointer);
    free(list);
}

void freeNode(LListNode *node, void (*funcPointer)(LListNode*))
{
    if(node != NULL)
    {
        freeNode((*node).next, funcPointer);

        (*funcPointer)(node);
        free(node);
    }
}
