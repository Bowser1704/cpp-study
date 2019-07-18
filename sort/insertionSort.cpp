#include <iostream>

int* insertionSort(int *arr, int len){
    int preIndex, key;
    for(int i=1; i<len; i++){
        preIndex = i-1;
        key = arr[i];
        while(preIndex >= 0 && arr[preIndex] > key){
            arr[preIndex+1] = arr[preIndex];//元素后移
            preIndex--;
        }
        arr[preIndex+1] = key;
    }
    return arr;
}
int main()
{
    int a[] = {3,2,1,21,213,423,556,7,57,34,65,23,77};
    int len = sizeof(a) / sizeof(a[0]);
    int *sortA = insertionSort(a, len);
    for (int i=0; i<len; i++)
        std::cout << sortA[i] << '-' ;
    std::cout << std::endl;
    return 0;
}

