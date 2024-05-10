#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define TABLE_SIZE 100 // Define the size of the hash table

// Structure for hash table entries.
typedef struct HashTableEntry {
    int key;                         // Key of the entry
    char *data;                      // Data associated with the key
    struct HashTableEntry *next;     // Pointer to the next entry (for chaining)
} HashTableEntry;

HashTableEntry* hashTable[TABLE_SIZE]; // Array of pointers to hash table entries

/**
 * Calculates the hash index for a given key.
 * @param key The key for which the hash index is to be calculated.
 * @return The hash index for the key.
 */
unsigned int hashFunction(int key);

/**
 * Initializes the hash table by setting all entries to NULL.
 * This should be called before the hash table is used.
 */
void initHashTable();

/**
 * Inserts a key-data pair into the hash table. If an entry with the same key
 * already exists, this function does not modify the existing entry.
 * @param key The key of the data to insert.
 * @param data The data to be associated with the key. This function duplicates
 * the data string.
 * @note If memory allocation fails, logs an error and the entry is not inserted.
 */
void insertHashTable(int key, char *data);

/**
 * Searches for the data associated with a key in the hash table.
 * @param key The key whose data is to be searched.
 * @return A pointer to the data if the key is found, NULL otherwise.
 */
char* searchHashTable(int key);

/**
 * Deletes the entry with the specified key from the hash table, if it exists.
 * @param key The key of the entry to delete.
 * @note Frees memory associated with the entry's data and the entry itself.
 */
void deleteHashTable(int key);

/**
 * Prints all the entries in the hash table. Each entry's key and data are displayed.
 * Entries within each bucket are shown in their linked list order.
 */
void printHashTable();

#endif // HASH_TABLE_H

