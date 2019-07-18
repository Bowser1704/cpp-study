#include <stdio.h>
#include <malloc.h>

typedef struct linkList
{
    /* data */
    int data;
    struct linkList* next;
}linkList, *plinkList;

plinkList createList(void);
void traverseList(plinkList pHead);
void inEmpty(plinkList pHead);
int lengthList(plinkList);

int main() {
    plinkList pHead = createList();
    traverseList(pHead);
    return 0;
}

plinkList createList(void){
    int len;
    scanf("%d",&len);
    plinkList pHead = (plinkList)malloc(sizeof(linkList));
    plinkList pTail = (plinkList)malloc(sizeof(linkList));
    pTail = pHead;
    pTail->next = NULL;

    for (int i=0; i < len; i++){
        int val;
        scanf("%d",&val);
        plinkList pNew = (plinkList)malloc(sizeof(linkList));
        pNew->data = val;
        pTail->next = pNew;
        pNew->next = NULL;
        pTail = pNew;
    }
    return pHead;
}

void traverseList(plinkList pHead){
    plinkList p = pHead->next;
    if (p == NULL){
        printf("list is empty");
    }
    while (p != NULL){
        printf("%d->",p->data);
        p = p->next;
    }
    return;
}

void isEmpty(plinkList pHead){
    return (pHead->next == NULL);
}

int lengthList(plinkList pHead){
    plinkList p = pHead->next;
    int len;
    while (p != NULL)
    {
        len++;
        p = p->next;
    }
    return len;
}