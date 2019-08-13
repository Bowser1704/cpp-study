//必须要中序，和先，后，层其中一个搭配才可以求得出来tree
#include <iostream>
#include <queue>
using namespace std;
const int maxn=50;

struct node{
    int data;
    node* lChild;
    node* rChild;
};
int in[maxn], post[maxn];
int n;

node* create(int postL, int postR, int inL, int inR){
    //后序
    if(postL > postR){
        return NULL;
    }
    node* root = new node;
    root->data = post[postR];   //后序的最后一个是根节点数据
    int k;
    for(k=0; k<=inR; k++){
        if(in[k]==root->data){
            break;
        }
    }
    int numLeft = k - inL;  //左子树的节点个数
    
    //左子树的后序空间[postL, postL+numLeft-1], 中序空间[inL, k-1]
    root->lChild = create(postL, postL+numLeft-1, inL, k-1);

    //右子树的后序空间[postL+numLeft, postR-1], 中序空间[k, inR]
    root->rChild = create(postL+numLeft, postR-1, k+1, inR);
    
    return root;
}

int num = 0;
void BFS(node* root){
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node* now = q.front();
        q.pop();
        printf("%d",now->data);
        num++;
        if (num<n) putchar(' ');
        if (now->lChild != NULL) q.push(now->lChild);
        if (now->rChild != NULL) q.push(now->rChild);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d", &post[i]);
    }
    for (int i=0; i<n; i++){
        scanf("%d", &in[i]);
    }
    BFS(create(0, n-1, 0, n-1));
    return 0;
}