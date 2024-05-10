#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"
#include "hash_table.h"

void populateAVLTree(AVLNode **root, int numNodes);
void populateHashTable(int numEntries);

int main() {
    AVLNode *root = NULL;
    int numNodes = 100;  // Number of nodes to generate for AVL Tree
    int numEntries = 100; // Number of entries for Hash Table

    // Populate AVL Tree with random data
    populateAVLTree(&root, numNodes);

    // Initialize Hash Table
    initHashTable();
    populateHashTable(numEntries);

    // Assuming functions to print the structures are defined
    printf("AVL Tree in order:\n");
    printInOrderAVL(root);
    printf("\n");

    printf("Hash Table contents:\n");
    printHashTable();

    // Clean up
    freeAVLTree(root);
    freeHashTable();

    return 0;
}

void populateAVLTree(AVLNode **root, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        int key = rand() % 1000;
        char data[50];
        sprintf(data, "Song %d", key);
        *root = insertAVLNode(*root, key, data);
    }
}

void populateHashTable(int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        int key = rand() % 1000;
        char data[50];
        sprintf(data, "Playlist %d", key);
        insertHashTable(key, data);
    }
}
