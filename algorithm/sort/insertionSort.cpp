#include "sort.h"

using namespace std;
double Sort::insertionSort() {
    auto start = chrono::steady_clock::now();
    for (int i = 1; i < len; i++) {
        //value 是要插入的值， j是已排序序列的末尾。
        int value = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > value) {
            arr[j + 1] = arr[j];
            j--;
        }
        // 找到插入的位置。
        arr[j + 1] = value;
    }
    auto end = chrono::steady_clock::now();
    // cout << "insertionSort: " << end - start << " milliseconds" << endl;
    return std::chrono::duration<double>(end - start).count();
}