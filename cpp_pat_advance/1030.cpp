    #include <iostream>
    #include <algorithm>
    using namespace std;
    const int MAXN = 501;
    const int INF = 0x3fffffff;

    int n, m, st, ed;
    int G[MAXN][MAXN], d[MAXN], cost[MAXN][MAXN], c[MAXN], pre[MAXN];   //此题是规定了只有一条最优路径
    bool vis[MAXN] = {false};

    void djikstra(int s) {
        fill(d, d+MAXN, INF);
        fill(c, c+MAXN, INF);
        d[s] = 0;
        c[s] = 0;
        for (int i=0; i<n; i++) {
            int u=-1, MIN=INF;
            for (int j=0; j<n; j++) {
                if (!vis[j] && d[j] < MIN) {
                    u = j;
                    MIN = d[j];
                }
            }
            if (u==-1) return;
            vis[u] = true;
            for (int j=0; j<n; j++) {
                if (!vis[j] && G[u][j] != INF) {
                    if (d[j] > d[u] + G[u][j]) {
                        d[j] = d[u] + G[u][j];
                        c[j] = c[u] + cost[u][j];
                        pre[j] = u;
                    }else if (d[j] == d[u] + G[u][j]) {
                        if (c[j] > c[u] + cost[u][j]) {
                            c[j] = c[u] + cost[u][j];
                            pre[j] = u;
                        }
                    }
                }
            }
        }
    }

    void DFS(int ed) {
        if (ed == st) {
            printf("%d ", ed);
            return; //重要，否则死循环
        }
        DFS(pre[ed]);
        printf("%d ", ed);
    }

    int main() {
        scanf("%d%d%d%d", &n, &m, &st, &ed);
        fill(G[0], G[0]+MAXN*MAXN, INF);    //初始化图
        int a,b,dis,cos;
        for (int i=0; i<m; i++) {
            scanf("%d%d%d%d", &a, &b, &dis, &cos);
            G[a][b] = G[b][a] = dis;
            cost[a][b] = cost[b][a] = cos;
        }
        djikstra(st);
        DFS(ed);
        printf("%d %d\n", d[ed], c[ed]);
        return 0;
    }