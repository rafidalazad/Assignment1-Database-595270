#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"
#include "hash_table.h"

// Forward declarations for helper functions
void populateAVLTree(AVLNode **root, int numNodes);
void populateHashTable(int numEntries);
void freeAVLTree(AVLNode *node); // Assuming this function exists to free AVL tree

int main() {
    AVLNode *root = NULL; // Root of the AVL Tree
    int numNodes = 100;   // Number of nodes to generate for the AVL Tree
    int numEntries = 100; // Number of entries for the Hash Table

    // Initialize Hash Table
    initHashTable(); // Ensure this function sets up the hash table properly

    // Populate AVL Tree with random data
    populateAVLTree(&root, numNodes);

    // Populate Hash Table with random data
    populateHashTable(numEntries);

    // Print the contents of the AVL Tree
    printf("AVL Tree in order:\n");
    printInOrderAVL(root); // Ensure this function prints elements in-order
    printf("\n");

    // Print the contents of the Hash Table
    printf("Hash Table contents:\n");
    printHashTable(); // Ensure this function prints all hash table entries

    // Cleanup
    freeAVLTree(root);    // Free all nodes in the AVL tree
    freeHashTable();      // Assuming a function to free all entries in the hash table

    return 0;
}

void populateAVLTree(AVLNode **root, int numNodes) {
    for (int i = 0; i < numNodes; i++) {
        int key = rand() % 1000; // Generate a random key
        char data[50];
        sprintf(data, "Song %d", key); // Create a string for song data
        *root = insertAVLNode(*root, key, data); // Insert the node in the AVL tree
    }
}

void populateHashTable(int numEntries) {
    for (int i = 0; i < numEntries; i++) {
        int key = rand() % 1000; // Generate a random key
        char data[50];
        sprintf(data, "Playlist %d", key); // Create a string for playlist data
        insertHashTable(key, data); // Insert the entry in the hash table
    }
}
