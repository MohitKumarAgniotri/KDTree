
#ifndef data_h
#define data_h

#include <stdio.h>


struct KeyDataPair 
{
    char *key;
    struct Data *d;    
};

// struct to store data
struct Data
{
    // the census year
    int censusYear;
    
    // the block ID
    int blockID;
    
    // the property ID
    int propertyID;
    
    // the base prorperty ID
    int basePropertyID;
    
    // the clue small area
    char *CLUESmallArea;
    
    // the industry code
    int industryCode;
    
    // the industry description
    char *industryDescription;
    
    // the x coodrinate
    double XCoordinate;
    
    // the y coodrinate
    double YCoordinate;
    
    // the location
    char *location;

    struct Data *nextData;
};

// the method is to get a line and return the the data parsed from the line
struct KeyDataPair * getData(char * line);

// the method to print data to file
void printKData(char *key, struct Data * data, FILE * fp);

void printData(char *key, struct Data * data, FILE * fp);

#endif /* data_h */
