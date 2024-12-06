
#include <stdio.h>
#include <stdlib.h>

struct nodeTree {
    int value;
    struct nodeTree* left;
    struct nodeTree* right;
    struct nodeTree* nextSibling;
};

struct nodeTree* binaryTreeToLCRS(struct nodeTree* root) {
    if (root == NULL) {
        return NULL;
    }

    struct nodeTree* lcrsRoot = (struct nodeTree*)malloc(sizeof(struct nodeTree));
    lcrsRoot->value = root->value;
    lcrsRoot->left = binaryTreeToLCRS(root->left);
    lcrsRoot->right = binaryTreeToLCRS(root->right);
    lcrsRoot->nextSibling = NULL;

    if (lcrsRoot->left != NULL) {
        struct nodeTree* temp = lcrsRoot->left;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = lcrsRoot->right;
    }

    return lcrsRoot;
}

