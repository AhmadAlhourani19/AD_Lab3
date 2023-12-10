#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

//Macros
#define MAX_ARRAY 50
#define MAX_STRING 30
#define MAX_LINE 100

// Define the data structure for an element in chained hashing
typedef struct sElementCH {
    int key;
    char value[MAX_STRING];
    struct sElementCH* next; // Pointer to the next element in the linked list
} sElementCH;

int readInt();
int hashing(int key);

/**********************************************************************************************************************
Prototypes for address hashing
**********************************************************************************************************************/
/*
Function creates a new entry in the hash table or if the key already exists overwrites the value with the passed value.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be inserted.
value: The value for the key that should be inserted.

Return value:
Function returns the number of collisions when inserting the key-value pair.
*/
int putCH(sElementCH* hashtableCH[MAX_ARRAY], int key, char value[MAX_STRING]);
/*
Function searches for the key-value pair in the hash table having the passed key.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be searched for in the hash table.

Return value:
Function returns the value of entry with the given key or NULL if the key does not exist in the hash table.
*/
char* getCH(sElementCH* hashtableCH[MAX_ARRAY], int key);

/*
Function prints the hash table on the console.

Input parameters:
hashtableAH: Function gets a hash table.

Return value:
none
*/
void printHashTableCH(sElementCH* hashtableCH[MAX_ARRAY]);
/*
Function reads key-value pairs from a csv-files and stores these pairs in a hash table.

Input parameters:
fp: Function gets a file pointer to a csv-file which contains some key-value-pairs.
hashtableAH: Function gets a hash table.

Return value:
none
*/
void readCSVAH(FILE* fP, sElementCH* hashtableCH[MAX_ARRAY]);

int divisionHashing(int key);

int foldingHashing(int key);

int xorHashing(int key);

int multiplicativeHashing(int key);