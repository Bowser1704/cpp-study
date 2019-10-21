#include "sort.h"
# include <stdlib.h>

int main(int argc, char *argv[]) {
    int length = 10;
    if (argc == 2) {
        length = atoi(argv[1]);
    }
    Sort sort1(length), sort2(length), sort3(length);
    sort1.insertionSort();
    sort1.printSortArr();

    sort2.shellSort();
    sort2.printSortArr();

    sort3.mergeSort();
    sort3.printSortArr();
    
    return 0;
}