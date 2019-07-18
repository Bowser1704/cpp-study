#include <stdio.h>
#include <stdlib.h>

#define SWAP(A, B) {pNode temp = A; A = B; B = temp; }

typedef struct  node{
    int addr;
    int data;
    int next;
}Node, *pNode;

int main() {
    Node list[100000] = {0};
    pNode pList[100000] = {0}, *p;
    int pHead, num, k;
    scanf("%d%d%d",&pHead, &num, &k);
    for (int i=0; i<num; i++){
        pList[i] = list + i;
        scanf ("%d%d%d",&pList[i]->addr, &pList[i]->data, &pList[i]->next);
    }

    //将链表排好序
    for(int i=0; i<num; i++){
        for (int j=i; j<num; j++){
            if(pList[j]->addr == (i ? pList[i-1]->next : pHead)) {
                SWAP(pList[i], pList[j]);
                break;
            }
        }
        if (pList[i]->next == -1) //可能有没用的节点
            num = i+1;
    }

    //反转链表
    //to understand
    for (int i=0; i<num / k; i++){
        p = pList + i*k;
        for (int j=0; j<k/2; j++){
            SWAP(p[j], p[k-j-1]);
        }
    }

    for (int i=0; i<num-1; i++)
        printf("%05d %d %05d\n",pList[i]->addr, pList[i]->data, pList[i]->next);    
    printf("%05d %d -1\n",pList[num-1]->addr, pList[num-1]->data); 

    return 0 ;
}