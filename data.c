
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// include the data file. Modularity!
#include "data.h"

// method to find the index of the next comma - starting from s
int find(char * line, int s, char c)
{
    // start from s
    int i = s;

    // as long as i is a valid index,
    while( i < strlen(line))
    {
        // if this is the character we are looking for
        if( line[i] == c )
        {
            // return this index
            return i;
        }

        // increment the value of i
        i++;
    }

    // return -1
    return -1;
}

// the method is to get a substring between two indices - including i and excluding j
char * substr(char * str, int i, int j)
{
    // create a string to return
    char * substring = (char *)malloc(sizeof(char) * (j-i+3));
    if (substring != NULL)
    {
        // copy all the characters from i till less than j
        int index = 0;
        while( i<j )
        {
            substring[index++] = str[i++];
        }
        substring[index] = '\0';
    }

    // return the substring
    return substring;
}

void GetDelimType(const char *line, char *delim, int *i);

// the method is to get a line and return the the data parsed from the line
struct KeyDataPair * getData(char * line)
{
    // create the struct to return
    struct KeyDataPair * keyPair = (struct KeyDataPair *)malloc(sizeof(struct KeyDataPair));
    if (keyPair != NULL)
    {
        struct Data * data = (struct Data *)malloc(sizeof(struct Data));
        if (data)
        {
            char delim = ',';
            // the start index
            int i = 0;

            // find comma
            GetDelimType(line, &delim, &i);
            int j = find(line, i, delim);
            char *s = substr(line, i, j);
            // store the census year
            data->censusYear = atoi(s);
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store block ID
            data->blockID = atoi(s);
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store property ID
            data->propertyID = atoi(s);
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store base property ID
            data->basePropertyID = atoi(s);
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);

            //Allocate data for the string
            data->CLUESmallArea = (char *) malloc(strlen(s) + 1);
            if (data->CLUESmallArea) {
                // store CLUE small area
                strcpy(data->CLUESmallArea, s);
            }
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);

            //Allocate data for the string
            keyPair->key = (char *) malloc(strlen(s) + 1);
            if (keyPair->key) {
                // store trading name
                strcpy(keyPair->key, s);
            }
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store industry code
            data->industryCode = atoi(s);
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store industry description
            //Allocate data for the string
            data->industryDescription = (char *) malloc(strlen(s) + 1);
            if (data->industryDescription) {
                strcpy(data->industryDescription, s);
            }

            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store x coordinate
            data->XCoordinate = atof(s);
            // free s
            free(s);

            // find comma
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            // get substring
            s = substr(line, i, j);
            // store y coordinate
            data->YCoordinate = atof(s);
            // free s
            free(s);

            // store location
            i = j + 1;
            GetDelimType(line, &delim, &i);
            j = find(line, i, delim);
            s = substr(line, i, j);
            data->location = (char *) malloc(strlen(s) + 1);
            if (data->location) {
                strcpy(data->location, s);
            }
            free(s);
            data->nextData = NULL;
            keyPair->d = data;
        }
    }
    // return the data
    return keyPair;
}

void GetDelimType(const char *line, char *delim, int *i)
{// get the substring
    if (line[(*i)] == '"'){
        (*delim) = '"';
        (*i) +=1;
    }
    else if (line[(*i)] == ','){
        (*delim) = ',';
        (*i) +=1;
    }
    else{
        (*delim) = ',';
    }
}

// the method is to print data to file
void printData(char *key, struct Data * data, FILE * fp)
{
    // print the data :)
    fprintf(fp, "%s --> Census year: %d || Block ID: %d || Property ID: %d || Base property ID: %d || CLUE small area: %s || Industry (ANZSIC4) code: %d || Industry (ANZSIC4) description: %s || x coordinate: %.5lf || y coordinate: %.5lf || Location: %s \n\n", key, data->censusYear, data->blockID, data->propertyID, data->basePropertyID, data->CLUESmallArea, data->industryCode, data->industryDescription, data->XCoordinate, data->YCoordinate, data->location );
}

// the method is to print data to file
void printKData(char *key, struct Data * data, FILE * fp)
{
    // print the data :)
    while (data)
    {
        fprintf(fp, "%s --> Census year: %d || Block ID: %d || Property ID: %d || Base property ID: %d || CLUE small area: %s || Industry (ANZSIC4) code: %d || Industry (ANZSIC4) description: %s || x coordinate: %.5lf || y coordinate: %.5lf || Location: %s \n\n", key , data->censusYear, data->blockID, data->propertyID, data->basePropertyID, data->CLUESmallArea, data->industryCode, data->industryDescription, data->XCoordinate, data->YCoordinate, data->location );
        data = data->nextData;
    }
}
