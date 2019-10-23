#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
Sort::Sort(int length)
{
    len = length;
    arr = new int[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % 10000;
    }
}

Sort::~Sort()
{
    delete[] arr;
    cout << "destructor" << endl;
}

bool Sort::is_less(int a, int b)
{
    return arr[a] < arr[b];
}

void Sort::exch(int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void Sort::printSortArr() {
    for(int i = 0; i < len; i++) {
        printf("%d%c", arr[i],i==len-1?'\n':'-');
    }
}