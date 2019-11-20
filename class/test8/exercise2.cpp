#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string &s);

int main()
{
    cout << isPalindrome("HelloolleH");
}

bool isPalindrome(const string &s)
{
    int len = s.length();
    if (len == 0)
        return false;
    if (len == 1)
        return true;
    for (int i = 0; i < len; i++)
    {
        if (s[i] != s[len - i - 1])
        {
            return false;
        }
    }
    return true;
}