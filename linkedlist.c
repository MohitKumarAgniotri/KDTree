
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

// method to insert a new node in the linked list
void insert(struct LinkedList * list, char *key, struct Data * data) {
    int found = 0;
    //try to find the node with the key:
    // the reference to the head node
    struct Node *current = list->head;
    // as long as current is not null
    while (current != NULL) {
        // if this is the key we are looking for
        if (strcmp(current->key, key) == 0) {
            found = 1;
            struct Data *tmpData = current->data;
            while (tmpData->nextData != NULL) {
                tmpData = tmpData->nextData;
            }
            tmpData->nextData = data;
            data->nextData = NULL;
            free(key);
        }
        // move on to the next node
        current = current->next;
    }

    if (!found) {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        if (newNode != NULL)
        {
            data->nextData = NULL;
            newNode->next = NULL;
            newNode->key = key;
            newNode->data = data;

            // if the head is null
            if (list->head == NULL) {
                // create a new head
                list->head = newNode;

                // set the next to null
                list->head->next = NULL;

                // set the tail to head
                list->tail = list->head;
            }
            else
            {
                // set the next of tail to new node
                list->tail->next = newNode;
                // set the tail to the new node
                list->tail = newNode;
            }
            // increment the size by 1
            list->size++;
        }
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
        if( strcmp(current->key, key) == 0 )
        {

            struct Data *tmp = current->data;
            while(tmp!=NULL)
            {
                // print this data
                printData(current->key, tmp, fp);
                tmp = tmp->nextData;
            }


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