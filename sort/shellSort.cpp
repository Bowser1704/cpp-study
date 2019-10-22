#include "sort.h"

using namespace std;

void Sort::shellSort() {
    clock_t start = clock();
    int h = 1; 
    while(h < len / 3) {h = 3*h + 1;}
    while(h >= 1) {
        for(int i = h; i < len; i++){
            for(int j = i; j < len && arr[j] < arr[j-h]; j-=h){
                exch(j, j-h);
            }
        }
        h /= 3;
    }
    clock_t end = clock();
    cout << "shellSort: " << end - start << " milliseconds" << endl;
}