#include <functional>
#include "sort.h"

void printTime(double sum, int len) {
    std::cout << "N: " << len << " ";
    std::cout << std::fixed << "sum: " << sum << "  average: " << sum / 1000 << " seconds" << std::endl;
    // std::cout << "average: " << sum / 1000 << " milliseconds" << std::endl;
}

int main(int argc, char *argv[]) {
    // int length = 100;
    // if (argc == 2) {
    //     length = atoi(argv[1]);
    // }
    // 用了成员函数,不好封装成函数,只能这么写了...
    int k = 1000;

    int lens[] = {100, 200, 500, 1000, 2000, 3000};
    std::cout << "BubbleSort" << std::endl;
    for (int j = 0; j < 6; j++) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            Sort sort(lens[j]);
            sum += sort.bubbleSort();
        }
        printTime(sum, lens[j]);
    }

    std::cout << "InsertionSort" << std::endl;
    for (int j = 0; j < 6; j++) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            Sort sort(lens[j]);
            sum += sort.insertionSort();
        }
        printTime(sum, lens[j]);
    }

    std::cout << "QucikSort" << std::endl;
    for (int j = 0; j < 6; j++) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            Sort sort(lens[j]);
            sum += sort.quickSort();
        }
        printTime(sum, lens[j]);
    }

    std::cout << "MergeSort" << std::endl;
    for (int j = 0; j < 6; j++) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            Sort sort(lens[j]);
            sum += sort.mergeSort();
        }
        printTime(sum, lens[j]);
    }

    std::cout << "HeapSort" << std::endl;
    for (int j = 0; j < 6; j++) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            Sort sort(lens[j]);
            sum += sort.heapSort();
        }
        printTime(sum, lens[j]);
    }

    std::cout << "ShellSort" << std::endl;
    for (int j = 0; j < 6; j++) {
        double sum = 0;
        for (int i = 0; i < k; i++) {
            Sort sort(lens[j]);
            sum += sort.shellSort();
        }
        printTime(sum, lens[j]);
    }

    return 0;
}