#ifndef STACK_OF_INTEGERS_H
#define STACK_OF_INTEGERS_H

class StackOfIntegers {
    private:
        int size;
        int elements[100];
    public:
        StackOfIntegers(int _size);
        StackOfIntegers();
        bool empty();
        int peek();
        int push(int);
        int pop();
        int getSize();
};

#endif