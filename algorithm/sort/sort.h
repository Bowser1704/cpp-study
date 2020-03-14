#ifndef SORT_H_
#define SORT_H_ 
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iterator>
#include <chrono>
class Sort{
    private:
        int len;
    public:
        int *arr;
        Sort(int length);
        ~Sort();
        double insertionSort();
        double shellSort();
        double mergeSort();
        double quickSort();
        double heapSort();
        double bubbleSort();
        void printSortArr();
        bool isLess(int a, int b);
        void exch(int a, int b);
        static void exch(int a, int b, int *arr);
        // friend int pratition(int lo, int hi);
};

class Heap {
    private:
        int *arr;
        int len;
    public:
        Heap(int size);
        void toHeap(int *tempArr, int len);
        ~Heap();
        int size();
        void swim(int n);
        void sink(int n);
        void insert(int n);
        int popMin();
};

#endif