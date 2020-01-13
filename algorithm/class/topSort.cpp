#include <iostream>
#include <queue>
using namespace std;

void topoSortByKahn() {
    int* inDegree = new int[v];  // 统计每个顶点的入度
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < adj[i].size(); ++j) {
            int w = adj[i].get(j);  // i->w
            inDegree[w]++;
        }
    }
    
    for (int i = 0; i < v; ++i) {
        if (inDegree[i] == 0) queue.add(i);
    }
    while (!queue.isEmpty()) {
        int i = queue.remove();
        cout << "->"  << i;
        for (int j = 0; j < adj[i].size(); ++j) {
            int k = adj[i].get(j);
            inDegree[k]--;
            if (inDegree[k] == 0) queue.add(k);
        }
    }
}