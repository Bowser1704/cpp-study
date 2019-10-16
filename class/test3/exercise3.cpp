#include "exercise2/StackOfIntegers.h"
#include "exercise2/StackOfIntegers.cpp"
#include <iostream>
using namespace std;

StackOfIntegers stack;

int getFactors(int num) {
    while(num != 1) {
        for(int i = 2; i <= num; i++) {
            if(num % i == 0) {
                stack.push(i);
                num /= i;
                break;
            }
        }
    }
}

void printFactors() {
    while (!stack.empty()) {
        cout << stack.pop() << " ";
    }
}

int main() {
    getFactors(120);
    printFactors();
}