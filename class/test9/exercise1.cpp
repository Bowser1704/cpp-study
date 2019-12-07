#include<iostream>
using namespace std;

template <class T, int arrlen>
bool isSorted(T (&arr)[arrlen]) {
    // how can you get length of array in template.
    // cout << arrlen << endl;
    for (int i=0; i<arrlen-1; i++) {
       if (arr[i] > arr[i+1]) {
           return false;
       }
    }
    return true;
}

int main() {
    int arr[] = {1,2,3,4,5,6};
    double arr2[] = {1,2,8,4,5,6};
    cout << "int" << endl << isSorted(arr) << endl;
    cout << "double" << endl << isSorted(arr2) << endl;
    return 0;
}
