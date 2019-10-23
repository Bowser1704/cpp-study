#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000;

int n, G[MAXN][MAXN];
int inq[MAXN] = {0};

void BFS(int u) {
    queue<int> q;
    q.push(u);
    inq[u] = 1;
    while (!q.empty()) {
        int u = q.front;
        q.pop();
        for (int v=0; v<n; v++) {
            if (!inq[v] && G[u][v] == 1<<31) {
                q.push(v);
                inq[v] = 1;
            }
        }
    }
}

void BFSTrave() {
    for (int u=0; u<n; u++) {
        if (!inq[u])    BFS(u);
    }
}