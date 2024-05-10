#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate hash based on the key
unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to initialize the hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Function to insert a key-data pair into the hash table
void insertHashTable(int key, char *data) {
    unsigned int index = hashFunction(key);
    HashTableEntry *entry = (HashTableEntry *) malloc(sizeof(HashTableEntry));
    if (!entry) {
        fprintf(stderr, "Failed to allocate memory for hash table entry\n");
        return;
    }
    entry->data = strdup(data);
    if (!entry->data) {
        fprintf(stderr, "Failed to duplicate data for hash table entry\n");
        free(entry); // Prevent memory leak by freeing allocated entry
        return;
    }
    entry->key = key;
    entry->next = hashTable[index];
    hashTable[index] = entry;
}

// Function to search for a data by key in the hash table
char* searchHashTable(int key) {
    unsigned int index = hashFunction(key);
    HashTableEntry *entry = hashTable[index];
    while (entry) {
        if (entry->key == key) {
            return entry->data;
        }
        entry = entry->next;
    }
    return NULL; // Key not found
}

// Function to delete a key-data pair from the hash table
void deleteHashTable(int key) {
    unsigned int index = hashFunction(key);
    HashTableEntry *current = hashTable[index];
    HashTableEntry *prev = NULL;

    while (current) {
        if (current->key == key) {
            if (prev) {
                prev->next = current->next;
            } else {
                hashTable[index] = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

// Function to print all key-data pairs in the hash table
void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashTableEntry *entry = hashTable[i];
        if (entry != NULL) {
            printf("Bucket %d: ", i);
            while (entry) {
                printf("(%d, %s) ", entry->key, entry->data);
                entry = entry->next;
            }
            printf("\n");
        }
    }
}
