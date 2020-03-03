#include "sort.h"
using namespace std;

// [lo, hi)
// arr[lo] as the pivot
int partition(int lo, int hi, int *arr) {
    int pivot = arr[lo];
    while (lo < hi) {
        while (lo < hi && arr[--hi] >= pivot)
            ;
        arr[lo] = arr[hi];
        while (lo < hi && arr[++lo] <= pivot)
            ;
        arr[hi] = arr[lo];
    }
    arr[lo] = pivot;
    return lo;
}

void sort(int lo, int hi, int *arr) {
    if (hi <= lo+1) return;
    int pos = partition(lo, hi, arr);
    sort(lo, pos, arr);
    sort(pos + 1, hi, arr);
}

void Sort::quickSort() {
    clock_t start = clock();
    sort(0, len, arr);
    clock_t end = clock();
    cout << "quickSort: " << end - start << " milliseconds" << endl;
}