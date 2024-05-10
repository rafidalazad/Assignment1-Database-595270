#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new AVL node
AVLNode* newAVLNode(int key, char *data) {
    AVLNode *node = (AVLNode*) malloc(sizeof(AVLNode));
    if (!node) {
        fprintf(stderr, "Error allocating memory for new AVL Node\n");
        return NULL;
    }
    node->data = strdup(data);
    if (!node->data) {
        fprintf(stderr, "Error duplicating string for AVL Node data\n");
        free(node);
        return NULL;
    }
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

// Function to get the height of an AVL node
int height(AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

// Helper function to get the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to right rotate subtree rooted with y
AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to left rotate subtree rooted with x
AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a key in the subtree rooted with node and returns the new root
AVLNode* insertAVLNode(AVLNode* node, int key, char *data) {
    if (node == NULL)
        return newAVLNode(key, data);

    if (key < node->key)
        node->left = insertAVLNode(node->left, key, data);
    else if (key > node->key)
        node->right = insertAVLNode(node->right, key, data);
    else // Duplicate keys not allowed
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);

    // Check this node's balance and rotate if necessary
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

// Utility function to find the node with the minimum key value
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Recursive function to delete a node
AVLNode* deleteAVLNode(AVLNode* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteAVLNode(root->left, key);
    else if (key > root->key)
        root->right = deleteAVLNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp->data);
            free(temp);
        } else {
            AVLNode* temp = minValueNode(root->right);
            free(root->data); // Free old data
            root->data = strdup(temp->data);
            root->key = temp->key;
            root->right = deleteAVLNode(root->right, temp->key);
        }
    }

    if (root == NULL)
      return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = height(root->left) - height(root->right);

    // Rebalance the tree
    if (balance > 1 && (height(root->left->left) - height(root->left->right)) >= 0)
        return rightRotate(root);
    if (balance > 1 && (height(root->left->left) - height(root->left->right)) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && (height(root->right->right) - height(root->right->left)) >= 0)
        return leftRotate(root);
    if (balance < -1 && (height(root->right->right) - height(root->right->left)) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Print the tree in inorder
void printInOrderAVL(AVLNode *root) {
    if (root != NULL) {
        printInOrderAVL(root->left);
        printf("%d (%s) ", root->key, root->data);
        printInOrderAVL(root->right);
    }
}

