#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 501;
const int INF = 0x3fffffff;

int N, M, st, ed, G[MAXN][MAXN], weight[MAXN];
int d[MAXN], w[MAXN], num[MAXN];
bool vis[MAXN]={false};

void Djikstra(int s) {
    fill(d, d+MAXN, INF);   //fill and memset
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;       //标志s为起点
    w[s] = weight[s];
    num[s] = 1;
    for (int i=0; i<N; i++){
        int u=-1, MIN=INF;      //每次循环都格式化一下min
        for (int j=0; j<N; j++) {
            if (!vis[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u==-1)  return ;
        vis[u] = true;
        for (int v=0; v<N; v++) {
            if (!vis[v] && G[u][v] != INF) {
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                }
                else if(d[u] + G[u][v] == d[v])
                {
                    if (w[v] < w[u] + weight[v]) {
                        w[v] = w[u] + weight[v];
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d", &N, &M, &st, &ed);
    for (int i=0; i<N; i++) {
        scanf("%d",&weight[i]);
    }
    int a,b,l;
    fill(G[0], G[0]+MAXN*MAXN, INF);
    for (int i=0; i<M; i++) {
        scanf("%d%d%d",&a,&b,&l);
        G[a][b] = G[b][a] = l;
    }
    Djikstra(st);
    printf("%d %d",num[ed], w[ed]);
}