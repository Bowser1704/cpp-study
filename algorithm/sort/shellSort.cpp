#include "sort.h"

using namespace std;

double Sort::shellSort() {
    auto start = std::chrono::steady_clock::now();
    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < len; i++) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
                swap(arr[j], arr[j - h]);
            }
        }
        h /= 3;
    }
    auto end = chrono::steady_clock::now();
    // cout << "shellSort: " << end - start << " milliseconds" << endl;
    return chrono::duration<double>(end - start).count();
}