#include <iostream>
#include <map>
using namespace std;

map<string, int> strNum;
multimap<int, string, greater<>> numStr;
int main() {
    string str;
    //Crtl + D input EOF or input file
    while (getline(cin, str)) {
        strNum[str]++;
    }
    for (auto it : strNum) {
        numStr.insert(make_pair(it.second, it.first));
    }
    for (auto it : numStr) {
        cout << it.second << ": " << it.first << endl;
    }
}
//   ./exercise < exercise1.txt

/*----------------------------------------------------------------
this
is
ok
this
plus
that
is
plus
plus
*/