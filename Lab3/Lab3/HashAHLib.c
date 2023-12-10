#pragma once

#include "HashAHLib.h"

// Function to read an integer value safely from the keyboard.
int readInt() {
    int number, test = 0;
    do {
        test = scanf_s("%d", &number);
        if (test != 1) {
            while (getchar() != '\n');
            printf("Wrong input. Try again.\n");
        }
        else
            return number;
    } while (1);
}

// Function to calculate the hash value for the passed key using simple division hashing.
int hashing(int key) {
    return key % MAX_ARRAY;
}

// Additional hash functions for experimentation

// Function to calculate the hash value using folding hashing.
int foldingHashing(int key) {
    int sum = 0;
    while (key > 0) {
        sum += key % 1000; // Extract a three-digit portion
        key /= 1000; // Move to the next portion
    }
    return sum % MAX_ARRAY;
}

// Function to calculate the hash value using XOR hashing.
int xorHashing(int key) {
    key = (key >> 16) ^ key; // XOR upper and lower 16 bits
    key = (key >> 8) ^ key;  // XOR upper and lower 8 bits
    return key % MAX_ARRAY;
}

// Function to calculate the hash value using multiplicative hashing.
int multiplicativeHashing(int key) {
    const double A = 0.6180339887; // Golden ratio constant
    double fraction = key * A - (int)(key * A); // Extract fractional part
    return (int)(MAX_ARRAY * fraction);
}

/**********************************************************************************************************************
Prototypes for address hashing
**********************************************************************************************************************/

// Function to create a new entry in the hash table or overwrite the value if the key already exists.
int putAH(sElementAH hashtableAH[MAX_ARRAY], int key, char value[MAX_STRING]) {
    int collisions = 0;
    int index = hashing(key); // Choose the desired hash function here (e.g., foldingHashing(key))

    while (hashtableAH[index].key != -1 && hashtableAH[index].key != key) {
        index = (index + 1) % MAX_ARRAY;  // Linear probing to find an empty slot or the same key
        collisions++;
    }

    hashtableAH[index].key = key;
    strcpy_s(hashtableAH[index].value, MAX_STRING, value);

    return collisions;
}

// Function to search for the key-value pair in the hash table with the passed key.
char* getAH(sElementAH hashtableAH[MAX_ARRAY], int key) {
    int index = hashing(key); // Choose the desired hash function here (e.g., foldingHashing(key))

    while (hashtableAH[index].key != -1) {
        if (hashtableAH[index].key == key) {
            return hashtableAH[index].value;
        }
        index = (index + 1) % MAX_ARRAY;  // Linear probing to find the entry with the given key
    }

    return NULL; // Key not found
}

// Function to search for the entry in the hash table with the passed key and delete it.
void deleteAH(sElementAH hashtableAH[MAX_ARRAY], int key) {
    int index = hashing(key); // Choose the desired hash function here (e.g., foldingHashing(key))

    while (hashtableAH[index].key != -1) {
        if (hashtableAH[index].key == key) {
            // Delete the entry by marking it as empty
            hashtableAH[index].key = -1;
            strcpy_s(hashtableAH[index].value, MAX_STRING, "");
            return;
        }
        index = (index + 1) % MAX_ARRAY;  // Linear probing to find the entry with the given key
    }
    // Key not found, do nothing
}

// Function to print the hash table on the console.
void printHashTableAH(sElementAH hashtableAH[MAX_ARRAY]) {
    for (int i = 0; i < MAX_ARRAY; i++) {
        if (hashtableAH[i].key != -1) {
            printf("Index %d: Key=%d, Value=%s\n", i, hashtableAH[i].key, hashtableAH[i].value);
        }
        else {
            printf("Index %d: Empty\n", i);
        }
    }
}

// Function to read key-value pairs from a csv-file and store these pairs in a hash table.
void readCSVAH(FILE* fP, sElementAH hashtableAH[MAX_ARRAY]) {
    int number = 0;
    char buffer[MAX_LINE];
    char* field;
    char* nextToken = NULL;
    int key;
    char string[MAX_STRING];

    if (fP == NULL) {
        printf("File does not exist.");
        exit(0);
    }
    else
        // Get number of lines
        while (!feof(fP)) {
            char ch = fgetc(fP);
            if (ch == '\n')
                number++;
        }

    if (fP != NULL)
        rewind(fP);

    for (int i = 0; i < number; i++) {
        fgets(buffer, MAX_LINE, fP);

        field = strtok_s(buffer, ";", &nextToken);
        key = atoi(field);

        field = strtok_s(NULL, ";", &nextToken);
        strcpy_s(string, MAX_STRING, field);
        // Replace \n in name
        string[strlen(string) - 1] = '\0';

        putAH(hashtableAH, key, string);
    }
}
