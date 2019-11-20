#include <iostream>
#include <cstring>
class MyString {
    private:
        int capacity;
        int len;
        char* str;
    public:
        MyString();
        MyString(const char *cString);
        ~MyString();
        char at(int index) const;
        int length() const;
        void clear();
        bool empty() const;
        int compare(const MyString &s) const; 
        int compare(int index, int n, const MyString s) const;
        void copy(char s[], int index, int n);
        char* data() const;
        int find(char ch) const;
        int find(char ch, int index) const;
};