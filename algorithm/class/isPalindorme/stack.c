#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    int test = 123321;
    int result = test;
    int* data = (int*)calloc(10 ,sizeof(int));
    stack s = {data, 10, 0};
    while (test) {
        int temp = test % 10;
        push(&s, temp);
        test /= 10;
    }
    int val = 0;
    while (!isEmpty(&s)) {
        val = val * 10 + pop(&s);
    }
    if (val == result) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}