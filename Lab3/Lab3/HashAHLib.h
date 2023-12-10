#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "string.h"


//Macros
#define MAX_ARRAY 50
#define MAX_STRING 30
#define MAX_LINE 100


//Data type for address hashing
typedef struct sElementAH {
	int key;
	char value[MAX_STRING];
} sElementAH;


/*
Function reads an integer value safely from the keyboard.

Return value:
Read integer value
*/
int readInt();

/*
Function calculates the hash value for the passed key.

Input parameters:
key: The integer for which the hash value should be calculated.

Return value:
Calculated hash value for parameter key.
*/
int hashing(int key);
int multiplicativeHashing(int key);
int xorHashing(int key);
int foldingHashing(int key);

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
int putAH(sElementAH hashtableAH[MAX_ARRAY], int key, char value[MAX_STRING]);

/*
Function searches for the key-value pair in the hash table having the passed key.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be searched for in the hash table.

Return value:
Function returns the value of entry with the given key or NULL if the key does not exist in the hash table.
*/
char* getAH(sElementAH hashtableAH[MAX_ARRAY], int key);

/*
Function searches for the entry in the hash table having the passed key.
If it finds an entry the function deletes it from the hash table.

Input parameters:
hashtableAH: Function gets a hash table.
key: The key that should be searched for in the hash table and whose key-value pair should be deleted.

Return value:
none
*/
void deleteAH(sElementAH hashtableAH[MAX_ARRAY], int key);

/*
Function prints the hash table on the console.

Input parameters:
hashtableAH: Function gets a hash table.

Return value:
none
*/
void printHashTableAH(sElementAH hashtableAH[MAX_ARRAY]);

/*
Function reads key-value pairs from a csv-files and stores these pairs in a hash table.

Input parameters:
fp: Function gets a file pointer to a csv-file which contains some key-value-pairs.
hashtableAH: Function gets a hash table.

Return value:
none
*/
void readCSVAH(FILE* fP, sElementAH hashtableAH[MAX_ARRAY]);

