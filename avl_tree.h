#ifndef AVL_TREE_H
#define AVL_TREE_H

// Define the structure for an AVL Tree node.
typedef struct AVLNode {
    int key;               // Key for the AVL node
    char *data;            // Data stored in the node
    struct AVLNode *left;  // Pointer to the left child
    struct AVLNode *right; // Pointer to the right child
    int height;            // Height of the node
} AVLNode;

// Function prototypes for AVL tree operations.
AVLNode* newAVLNode(int key, char *data);
AVLNode* insertAVLNode(AVLNode* node, int key, char *data);
AVLNode* deleteAVLNode(AVLNode* root, int key);
void printInOrderAVL(AVLNode *root);
int height(AVLNode *N);
int max(int a, int b);
AVLNode *rightRotate(AVLNode *y);
AVLNode *leftRotate(AVLNode *x);
AVLNode* minValueNode(AVLNode* node);

#endif // AVL_TREE_H
