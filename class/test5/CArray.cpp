#include "CArray.hpp"
#include <iostream>
CArray::CArray()
{
    array = nullptr;
    len = 0;
    capacity = 0;
}

CArray::CArray(const CArray &temp)
{
    array = temp.array;
    len = temp.len;
    capacity = temp.capacity;
}

CArray::~CArray()
{
    // you can't use array != nullptr, it will... , I'm confused about that.
    if (!array)
    {
        delete[] array;
        array = nullptr;
        // std::cout << "free array" << std::endl;
    }
}

int CArray::length() { return len; }

CArray CArray::operator=(const CArray &temp)
{
    array = temp.array;
    len = temp.len;
}

int &CArray::operator[](int index)
{
    return array[index];
}

void CArray::resetCapacity(int tempCapacity)
{
    int *tempArr = new int[tempCapacity];
    for (int i = 0; i < this->len; i++)
    {
        tempArr[i] = this->array[i];
    }
    delete[] array;
    array = tempArr;
}

void CArray::push_back(int value)
{
    if (capacity == 0)
    {
        capacity = 2;
        array = new int[2];
    }
    if (len == capacity)
    {
        capacity *= 2;
        resetCapacity(capacity);
    }
    array[len++] = value;
}