#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 100 // Define the size of the hash table

// Define the structure for hash table entries.
typedef struct HashTableEntry {
    int key;                         // Key of the entry
    char *data;                      // Data associated with the key
    struct HashTableEntry *next;     // Pointer to the next entry (for chaining)
} HashTableEntry;

HashTableEntry* hashTable[TABLE_SIZE]; // Array of pointers to hash table entries

// Function prototypes for hash table operations.
unsigned int hashFunction(int key);
void initHashTable();
void insertHashTable(int key, char *data);
char* searchHashTable(int key);
void deleteHashTable(int key);
void printHashTable();

#endif // HASH_TABLE_H
