#include "StackOfIntegers.h"
#include "StackOfIntegers.cpp"
#include <iostream>
using namespace std;

int main(){
    StackOfIntegers stack ;
    for(int i=0; i<10; i++){
        stack.push(i+1);
    }
    cout << stack.getSize() << endl;
    cout << stack.empty() << endl;
    cout << stack.pop() << endl;  
    cout << stack.peek() << endl;
    for(int i=0; i<9; i++){
        stack.pop();
    }
    cout << stack.getSize() << endl; 
    cout << stack.empty() << endl;
}