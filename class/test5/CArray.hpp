#ifndef C_ARRAY
#define C_ARRAY

class CArray {
    private:
        int *array;
        int len;
        int capacity;
    public:
        CArray();
        CArray(const CArray & temp);
        ~CArray();
        int length();
        CArray operator=(const CArray &);
        int& operator[](int index);
        void push_back(int value);
        void resetCapacity(int tempCapacity);
};

#endif