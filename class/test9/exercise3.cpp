#include <iostream>
using namespace std;

template <class T>
class Stack {
   private:
    T elements[100];
    int size;

   public:
    Stack() {
        size = 0;
        for (int i = 0; i < 100; ++i) {
            elements[i] = T{};
        }
    }
    bool empty() { return size == 0; }
    T peek() { return elements[size - 1]; }
    void push(T value) { elements[size++] = value; }
    T pop() { return elements[--size]; }
    int getSize() { return size; }
};

int main() {
    Stack<int> intStack;
    Stack<double> doubleStack;
    for (int i = 0; i < 100; i++) {
        intStack.push(i);
        doubleStack.push(i);
    }
    cout << "length: " << intStack.getSize() << " " << doubleStack.getSize() << endl;
    cout << "peek " << intStack.peek() << " " << doubleStack.peek() << endl;
    for (int i = 0; i < 100; i++) {
        cout << intStack.pop() << " ";
        cout << doubleStack.pop() << " ";
    }
    return 0;
}