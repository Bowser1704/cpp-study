#ifndef SORT_H_
#define SORT_H_ 

class Sort{
    private:
        int *arr;
        int len;
        bool is_less(int a, int b);
        void exch(int a, int b);
    public:
        Sort(int length);
        ~Sort();
        void insertionSort();
        void shellSort();
        void mergeSort();
        void printSortArr();
};

#endif