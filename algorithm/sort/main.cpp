#include "sort.h"

int main(int argc, char *argv[]) {
    int length = 100;
    if (argc == 2) {
        length = atoi(argv[1]);
    }
    Sort sort1(length), sort2(length), sort3(length), sort4(length);
    // sort1.bubbleSort();
    // sort2.printSortArr();

    sort2.insertionSort();
    sort2.printSortArr();

    // sort3.shellSort();
    // sort2.printSortArr();

    //sort3.mergeSort();
    // sort3.printSortArr();
    
    // sort4.quickSort();
    // sort4.printSortArr();

    // Sort heapSort(length);
    // heapSort.heapSort();
    // heapSort.printSortArr();
    return 0;
}