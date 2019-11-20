#include "MyString.hpp"
using namespace std;

int main() {
    MyString s;
    MyString s1("hello");
    char ss[] = "world";
    s.copy(ss, 0, 5);
    cout << s.compare(s1) << endl;
    cout << "s[0] = " << s.at(0) << endl;
    char *sss = s.data();
    cout << sss << endl;
    cout << "s1[1] = " << s1.at(1) << endl;
    cout << s.find('d') << endl;
    // cout << s1.find('o') << endl;
}