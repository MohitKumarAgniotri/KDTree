
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// method to insert a new node in the linked list
void insert(struct LinkedList * list, struct Data * data)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
	    // if the head is null
	    if( list->head == NULL )
	    {
		    // create a new head
		    list->head = newNode; 

		    // set the data
		    list->head->data = data;

		    // set the next to null
		    list->head->next = NULL;

		    // set the tail to head
		    list->tail = list->head;
	    }
	    else
	    {
		    // set data and next
		    newNode->data = data;
		    newNode->next = NULL;

		    // set the next of tail to new node
		    list->tail->next = newNode;

		    // set the tail to the new node
		    list->tail = newNode;
	    }
	    // increment the size by 1
	    list->size++;
    }
}

// method to search
void search(struct LinkedList * list, char * key, FILE * fp)
{
    // look for the data with this trading name
    
    // the reference to the head node
    struct Node * current = list->head;

    // set the flag found to false
    int found = 0;
    
    // as long as current is not null
    while( current != NULL )
    {
        // if this is the key we are looking for
        if( strcmp(current->data->tradingName, key) == 0 )
        {
            // print this data
            printData(current->data, fp);

            // set found to true
            found = 1;
        }
        // move on to the next node
        current = current->next;
    }

    // if not found
    if( !found )
    {
        // print not found
        fprintf(fp, "%s --> NOT FOUND\n\n", key);
    }
}
