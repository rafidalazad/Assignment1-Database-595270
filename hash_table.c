#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

void insertHashTable(int key, char *data) {
    unsigned int index = hashFunction(key);
    HashTableEntry *entry = (HashTableEntry *) malloc(sizeof(HashTableEntry));
    entry->key = key;
    entry->data = strdup(data);
    entry->next = hashTable[index];
    hashTable[index] = entry;
}

char* searchHashTable(int key) {
    unsigned int index = hashFunction(key);
    HashTableEntry* entry = hashTable[index];
    while (entry != NULL) {
        if (entry->key == key)
            return entry->data;
        entry = entry->next;
    }
    return NULL; // Not found
}

void deleteHashTable(int key) {
    unsigned int index = hashFunction(key);
    HashTableEntry* current = hashTable[index];
    HashTableEntry* prev = NULL;
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                hashTable[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashTableEntry *entry = hashTable[i];
        if (entry != NULL) {
            printf("Bucket %d: ", i);
            while (entry != NULL) {
                printf("(%d, %s) ", entry->key, entry->data);
                entry = entry->next;
            }
            printf("\n");
        }
    }
}

