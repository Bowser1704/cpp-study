#include<iostream>
#include<string>
using namespace std;

template <class T>
T ArraySum(T* start, T* end) {
    // cout << "length" << end - start << endl;
    int length = end - start;
    T sum{}; // must initialize, important sum is also a object
    for (int i = 0; i < length; i++)
    {
        // cout << *(start + i) << endl;
        sum += *(start + i);
    }
    return sum;
}

int main() {
    string array[4] = {"Tomy", "Jacy", "Mary", "john"};
    cout << ArraySum(array, array + 4) << endl;
    int a[4] = {1, 2, 3, 4};
    cout << ArraySum(a, a + 4) << endl;
    return 0;
}