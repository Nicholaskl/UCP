/*
 * File: LinkedList.h
 * File Created: Tuesday, 1st October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Wednesday, 16th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes method definitions for LinkedList.c
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* Normal Text colour definition */
#define CLR "\033[0m"
/* Red text definitions - for error printing */
#define ERRCLR "\033[1;31m"

typedef struct LListNode{
    void* data;
    struct LListNode* next;
} LListNode;

typedef struct{
    LListNode* head;
    LListNode* tail;
    int count;
} LinkedList;

LinkedList* createLinkedList();
void insertStart(LinkedList* list, void* entry);
int isEmpty(LinkedList* list);
void* removeStart(LinkedList* list);
void insertLast(LinkedList* list, void* entry);
void* removeLast(LinkedList* list);
int listLength(LListNode* node);
void printLinkedList(LinkedList* list, void (*funcPointer)(LListNode*));
void writeLinkedList(LinkedList* list, FILE* file, void (*funcPointer)(LListNode*, FILE*));
void freeLinkedList(LinkedList* list, void (*funcPointer)(LListNode*));
void freeNode(LListNode *node, void (*funcPointer)(LListNode*));

#endif
