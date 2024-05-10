#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_tree.h"

// Helper function to create a new node
AVLNode* newAVLNode(int key, char *data) {
    AVLNode *node = (AVLNode*) malloc(sizeof(AVLNode));
    node->key = key;
    node->data = strdup(data);
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Function to get the height of the tree
int height(AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Right rotate utility function
AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotate utility function
AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Insert a node in the AVL tree
AVLNode* insertAVLNode(AVLNode* node, int key, char *data) {
    // Normal BST insertion
    if (node == NULL)
        return newAVLNode(key, data);
    if (key < node->key)
        node->left = insertAVLNode(node->left, key, data);
    else if (key > node->key)
        node->right = insertAVLNode(node->right, key, data);
    else // Duplicate keys not allowed
        return node;

    // Update height of this ancestor node
    node->height = 1 + max(height(node->left), height(node->right));

    // Get balance factor to check whether this node became unbalanced
    int balance = height(node->left) - height(node->right);

    // If unbalanced, then 4 cases
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

// A utility function to print the tree in in-order
void printInOrderAVL(AVLNode *root) {
    if (root != NULL) {
        printInOrderAVL(root->left);
        printf("%d ", root->key);
        printInOrderAVL(root->right);
    }
}

