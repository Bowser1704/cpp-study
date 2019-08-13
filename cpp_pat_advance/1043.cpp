#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node* lChild;
    node* rChild;
};

//注意要用引用
void insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->lChild = root->rChild = NULL;
        return;
    }
    if(root->data > data) insert(root->lChild, data);
    else    insert(root->rChild, data);
}

void preOrder(node* root, vector<int>&res){
    if(root == NULL) return;
    res.push_back(root->data);
    preOrder(root->lChild, res);
    preOrder(root->rChild, res);
}

void preOrderMirror(node* root, vector<int>&res){
    if(root == NULL) return;
    res.push_back(root->data);
    preOrderMirror(root->rChild, res);
    preOrderMirror(root->lChild, res);
}

void postOrder(node* root, vector<int>&res){
    if(root == NULL) return;
    postOrder(root->lChild, res);
    postOrder(root->rChild, res);
    res.push_back(root->data);
}

void postOrderMirror(node* root, vector<int>&res){
    if(root == NULL) return;
    postOrderMirror(root->rChild, res);
    postOrderMirror(root->lChild, res);
    res.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;
int main(){
    int n;
    node* root = NULL;
    scanf("%d", &n);
    int data;
    for(int i=0; i<n; i++){
        scanf("%d",&data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre) {
        printf("YES\n");
        for(int i=0; i<n; i++){
            printf("%d", post[i]);
            if (i < n-1) printf(" ");
        }
    }
    else if (origin == preM) {
        printf("YES\n");
        for(int i=0; i<n; i++){
            printf("%d", postM[i]);
            if (i < n-1) printf(" ");
        }
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}