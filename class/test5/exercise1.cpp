#include "CArray.hpp"
#include <iostream>

int main()
{
    CArray a;
    for (int i = 0; i < 5; ++i)
    {
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); i++)
    {
        std::cout << a2[i] << " ";
    }
    a2 = a3;
    for (int i = 0; i < a2.length(); i++)
    {
        std::cout << a2[i] << " ";
    }
    std::cout << std::endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i < a4.length(); i++)
    {
        std::cout << a4[i] << " ";
    }
    std::cout << std::endl;

    // CArray a5;
    // std::cout << a5.length() << std::endl;
    // a5.push_back(1);
    // std::cout << a5.length() << std::endl;
    return 0;
}