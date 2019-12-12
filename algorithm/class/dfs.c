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

typedef struct Graph {
    int (*adjMatrix)[MAX];
    int pointNum;
} graph;

void dfs(graph* g, int start) {
    int vis[MAX] = {0};
    //是否访问
    int* data = (int*)calloc(MAX, sizeof(int));
    stack s = {data, MAX, 0};
    //利用栈模拟递归，其实递归就是栈，只不过是利用了系统栈。
    push(&s, start);
    vis[start] = 1;
    while (!isEmpty(&s)) {
        int curr = pop(&s);
        //因为从下标0开始
        printf("%d-", curr+1);
        //反向遍历。ppt的结果是先1-2-5-3-4-6，其实正向遍历也一样，但是结果不同，dfs的结果是不唯一的。
        for (int i=g->pointNum-1; i >=0; i--) {
            if (g->adjMatrix[curr][i] && !vis[i]) {
                vis[i] = 1;
                push(&s, i);
            }
        }
    }
}

int main() {
    int adjMatrix[MAX][MAX] = { {0, 1, 1, 1, 0, 0},
                                {1, 0, 0, 0, 1, 0},
                                {1, 0, 0, 0, 1, 0},
                                {1, 0, 0, 0, 0, 1},
                                {0, 1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 0, 0} };
    graph g = {adjMatrix};
    g.pointNum = 6;
    //这是指定的起点
    int start = 0;
    dfs(&g, start);
}