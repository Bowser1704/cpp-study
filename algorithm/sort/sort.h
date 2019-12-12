#ifndef SORT_H_
#define SORT_H_ 
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <iterator>

class Sort{
    private:
        int *arr;
        int len;
    public:
        Sort(int length);
        ~Sort();
        void insertionSort();
        void shellSort();
        void mergeSort();
        void quickSort();
        void heapSort();
        void bubbleSort();
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