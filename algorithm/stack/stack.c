#include <stdlib.h>
#include <malloc.h>
#include "stack.h"

stack createStack(){
    stack S = (pNode)malloc(sizeof(node));
    if (S == NULL)  printf("error");
    else{
    S->next = NULL;
    return S;
    }
}

void destoryStack(stack S){
    stack temp;
    while (S->next != NULL)
    {
        temp = S->next;
        S->next = temp->next;
        free(temp);
    }
    free(S);
}

void push(int var, stack S){
    stack temp = (stack)malloc(sizeof(node));
    if (temp == NULL) printf("error");
    else{
        temp->data = var;
        temp->next = S->next;
        S->next = temp;
    }
}

int pop(stack S){
    int x;
    stack temp;
    if (S->next == NULL)   printf("error");
    else
    {
        temp = S->next;
        x = temp->data;
        S->next = temp->next;
        free(temp);
        return x;
    }
}