#include "sort.h"
#include <iostream>
#include <time.h>
using namespace std;

void Sort::insertionSort() {
    clock_t start = clock();
    for(int i = 1; i < len; i++) {
        for(int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
            exch(j, j-1);
        }
    }
    clock_t end = clock();
    cout << "insertionSort:" << end - start << " milliseconds" << endl;
}