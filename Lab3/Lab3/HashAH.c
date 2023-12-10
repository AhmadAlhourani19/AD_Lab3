#include <stdio.h>
#include "HashAHLib.h"

int main() {
	//Variables
	int choice = 0;
	int key = -1;
	char value[MAX_STRING];
	char* valuePointer = NULL;
	int counter;

	//Open csv-file
	errno_t err;
	FILE* fP = NULL;
	err = fopen_s(&fP, "students.csv", "r");
	if ((err != 0) || (fP == NULL)) {
		printf("CSV file could not be opend.\n");
		exit(1);
	}

	//Welcome and choice of collision strategy
	printf("Welcome to our Hashing program!\n");
	printf("What kind of collision strategy do you prefer?\n1: Address Hashing\n2: Chained Hashing\nAny other choice: exit program\n");
	choice = readInt();

	switch (choice) {
	case 1:
		//Create a hash table and initialize it
		sElementAH hashtableAH[MAX_ARRAY];
		for (int i = 0; i < MAX_ARRAY; i++) {
			hashtableAH[i].key = -1;
			strcpy_s(hashtableAH[i].value, MAX_STRING, "");
		}

		//Read in the key-value-pairs from the csv-file and print the hash table
		readCSVAH(fP, hashtableAH);
		printHashTableAH(hashtableAH);

		//User can choose what to do next
		printf("OK, lets do Hashing using Address Hashing strategy:-)\n");
		do {
			printf("What do you like to do?\n1: Adding new element\n2: Searching for an element\n3: Delete key\nAny other choice: exit program\n");
			choice = readInt();
			switch (choice) {
				//Adding a new element to the hash table
			case 1:
				printf("Type in the key: \n");
				key = readInt();
				printf("\nType in the value: \n");
				scanf_s("%s", value, MAX_STRING);
				counter = putAH(hashtableAH, key, value);
				printHashTableAH(hashtableAH);
				printf("There were %d collision(s).\n", counter);
				break;
				//Searching for an element
			case 2:
				printf("Type in the key: \n");
				key = readInt();
				valuePointer = getAH(hashtableAH, key);
				if (valuePointer == NULL)
					printf("Key not found in hashtable\n");
				else
					printf("Value is %s\n", valuePointer);
				valuePointer = NULL;
				break;
				//Delete a key-value pair if it exists
			case 3:
				printf("Type in the key: \n");
				key = readInt();
				deleteAH(hashtableAH, key);
				printHashTableAH(hashtableAH);
				break;
				//Exit program
			default:
				return 0;
			}
		} while (1);
		break;
	case 2:
		//Todo: Assignment 3.2
		break;
	default:
		//Close file
		if (fP != NULL)
			fclose(fP);
		return 0;
	}
}