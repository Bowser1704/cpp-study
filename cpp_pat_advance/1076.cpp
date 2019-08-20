#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 1001;
struct Node
{
    int id;
    int depth;
};
vector<Node> adj[MAXN];     //vector存的是Followers
// int inq[MAXN] = {0};

int BFS(int s, int l) {
    int inq[MAXN] = {0};    //必须要在里面初始化!!!
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.depth = 0;        //初始化一下，有多个start
    q.push(start);
    inq[start.id] = 1;
    while (!q.empty()) {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for (int i=0; i<adj[u].size(); i++) {
            Node next = adj[u][i];
            next.depth = topNode.depth + 1; //到达后深度就变了
            if (inq[next.id]==0 && next.depth <= l) {
                q.push(next);
                inq[next.id] = 1;
                numForward ++;
            }
        }
    }
    return numForward;
}

int main() {
    Node user;
    int N, L, num, id;
    scanf("%d%d", &N, &L);
    for (int i=1; i<=N; i++) {   //i从1开始
        user.id = i;
        scanf("%d", &num);
        for (int j=0; j<num; j++){
            scanf("%d", &id);
            adj[id].push_back(user);
        }
    }

    int k,x;
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d",&x);
        printf("%d\n",BFS(x,L));
    }
}