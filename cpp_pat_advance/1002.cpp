//错误    问题在于浮点数的不确定,如何判断浮点数等于0很重要
#include <iostream>
using namespace std;

int main(){
    float array[1001] = {0};
    int m, n;
    cin >> m;
    // for (int i=0; i<1001; i++){
    //     cout << array[i] << endl;
    // }
    for (int i=0; i<m; i++){
        int k = 0;
        float in = 0.0;
        cin >> k >> in;
        array[k] += in;
    }
    cin >> n;
    for (int i=0; i<n; i++){
        int k = 0;
        float in = 0.0;
        cin >> k >> in;
        array[k] += in;
    }
    int sum=0;
    for (int i=0; i <= 1000; i++){
        if (array[i] != 0) sum++;
    }
    cout << sum << ' ';
    for (int i=1000; i>=0; i--){
        if (array[i] != 0) {
            printf("%d %.1f%c",i, array[i], sum==1?'\0':' ');
            sum -- ;
        }
    }
    return 0;
}