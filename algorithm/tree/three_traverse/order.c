#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} node;

void inOrder(node* root) {
    node* curr = root;
    if (curr != NULL) {
        inOrder(curr->left);
        printf("current order--> %d\n", curr->val);
        inOrder(curr->right);
    }
}

void preOrder(node* root) {
    node* curr = root;
    if (curr != NULL) {
        printf("current order--> %d\n", curr->val);
        preOrder(curr->left);
        preOrder(curr->right);
    }
}

void postOrder(node* root) {
    node* curr = root;
    if (curr != NULL) {
        postOrder(curr->left);
        postOrder(curr->right);
        printf("current order--> %d\n", curr->val);
    }
}
int count = 0;
node* create() {
    node* root;
    if (count >= 10) {
        root = NULL;
    } else {
        root = (node*)malloc(sizeof(node));
        root->val = count++;
        root->left = create();
        root->right = create();
    }
    return root;
}

int main() {
    count = 0;
    // node* root = (node*) malloc(sizeof(node));
    node* root = create();

    preOrder(root);
    inOrder(root);
    postOrder(root);
    return 0;
}