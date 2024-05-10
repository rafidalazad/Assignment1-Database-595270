#include "../include/avl_tree.h"
#include <assert.h>
#include <stdio.h>

void test_insertion() {
    AVLNode *root = NULL;
    root = insertAVLNode(root, 10, "Song 10");
    root = insertAVLNode(root, 20, "Song 20");
    root = insertAVLNode(root, 5, "Song 5");
    assert(root->key == 10);
    printf("Test Insertion Passed\n");
}

void test_deletion() {
    AVLNode *root = NULL;
    root = insertAVLNode(root, 10, "Song 10");
    root = insertAVLNode(root, 20, "Song 20");
    root = insertAVLNode(root, 5, "Song 5");
    root = deleteAVLNode(root, 10);
    assert(root->key != 10);
    printf("Test Deletion Passed\n");
}

void test_in_order_traversal() {
    AVLNode *root = NULL;
    root = insertAVLNode(root, 10, "Song 10");
    root = insertAVLNode(root, 20, "Song 20");
    root = insertAVLNode(root, 5, "Song 5");
    printf("In-Order Traversal: ");
    printInOrderAVL(root);
    printf("\nTest In-Order Traversal Passed\n");
}

int main() {
    test_insertion();
    test_deletion();
    test_in_order_traversal();
    return 0;
}
