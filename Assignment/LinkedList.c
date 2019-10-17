/*
 * File: LinkedList.c
 * File Created: Tuesday, 1st October 2019
 * Author: Nicholas Klvana-Hooper
 * -----
 * Last Modified: Thursday, 17th October 2019
 * Modified By: Nicholas Klvana-Hooper
 * -----
 * Purpose: A data stucture that can contain data and can expand and shrink
 * Reference: Functions provided are based on Lecture 7 (UCP)
              Also is a modified version of prac7 LinkedList.c made by Nicholas Klvana-Hooper (me)
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
 * SUBMODULE: createLinkedList
 * IMPORT:
 * EXPORT: list(LinkedList*)
 * ASSERTION: Create a new linked list with default values
 */
LinkedList* createLinkedList()
{
    LinkedList* list;

    /* Creates the linked list pointer */
    list = (LinkedList*)malloc(sizeof(LinkedList));
    /* Sets defaults for the linked list */
    (*list).head = NULL;
    (*list).tail = NULL;
    list->count = 0;

    return list;
}

/*
 * SUBMODULE: insertStart
 * IMPORT: list(LinkedList*), data(void*)
 * EXPORT:
 * ASSERTION: Inserts a new node at the front of the list
 */
void insertStart(LinkedList* list, void* data)
{
    /* Creates a newnode with data given */
    LListNode* newNode;
    newNode = (LListNode*)malloc(sizeof(LListNode));
    (*newNode).data = data;

    /* If List is empty head and tail should be made to be the new ndoe */
    if(list->count == 0)
    {
        (*list).head = newNode;
        (*list).tail = newNode;
        (*(*list).head).next = NULL;
    }
    /* Otherwise put new node at the beginning of the list */
    else
    {
        (*newNode).next = (*list).head;
        (*list).head = newNode;
    }
    list->count += 1;
}

/*
 * SUBMODULE: removeStart
 * IMPORT: list(LinkedList*)
 * EXPORT: node(void*)
 * ASSERTION: Removes the node at the front and returns it
 */
void* removeStart(LinkedList* list)
{
    LListNode* toRemove;
    void* value;

    /* Checks if list is empty, and thus cannot remove */
    if(list->count == 0)
    {
        printf(ERRCLR "Can't remove from empty list" CLR);
    }
    /* Otherwise there is at least a node to delete */
    else
    {
        /* Gets data for export */
        toRemove = (*list).head;
        value = toRemove->data;

        /* If list is 1 then removing should set list to NULL */
        if(list->count ==1)
        {
            list->head = NULL;
            list->tail = 0;
        }
        /* Otherwise set next to the value after the front */
        else
        {
            list->head = list->head->next;
        }

        /* Cleanup node and decrease count of nodes */
        free(toRemove);
        list->count -= 1;
    }

    return value;
}

/*
 * SUBMODULE: insertLast
 * IMPORT: list(LinkedList*), data(void*)
 * EXPORT: void
 * ASSERTION: Inserts a new node at the end of the list
 */
void insertLast(LinkedList* list, void* data)
{
    /* Creates new node with given data */
    LListNode* newNode;
    newNode = (LListNode*)malloc(sizeof(LListNode));
    (*newNode).data = data;

    /* If list is empty then newNode is tail and head */
    if(list->count == 0)
    {
        (*list).head = newNode;
        (*list).tail = newNode;
        (*(*list).tail).next = NULL;
    }
    /* Otherwise insert node at the end of the list */
    else
    {
        newNode->next = NULL;
        list->tail->next = newNode;
        (*list).tail = newNode;
    }
    /* Increase number of nodes in list */
    list->count += 1;
}

/*
 * SUBMODULE: removeLast
 * IMPORT: list(LinkedList*)
 * EXPORT: data(void*)
 * ASSERTION: Removes node at end of list and returns it
 */
void* removeLast(LinkedList* list)
{
    /* Uses a single linked, double ended so therefore need a prev node */
    LListNode* curr;
    LListNode* prev;
    void* value;

    curr = (*list).head;

    /* Checks if list is empty and thus can't remove */
    if(list->count == 0)
    {
        printf(ERRCLR "Can't remove from empty list" CLR);
    }
    /* Otherwise can remove a node */
    else
    {
        /* If there is one value get it and set list to NULL */
        if(list->count == 1)
        {
            curr = list->head;
            list->head = NULL;
            list->tail = NULL;
        }
        /* Otherwise remove and set tail to point to second last node */
        else
        {
            /* Find second last node */
            while ((*curr).next != NULL)
            {
                prev = curr;
                curr = (*curr).next;
            }

            /* Set tail to second last ndoe and unlink the last one */
            (*list).tail = prev;
            (*(*list).tail).next = NULL;
        }

        /* Get ready to return data and free up last node */
        value = curr->data;
        free(curr);
        list->count -= 1;
    }
    return value;
}

/*
 * SUBMODULE: writeLinkedList
 * IMPORT: list(LinkedList*), file(FILE*), void (*funcPointer)(LListNode*, FILE*)
 * EXPORT: void
 * ASSERTION: Traverses list and gives data to writing function for struct
 */
void writeLinkedList(LinkedList* list, FILE* file, void (*funcPointer)(LListNode*, FILE*))
{
    LListNode* curr;
    curr = list->head;

    /* Traverse list */
    while(curr != NULL)
    {
        /* Calls function given to write the data in the node */
        (*funcPointer)(curr, file);
        /* Now get the next node to print */
        curr = curr->next;
    }

}

/*
 * SUBMODULE: printLinkedList
 * IMPORT: list(LinkedList*), void (*funcPointer)(LListNode*, FILE*)
 * EXPORT: void
 * ASSERTION: Traverses list and gives data to print function for struct
 */
void printLinkedList(LinkedList* list, void (*funcPointer)(LListNode*))
{
    LListNode* curr;
    curr = list->head;

    /* Traverse list */
    while(curr != NULL)
    {
        /* Calls function to print the data in the node */
        (*funcPointer)(curr);
        /* Now get the next node to print */
        curr = curr->next;
    }

}

/*
 * SUBMODULE: freeLinkedList
 * IMPORT: list(LinkedList*), file(FILE*), void (*funcPointer)(LListNode*, FILE*)
 * EXPORT: void
 * ASSERTION: Calls function to free nodes and then the list pointer
 */
void freeLinkedList(LinkedList* list, void (*funcPointer)(LListNode*))
{
    /* Call for the nodes to be freed */
    freeNode((*list).head, funcPointer);
    /* Free the list pointer */
    free(list);
}

/*
 * SUBMODULE: freeLinkedList
 * IMPORT: node(LListNode*), file(FILE*), void (*funcPointer)(LListNode*, FILE*)
 * EXPORT: void
 * ASSERTION: Recursive function freeing every node using function provided for struct
 */
void freeNode(LListNode *node, void (*funcPointer)(LListNode*))
{
    /* Traverse nodes */
    if(node != NULL)
    {
        /* Recursive call to reach all nodes */
        freeNode(node->next, funcPointer);

        /* Calls function provided to free the node data */
        (*funcPointer)(node);
        /* Free the node itself */
        free(node);
    }
}
