#include "sort.h"

using namespace std;

double Sort::bubbleSort() {
    auto start = chrono::steady_clock::now();
    for (int i = 0; i < len; i++) {
        bool isSorted = true;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                isSorted = false;
            }
        }
        if (isSorted) {
            break;
        }
    }
    auto end = chrono::steady_clock::now();
    // cout << "bubbleSort: " << end - start << " milliseconds" << endl;
    return std::chrono::duration<double>(end - start).count();
}