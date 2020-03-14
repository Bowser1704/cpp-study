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
    if (hi <= lo + 1) return;
    int pos = partition(lo, hi, arr);
    sort(lo, pos, arr);
    sort(pos + 1, hi, arr);
}

double Sort::quickSort() {
    auto start = chrono::steady_clock::now();
    sort(0, len, arr);
    auto end = chrono::steady_clock::now();
    // cout << "quickSort: " << end - start << " milliseconds" << endl;
    return std::chrono::duration<double>(end - start).count();
}