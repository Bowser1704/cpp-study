#include <stdio.h>
#include <stdlib.h>

//maxHeap
void swap(int *x, int *y){
    int* temp = x;
    x = y;
    y = temp;
}

void Adjust(int *a, int parent, int high){
    int left = 2*parent + 1;    //左子节点
    int right = left + 1;
    int flag  = parent;

    if (left <= high && a[left] > a[flag])
        flag = left;
    if (right <= high && a[right] > a[flag])
        flag = right;
    if (flag != parent) {
        swap(a+parent, a+flag);
        Adjust(a, flag, high);
    }
}

void HeapSort(int *a, int n) {
    for (int i=n-1; i>=0; i--){
        Adjust(a, i, n-1);
    }
    for (int i=n-1; i>=0; i--){
        swap(a[0], a[i]);
        Adjust(a, 0, i-1);
    }
}

void Output(int *a, int n)
{
    int i;
    for (i=0; i<n; i++) {
        printf("\t%d", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
    int n = 8;
    Output(a, n);
    HeapSort(a, n);
    Output(a, n);
    return 0;
}


