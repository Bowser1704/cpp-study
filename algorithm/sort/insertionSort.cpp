#include "sort.h"

using namespace std;

void Sort::insertionSort() {
    clock_t start = clock();
    for (int i = 1; i < len; i++) {
        int value = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
    clock_t end = clock();
    cout << "insertionSort: " << end - start << " milliseconds" << endl;
}