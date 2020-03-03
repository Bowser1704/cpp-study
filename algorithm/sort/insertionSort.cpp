#include "sort.h"

using namespace std;

void Sort::insertionSort() {
    clock_t start = clock();
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
    clock_t end = clock();
    cout << "insertionSort: " << end - start << " milliseconds" << endl;
}