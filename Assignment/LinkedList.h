/*
 * File: LinkedList.h
 * File Created: Tuesday, 1st October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Thursday, 17th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: Includes method definitions for LinkedList.c
 * Reference: Functions provided are based on Lecture 7 (UCP)
              Also is a modified version of prac7 LinkedList.c made by Nicholas Klvana-Hooper (me)
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* Normal Text colour definition */
#define CLR "\033[0m"
/* Red text definitions - for error printing */
#define ERRCLR "\033[1;31m"

/* LinkedListNode Struct defintion */
typedef struct LListNode{
    void* data;
    struct LListNode* next;
} LListNode;

/* LinkedList Struct defintion */
typedef struct{
    LListNode* head;
    LListNode* tail;
    int count;
} LinkedList;

LinkedList* createLinkedList();
void insertStart(LinkedList* list, void* entry);
void* removeStart(LinkedList* list);
void insertLast(LinkedList* list, void* entry);
void* removeLast(LinkedList* list);
void printLinkedList(LinkedList* list, void (*funcPointer)(LListNode*));
void writeLinkedList(LinkedList* list, FILE* file, void (*funcPointer)(LListNode*, FILE*));
void freeLinkedList(LinkedList* list, void (*funcPointer)(LListNode*));
void freeNode(LListNode *node, void (*funcPointer)(LListNode*));

#endif
