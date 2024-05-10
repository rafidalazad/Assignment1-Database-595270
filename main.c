#include <stdio.h>
#include <stdlib.h>
#include <time.h>        // For timing operations
#include "avl_tree.h"
#include "hash_table.h"

// Forward declarations for helper functions
void populateAVLTree(AVLNode **root, int numNodes);
void populateHashTable(int numEntries);
void freeAVLTree(AVLNode *node); // Ensure this function exists to free AVL tree
void freeHashTable(void);        // Ensure this function fully cleans up the hash table

// Helper function to measure performance
double measurePerformance(void (*func)(void *), void *arg);

int main() {
    AVLNode *root = NULL; // Root of the AVL Tree
    int numNodes = 100;   // Number of nodes to generate for the AVL Tree
    int numEntries = 100; // Number of entries for the Hash Table

    // Initialize Hash Table
    initHashTable(); // Ensure this function sets up the hash table properly

    // Measure performance of populating the AVL Tree
    double timeTakenAVL = measurePerformance((void (*)(void *))populateAVLTree, &root);
    printf("Time taken to populate AVL Tree: %.6f seconds\n", timeTakenAVL);

    // Measure performance of populating the Hash Table
    double timeTakenHash = measurePerformance((void (*)(void *))populateHashTable, &numEntries);
    printf("Time taken to populate Hash Table: %.6f seconds\n", timeTakenHash);

    // Display the contents
    printf("AVL Tree in order:\n");
    printInOrderAVL(root);
    printf("\nHash Table contents:\n");
    printHashTable();

    // Cleanup
    freeAVLTree(root);    // Free all nodes in the AVL tree
    freeHashTable();      // Free all entries in the hash table

    return 0;
}

void populateAVLTree(AVLNode **root, int numNodes) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < numNodes; i++) {
        int key = rand() % 1000;
        char data[50];
        sprintf(data, "Song %d", key);
        *root = insertAVLNode(*root, key, data);
    }
}

void populateHashTable(int numEntries) {
    srand(time(NULL)); // Ensure random behavior is reproducible run-to-run
    for (int i = 0; i < numEntries; i++) {
        int key = rand() % 1000;
        char data[50];
        sprintf(data, "Playlist %d", key);
        insertHashTable(key, data);
    }
}

// Generic function to measure the performance of a function
double measurePerformance(void (*func)(void *), void *arg) {
    clock_t start, end;
    start = clock();
    func(arg);
    end = clock();
    return (double)(end - start) / CLOCKS_PER_SEC;
}

