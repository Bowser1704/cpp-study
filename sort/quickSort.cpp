#include "sort.h"
using namespace std;

void exch(int a, int b, int *arr){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int lo, int hi, int *arr) {
    int i=lo, j=hi+1;
    int v = arr[lo];
    while(true) {
        while(arr[++i] < v) if(i==hi) break;
        while(arr[--j] > v) if(j==lo) break;
        if(i>=j) break;
        exch(i, j, arr);
        //notice j is lower than i, so exch(lo, j, arr)
    }
    exch(lo, j, arr);
    return j;
}

void sort(int lo, int hi, int *arr) {
    if (hi <= lo) return;
    int j = partition(lo, hi, arr);
    sort(lo, j-1, arr);
    sort(j+1, hi, arr);
}

void Sort::quickSort() {
    clock_t start = clock();
    sort(0, len-1, arr);
    clock_t end = clock();
    cout << "quickSort: " << end - start << " milliseconds" << endl;
}