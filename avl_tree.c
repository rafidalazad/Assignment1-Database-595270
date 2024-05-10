#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

AVLNode* newAVLNode(int key, char *data) {
    AVLNode *node = (AVLNode*) malloc(sizeof(AVLNode));
    node->key = key;
    node->data = strdup(data);
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

int height(AVLNode *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLNode *rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode *leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* insertAVLNode(AVLNode* node, int key, char *data) {
    if (node == NULL)
        return newAVLNode(key, data);
    if (key < node->key)
        node->left = insertAVLNode(node->left, key, data);
    else if (key > node->key)
        node->right = insertAVLNode(node->right, key, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);

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

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

AVLNode* deleteAVLNode(AVLNode* root, int key) {
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteAVLNode(root->left, key);
    else if (key > root->key)
        root->right = deleteAVLNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->key = temp->key;
            root->data = strdup(temp->data);
            root->right = deleteAVLNode(root->right, temp->key);
        }
    }

    if (root == NULL)
      return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = height(root->left) - height(root->right);

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

void printInOrderAVL(AVLNode *root) {
    if (root != NULL) {
        printInOrderAVL(root->left);
        printf("%d ", root->key);
        printInOrderAVL(root->right);
    }
}

