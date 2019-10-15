#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
