// Program to mirror a binary tree
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void mirror(struct Node* root) {
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);

    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal of original tree: ");
    inorder(root);
    printf("\n");

    mirror(root);

    printf("Inorder traversal of mirrored tree: ");
    inorder(root);
    printf("\n");

    return 0;
}
