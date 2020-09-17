
#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>


// get a linked list of data from the given file name :)
struct LinkedList * readFile(const char * filename)
{

    // open the file
    FILE * fp = fopen(filename, "r");
    // if cannot open file, return null
    if( fp == NULL )
    {
        // return null
        return NULL;
    }

    // create a linked list
    struct LinkedList * list = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    if (list != NULL)
    {
        // set the head and tail to null
        list->head = NULL;
        list->tail = NULL;

        // set the size to 0
        list->size = 0;

        // the string to be read
        char * line = NULL;

        // to store length
        size_t len = 0;
        ssize_t read;

        // skip first line
        read = getline(&line, &len, fp);

        // read the file
        while ((read = getline(&line, &len, fp)) != -1)
        {
            // remove the change in line
            line[ strlen(line) - 1] = '\0';

            // get the data from this line
            struct Data * data = getData(line);

            // add this data to linked list
            insert(list, data);
        }
        //free the line ptr
        free(line);

        // close the file
        fclose(fp);
    }

    // return the list
    return list;
}

// the method to search keys
void searchKeys(struct LinkedList * list, FILE * fout)
{
    // the key to be searched
    char * key;
    size_t len = 0;
    ssize_t read;

    // read the keys

    // as long as there is a key from stdin
    while( (read = getline(&key, &len, stdin)) != -1 )
    {
        // remove the change in line
        if( key[ strlen(key) - 1] == '\n' )
            key[ strlen(key) - 1] = '\0';

        // printf("key = %s\n", key);

        // search
        search(list, key, fout);
    }
}


void freeLinkedList(struct LinkedList* list)
{
    struct Node *current, *tmpNode;
    current = list->head;
    while (current != NULL)
    {
        tmpNode = current;
        current = current->next;
        free(tmpNode->data->CLUESmallArea);
        free(tmpNode->data->industryDescription);
        free(tmpNode->data->tradingName);
        free(tmpNode->data->location);
        free(tmpNode->data);
        free(tmpNode);
    }
}

int main(int argc, const char * argv[])
{
    // there must be 3 arguments
    if( argc < 3 )
    {
        // show error
        printf("Usage : %s <input_file_name> <output_file_name>\n", argv[0]);
        // stop
        return 1;
    }

    // read the linked lsit
    struct LinkedList * list = readFile(argv[1]);

    // if cannot open file, stop
    if( list == NULL )
        return 2;

    // open the file to output
    FILE * fout = fopen(argv[2], "w");

    // if cannot open file
    if( !fout )
    {
        // stop
        return 3;
    }

    // search for the keys :)
    searchKeys(list, fout);

    // close the output file :)
    fclose(fout);

    freeLinkedList(list);
    free(list);

    return 0;
}
