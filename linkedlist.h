
#ifndef linkedlist_h
#define linkedlist_h

// include the data file
#include "data.h"

// the node to store a linked list
struct Node
{
    char *key;
    // the data at this node
    struct Data * data;

    // the link to the next node
    struct Node * next;
};

// the struct to represent the linked list
struct LinkedList
{
    // the head of the linked list
    struct Node * head;
    
    // the tail of the linked list
    struct Node * tail;
    
    // the size of the linked list
    int size;
};

// the method to insert a new node in the linked list
void insert(struct LinkedList * list, char *key, struct Data * data);

// method to search
void search(struct LinkedList * list, char * key, FILE * fp);

void freeLinkedList(struct LinkedList * list);


#endif /* linkedlist_h */
