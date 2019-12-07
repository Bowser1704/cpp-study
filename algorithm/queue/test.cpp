#include <iostream>
#include "./circular_queue.hpp"
using namespace std;

int main() {
    CircularQueue<int> Myqueue(5);
    for (int i=0; i<5; i++) {
        Myqueue.enqueue(i);
    }
    for (int i=0; i<5; i++) {
        cout << Myqueue.dehead() << endl;
        Myqueue.dequeue();
    }
}