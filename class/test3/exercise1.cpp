#include <iostream>
using namespace std;

class MyInteger {
    private:
        int value;
    public:
        MyInteger(int value) : value(value) {}
        int getValue() {return value;}
        bool equals(MyInteger& other)   {return value == other.getValue(); }
        bool equals(int other) {return value == other;}
};

bool isEven(int value) {
    return value % 2 == 0;
}

bool isPrime(int value) {
    for(int i=2; i*i <= value; i++){
        if(value % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    MyInteger test = 33;
    MyInteger test2 = 44;
    cout << test.getValue() << endl;
    cout << test.equals(test2) << endl;
    cout << test.equals(20) << endl;
    cout << isEven(test2.getValue()) << endl;
    cout << isPrime(test.getValue()) << endl;
}