#include "../include/avl_tree.h"
#include "../include/hash_table.h"
#include <stdio.h>

void test_avl_and_hash_interaction() {
    AVLNode *avlRoot = NULL;
    avlRoot = insertAVLNode(avlRoot, 10, "Song 10");
    avlRoot = insertAVLNode(avlRoot, 20, "Song 20");

    initHashTable();
    insertHashTable(10, "Playlist containing Song 10 and Song 20");
    char *data = searchHashTable(10);
    printf("AVL and Hash Interaction: %s\n", data);
    assert(data != NULL && strcmp(data, "Playlist containing Song 10 and Song 20") == 0);
    printf("Test AVL and Hash Table Interaction Passed\n");
}

int main() {
    test_avl_and_hash_interaction();
    return 0;
}
