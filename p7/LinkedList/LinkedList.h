#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LListNode{
    void* data;
    struct LListNode* next;
} LListNode;

typedef struct{
    LListNode* head;
    LListNode* tail;
} LinkedList;

LinkedList* createLinkedList();
void insertStart(LinkedList* list, void* entry);
void* removeStart(LinkedList* list);
void insertLast(LinkedList* list, void* entry);
void* removeLast(LinkedList* list);
int listLength(LListNode* node);
void printLinkedList(LinkedList* list);
void freeLinkedList(LinkedList* list);
void freeNode(LListNode *node);

#endif
