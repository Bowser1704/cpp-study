Q&A:

1. 什么是多态 polymorphism

   1. 目的是为了接口重用，也就是说，不论传递过来的究竟是那个类的对象，函数都能够通过同一个接口调用到适应各自对象的实现方法。**这里思考一下python的鸭子类型和多态的关系**。

   2. 虚函数

      1. `虚函数`： 就是可以被子类重新definition的函数,但是在父类中其实已经definition过一次了，可以称之为覆盖，注意(必须是有virtual的)，这是就是所谓的动态覆盖(override)

      2. `纯虚函数`：是虚函数，但是在父类中就没有definition，just declaration，方法是

         ```c++
         virtual void funtion()=0
         ```

      3. 抽象类：包含了纯虚函数就是抽象类，不可以直接实例化对象，只能作为父类用。

   3. 两种多态

      - 运行时多态(有virtual)

        也就是说在声明一个类的时候声明

      - 非运行时多态，直接函数重载调用。

   4. 令人迷惑的隐藏规则

      隐藏是子类的函数屏蔽了父类的同名函数，	有如下规则

      - 如果子类的函数和父类的`函数名字相同`，但是`参数不同`，此时，无论是否有`virtual`关键字,父类的函数将会被隐藏，也就是说会被屏蔽(注意，重载是对于一个类来说的，而这里是对于类与类之间继承来说的)
      - 如果子类的函数与父类的`函数名字相同`，并且`参数相同`，但是没有`virtual`关键字，此时父类的函数将被隐藏。(如果有`virtual`关键字,就是覆盖了)

   5. 代码实例

      ```c++
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
          pd->f(3.14f);    //两个调用的都是子类的函数
      
          pb->g(3.14f);
          pd->g(3.14f);   //前者调用base的g()，后者调用的还是自己的g().
          return 0;
      }
      ```

2. 重载机制

   重载声明可以简单理解为你本来有一个函数，但是你可以通过重载，使同一个函数名，通过`参数的不同或者返回值类型不同`其实实现了不同的函数，你就可以通过修改声明时的`参数列表，定义，实现(运算符)`，编译器会根据你的参数自动帮你选择函数类型。

   - 函数重载

     在同一个作用域内，一般是在一个类中，声明多个功能类似的同名函数，但是这些函数必须满足`形式参数（指参数的个数、类型或者顺序）必须不同，不能仅通过返回类型的不同来重载函数。`

     ```c++
     //不难，直接复制了别人的代码
     #include <iostream>
     using namespace std;
      
     class printData 
     {
        public:
           void print(int i) {
             cout << "Printing int: " << i << endl;
           }
     
           void print(double  f) {
             cout << "Printing float: " << f << endl;
           }
     
           void print(char* c) {
             cout << "Printing character: " << c << endl;
           }
     };
     
     int main(void)
     {
        printData pd;
      
        // Call print to print integer
        pd.print(5);
        // Call print to print float
        pd.print(500.263);
        // Call print to print character
        pd.print("Hello C++");
      
        return 0;
     }
     ```

   - 运算符重载

     你可以重定义或者说重载c++中的大部分内置运算符，这样你就可以自定义运算符对于你自己定义的类型，函数名是由关键字 `operator` 和其后要`重载的运算符符号`（如`operator +`）构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表。

     - 可以重载的运算符

       ```c++
       |+| -| * |\/ |% |^|
       |–|–|–|–|–|–|
       |& || |~ |! |, |=|
       |< |>| <=| >=| ++| –|
       |<<| >>| ==| !=| &&| || |
       |+= |-= |/= |%= |^= |&=|
       ||=| *=| <<=| >>=| [] |()|
       |-> |->* |new |new [] |delete |delete []|
       ```

     - 不可以的

       ```c++
       ::
       .*
       .
       ?:```
       ```
       
     - 一元运算符重载
     
       只有一个数，`++`，`--`，`-`，`！`(逻辑非)，有一点要注意(自增与自减，后缀重载有参数int(`i++`)，前缀重载没有参数(`++i`))
     
       ```c++
       #include <iostream>
       using namespace std;
       
       class Time {
           private:
               int hours;
               int minutes;
           public:
               Time(): hours(0), minutes(0) {}
               Time(int h, int m) {
                   hours = h;
                   minutes = m;
               }
               void displayTime() {
                   cout << "Hour:" << hours << "   Minutes:" << minutes << endl;
               }
       
               //重点重载前缀自增运算符 (++i)
               Time operator++ () {
                   ++minutes;
                   if (minutes >= 60) {
                       ++hours;
                       minutes -= 60;
                   }
                   return Time(hours, minutes);
               }
               //重载后缀自增运算符(i++)
               Time operator++ (int) {
                   Time T(hours, minutes);
                   ++minutes;
                    if (minutes >= 60) {
                       ++hours;
                       minutes -= 60;
                   }
                   return T;
               }
       };
       
       int main() {
           Time T1(11, 59), T2(10, 40);
           ++T1;                    // T1 加 1
           T1.displayTime();        // 显示 T1
           ++T1;                    // T1 再加 1
           T1.displayTime();        // 显示 T1
        
           T2++;                    // T2 加 1
           T2.displayTime();        // 显示 T2
           T2++;                    // T2 再加 1
           T2.displayTime();        // 显示 T2
           return 0;
           }
       
       ```
     
       
     

​     

3. declaration&definition initialization&assignment

   在c++中必须要区分的两组词语

   - declaration 声明

     ```c++
     extern int x;
     ```

   - definition 定义

     ```c++
     int x;
     ```

   - initialization 初始化

     ```c++
     int x = 1;
     ```

   - assignment 赋值

     ```c++
     x = 1;
     ```

     

4. 拷贝构造

   1. member 对 member的拷贝,每一个成员的拷贝,如果有指针member,就很重要,拷贝的是一样的.这样的话如果析构,或者说释放内存的时候,是重复释放两次的,会产生malloc错误,所以我们要自定义拷贝构造函数.
   2. 如果拷贝构造的时候,用的是 obj(obj x),这样就是一个死循环,因为进参数的时候就是一次拷贝,这样就一直拷贝但是出不来.正确写法`obj(const obj *x)`

5. const reference      parameter 常常使用的是 const string& str 这是为什么

6. default constructor, virtual  destructor, copy constructor(private)

7. static

   1. 持久存储
   2. 访问受限hidden,同时是全局的

8. inline

9. overloading operators

10. templates

11. streams

12. STL ---> Standrad Template Library

13. there are reasons to believe in a better world.