#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Stack {
    int* data;
    int capacity;
    int size;
} stack;

int isEmpty(stack* s) {
    return s->size == 0;
}

void push(stack* s, int value) {
    s->data[(s->size)++] = value;
}

int pop(stack* s) {
    return s->data[--(s->size)];
}

typedef struct ListNode {
    char val;
    struct ListNode *left, *right;
} listNode;

listNode* create(char* s) {
    listNode* root = (listNode*)malloc(sizeof(listNode));
    listNode* startNode = root;
    root->val = s[0];
    int i = 1;
    while (s[i] == '#' && s[i+1] == '#') {
        startNode->left = (listNode*)malloc(sizeof(listNode));
        startNode->right = (listNode*)malloc(sizeof(listNode));
    }
}

int main() {
   
}