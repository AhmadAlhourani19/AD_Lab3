
#include <stdio.h>
#include "HashCHLib.h"

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
	if ((err != 0) || (fP == NULL))
	{
		//perror("Error");		// prints the error
		printf("CSV file could not be opend.\n");
		exit(1);
	}

	//Welcome and choice of collision strategy
	printf("Welcome to our Hashing program!\n");
	printf("What kind of collision strategy do you prefer?\n1: Address Hashing\n2: Chained Hashing\nAny other choice: exit program\n");
	choice = readInt();

	switch (choice) {
	case 1:;

	case 2:;
		//Create a hash table and initialize it
		// Create a hash table and initialize it
		sElementCH* hashtableCH[MAX_ARRAY];

		for (int i = 0; i < MAX_ARRAY; i++) {
			// Allocate memory for each element
			hashtableCH[i] = (sElementCH*)malloc(sizeof(sElementCH));
			if (hashtableCH[i] == NULL) {
				// Handle memory allocation failure
				printf("Memory allocation failed.\n");
				exit(1);
			}

			// Initialize the key and value
			hashtableCH[i]->key = -1;
			strcpy_s(hashtableCH[i]->value, MAX_STRING, "");
		}

		//Read in the key-value-pairs from the csv-file and print the hash table
		readCSVAH(fP, hashtableCH);
		printHashTableCH(hashtableCH);

		//User can choose what to do next
		printf("OK, lets do Hashing using Address Hashing strategy:-)\n");
		do {
			printf("What do you like to do?\n1: Adding new element\n2: Searching for an element\nAny other choice: exit program\n");
			choice = readInt();
			switch (choice) {
				//Adding a new element to the hash table
			case 1:
				printf("Type in the key: \n");
				key = readInt();
				printf("\nType in the value: \n");
				scanf_s("%s", value, MAX_STRING);
				counter = putCH(hashtableCH, key, value);
				printHashTableCH(hashtableCH);
				printf("There were %d collision(s).\n", counter);
				break;
				//Searching for an element
			case 2:
				printf("Type in the key: \n");
				key = readInt();
				valuePointer = getCH(hashtableCH, key);
				if (valuePointer == NULL)
					printf("Key not found in hashtable\n");
				else
					printf("Value is %s\n", valuePointer);
				valuePointer = NULL;
				break;
			default:
				return 0;
			}
		} while (1);
		break;

	default:
		//Close file
		if (fP != NULL)
			fclose(fP);
		return 0;
	}
}