#include "sort.h"

using namespace std;

void Sort::bubbleSort() {
    clock_t start = clock();
    for(int i = 0; i < len; i++) {
        bool isSorted = true;
        for (int j = 0; j < len-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSorted = false;
            }
        }
        if (isSorted) {
            break;
        }
    }
    clock_t end = clock();
    cout << "bubbleSort: " << end - start << " milliseconds" << endl;
}