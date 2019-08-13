#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=101;

struct node
{
    int weight;
    vector<int> childs;  //储存的是childs的下标
}NODE[maxn];

bool cmp(int a, int b){
    return NODE[a].weight > NODE[b].weight;     //从大到小排列
}

int n, m, s;
int path[maxn];     //记录path, 节点下标

//index, numNode节点个数， sum权合
void DFS(int index, int numNode, int sum){
    if(sum>s) return;
    if(sum==s){
        if(NODE[index].childs.size()!=0) return;
        for(int i=0; i<numNode; i++){
            printf("%d%c",NODE[path[i]].weight,i==numNode-1?'\n':' ');
        }
        return;
    }
    for (int i=0; i<NODE[index].childs.size(); i++){
        int childNum = NODE[index].childs[i];
        path[numNode] = childNum;   //储存从0->n-1
        DFS(childNum, numNode+1, sum+NODE[childNum].weight);
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &s);
    for(int i=0; i<n; i++){
        scanf("%d", &NODE[i].weight);
    }
    int id, k, child;
    for(int i=0; i<m; i++){
        scanf("%d%d", &id, &k);
        for (int j=0; j<k; j++){
            scanf("%d", &child);
            NODE[id].childs.push_back(child);
        }
        sort(NODE[id].childs.begin(), NODE[id].childs.end(), cmp);       
    }
    path[0]=0;  //第一个节点root
    DFS(0, 1, NODE[0].weight);
    return 0;
}