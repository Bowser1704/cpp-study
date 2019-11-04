多态的目的：封装可以使得代码模块化，继承可以扩展已存在的代码，他们的目的都是为了代码重用。而多态的目的则是为了“接口重用”。也即，不论传递过来的究竟是类的哪个对象，函数都能够通过同一个接口调用到适应各自对象的实现方法。==也就是父类可以调用子类的函数，并且子类可以有多个，就可以调用多个函数了==

内联函数inline：引入内联函数的目的是为了解决程序中函数调用的效率问题，是将函数直接放到调用的地方去，但是多态是运行时调用函数的，这样就阻止多态了，所以是冲突的。多态调用函数是动态的，也就是运行时候才会被注入。

p.s：即使声明为inline也不一定是内联函数，这是由编译器决定的。要看汇编代码、

override可以有两种，override成员函数，override虚函数，只有override了虚函数的才能算作是体现了C++多态性。而overload则是允许有多个同名的函数，而这些函数的参数列表不同，允许参数个数不同，参数类型不同，或者两者都不同。编译器会根据这些函数的不同列表，==将同名的函数的名称做修饰，从而生成一些不同名称的预处理函数，来实现同名函数调用时的重载问题。==，就是换一个很长的能去区分的函数的名字，但这并没有体现多态性。

==隐藏函数==

1. 如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual 关键字，基类的函数将被隐藏（注意别与重载混淆，重载是在同一个类中发生）。

2. 如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual 关键字。此时，基类的函数被隐藏（注意别与覆盖混淆，覆盖有virtual关键字）。一定需要virtual吗？？？

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    //有virtual关键字,运行时多态
    virtual void f(float x) {
        cout << "Base::f(float)" << x << endl;
    }
    //无virtual关键字,不会运行时多态
    void g(float x) {
        cout << "Base::g(float)" << x << endl;
    }
};

class Derived : public Base {
public:
    virtual void f(float x) {
        cout << "Derived::f(float)" << x << endl;
    }
    //子类与父类函数同名,但是父类没有virtual,或者有,但是参数不同都是隐藏
    void g(int x) {
        cout << "Derived::g(int)" << x << endl;
    }
};

int main(){
    Derived d;
    Base* pb = &d;
    Derived* pd = &d;
    //一般多态都是这样使用，父类的指针指向子类，如果是vitrual那么就会覆盖了
    pb->f(3.14f);
    pd->f(3.14f);    //两个调用的都是子类的函数，也就是override之后的

    pb->g(3.14f);
    pd->g(3.14f);   //前者调用base的g()，后者调用的还是自己的g().
    return 0;
}%  
```

