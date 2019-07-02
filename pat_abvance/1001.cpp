//The sum must be written in the standard format.  eg: -999.999
#include <iostream>
#include <string>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string s = to_string(a+b);
    int len = s.length();
    // cout << len << endl;
    for (int i=0; i<len; i++){
        cout << s[i];
        if (s[i]=='-') continue;
        if ((i+1)%3 == len%3 && i!=len-1) cout << ',';
    }
    cout << endl;
    return 0;
}