#include "sort.h"

class Merge {
   private:
    int *aux;

    // merge [lo, mid] and [mid+1, hi]
    void merge(int *arr, int lo, int mid, int hi) {
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            aux[k] = arr[k];
        }
        // [i, mid] [j, hi]
        for (int k = lo; k <= hi; k++) {
            if (i > mid)
                arr[k] = aux[j++];
            else if (j > hi)
                arr[k] = aux[i++];
            else if (aux[i] < aux[j])
                arr[k] = aux[i++];
            else
                arr[k] = aux[j++];
        }
    }

    int min(int a, int b) {
        if (a < b) return a;
        return b;
    }

   public:
    Merge(int len) {
        aux = new int[len];
    }
    ~Merge() {
        delete[] aux;
    }
    // 自顶向下归并排序， 递归
    void sort(int *arr, int lo, int hi) {
        if (lo >= hi) return;
        int mid = lo + (hi - lo) / 2;
        sort(arr, lo, mid);
        sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }

    // 自底向上归并排序，多次遍历数组，每次归并很多个小数组。
    void sort(int *arr, int len) {
        // sz为子数组的大小，初始为1，每次加倍， 最后一个数组只有数组大小为sz的偶数倍才会为sz，否则比sz小。
        for (int sz = 1; sz < len; sz += sz) {
            for (int lo = 0; lo < len - sz; lo += sz + sz) {
                merge(arr, lo, lo + sz - 1, min(lo + sz + sz - 1, len - 1));
            }
        }
    }
};

void Sort::mergeSort() {
    clock_t start = clock();
    Merge merge = Merge(len);
    merge.sort(arr, len);
    clock_t end = clock();
    std::cout << "mergeSort: " << end - start << " milliseconds" << std::endl;
}

// int main() {
//     Merge merge = Merge(10);
//     int arr[] = {1, 2, 4, 3, 5, 6, 7, 8, 9, 10};
//     merge.sort(arr, 0, 9);
//     for (int i = 0; i < 9; ++i) {
//         printf("%d ", arr[i]);
//     }
// }