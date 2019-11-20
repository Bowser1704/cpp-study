#include "MyString.hpp"
using namespace std;

MyString::MyString() : capacity(0), len(0)
{
    str = new char[capacity];
}

MyString::MyString(const char *cString)
{
    capacity = len = strlen(cString);
    str = new char[capacity];
    memcpy(str, cString, len);
}

MyString::~MyString()
{
    delete[] str;
}

char MyString::at(int index) const
{
    return str[index];
}

int MyString::length() const { return len; }

void MyString::clear()
{
    len = 0;
}

bool MyString::empty() const { return len == 0; }

int MyString::compare(const MyString &s) const
{
    return strcmp(s.str, this->str);
}

int MyString::compare(int index, int n, MyString s) const
{
    char buf[n];
    for (int i = 0; i < n; i++)
        buf[i] = s.str[index + i];
    return strcmp(buf, this->str);
}

void MyString::copy(char s[], int index, int n)
{
    str = (char *)realloc(str, n * sizeof(char));
    len = n;
    //if capacity > n, don't modify capacity
    if (capacity < n)
    {
        capacity = n;
    }
    for (int i = 0; i < n; i++)
        str[i] = s[index + i];
}

char *MyString::data() const
{
    return this->str;
}
int MyString::find(char ch) const
{
    for (int i = 0; i < len; i++)
    {
        if (*(str + i) == ch)
        {
            return i;
        }
    }
    return -1;
}
int MyString::find(char ch, int index) const
{
    for (int i = index; i < len; i++)
    {
        if (*(str + i) == ch)
        {
            return i;
        }
    }
    return -1;
}