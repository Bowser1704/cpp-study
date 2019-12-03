#include <iostream>
#include <string>
using namespace std;

string commonChars(const string &s1, const string &s2)
{
    int len1 = s1.length(), len2 = s2.length();
    string result;
    if (len1 <= len2)
    {
        for (int i = 0; i < len1; i++)
        {
            if (s2.find(s1[i])>=0)
            {
                result += s1[i];
            }
        }
    }
    else
    {
        result = commonChars(s2, s1);
    }
    return result;
}
int main()
{
    string s1, s2;
    cout << "enter a string s1: ";
    cin >> s1;
    cout << "enter a string s2: ";
    cin >> s2;
    cout << "the common characters are " << commonChars(s1, s2) << endl;
    return 0;
}
