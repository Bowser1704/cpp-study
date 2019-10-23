#ifndef STACK_H
#define STACK_H

typedef struct node
{
    int data;
    struct node* next;
}node, *pNode;
typedef pNode stack;

stack createStack();
void destoryStack(stack S);
void push(int var, stack S);
stack pop(stack S);

#endif