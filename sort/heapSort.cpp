#include "sort.h"
using namespace std;

Heap::Heap(int size = 0) {
    len = 0;
    arr = new int[size];
}
Heap::~Heap() {
    delete[] arr;
}
int Heap::size() {
    return len;
}
void Heap::swim(int k) {
    int parent = (k-1) / 2;
    while(k>0 && (arr[parent] > arr[k])) {
        Sort::exch(parent, k, arr);
        k = parent;
        parent = (k-1) / 2;
    }
}
void Heap::sink(int k) {
    while(k < (len-1) / 2) {
        int lChild = 2*k + 1;
        if(lChild < len-1 && arr[lChild] > arr[lChild+1]) lChild++;
        if(arr[k] < arr[lChild]) break;
        Sort::exch(lChild, k, arr);
        k = lChild;
    }
}
void Heap::insert(int v) {
    arr[len++] = v;
    swim(len-1);
}
int Heap::popMin() {
    int min = arr[0];
    Sort::exch(0, --len, arr);
    sink(0);
    return min;
}

void Heap::toHeap(int* tempArr, int size){
    for(int i = 0; i < size;i++) {
        this->insert(tempArr[i]);
    }
}

void Sort::heapSort() {
    clock_t start = clock();
    Heap heap(len);
    heap.toHeap(arr, len);
    for(int i = 0; i < len; i++) {
        arr[i] = heap.popMin();
    }
    clock_t end = clock();
    cout << "heapSort: " << end - start << " milliseconds" << endl;
}