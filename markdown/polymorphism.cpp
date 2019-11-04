#include <iostream>
using namespace std;

class Base {
public:
    //有virtual关键字,运行时多态
    virtual void f(float x) {
        cout << "Base::f(float)" << x << endl;
    }
    //无virtual关键字,不会运行时多态
    virtual void g(float x) {
        cout << "Base::g(float)" << x << endl;
    }
};

class Derived : public Base {
public:
    virtual void f(float x) {
        cout << "Derived::f(float)" << x << endl;
    }
    //子类与父类函数同名,但是父类没有virtual,或者有,但是参数不同都是隐藏
    virtual void g(int x) {
        cout << "Derived::g(int)" << x << endl;
    }
};

int main(){
    Derived d;
    Base* pb = &d;
    Derived* pd = &d;
    //一般多态都是这样使用，父类的指针指向子类，如果是vitrual那么就会覆盖了
    pb->f(3.14f);
    pd->f(3.14f);    //两个调用的都是子类的函数

    pb->g(3.14f);
    pd->g(3.14f);   //前者调用base的g()，后者调用的还是自己的g().
    return 0;
}
