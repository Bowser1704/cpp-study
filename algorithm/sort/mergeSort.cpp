#include "sort.h"

void merge(int *aux, int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1;
    for (int k = low; k <= high; k++)
    {
        aux[k] = arr[k];
    }
    for (int k = low; k <= high; k++)
    {
        if (i > mid)
            arr[k] = aux[j++];
        else if (j > high)
            arr[k] = aux[i++];
        else if (aux[j] < aux[i])
            arr[k] = aux[j++];
        else if (aux[j] > aux[i])
            arr[k] = aux[i++];
        else
            i++; j++;
    }
}

void sort(int *arr, int low, int high)
{
    int aux[high + 1];
    if (high <= low)
        return;
    int mid = (low + high) / 2;
    sort(arr, low, mid);
    sort(arr, mid + 1, high);
    merge(aux, arr, low, mid, high);
}

void Sort::mergeSort()
{
    clock_t start = clock();
    sort(arr, 0, len-1);
    clock_t end = clock();
    std::cout << "mergeSort: " << end - start << " milliseconds" << std::endl;
}