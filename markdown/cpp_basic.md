### opp

#### 	Declarations vs Definitions

- Only declaration are allowed to be in .h  , No definition

  - extern  variables
  - function prototypes
  - class/struct declaration

 #### constructor

the name of the constructor is same as the name of class.	

类似于`py`的`__init__`  

#### destructor

#### inline 

优化函数产生的消耗,overhead,但是必须要把body放在headfile.

#### const

const在`*`前面对象是const,在`*`后面指针是const

```c++
class A {
    private:
    	int i;
    public:
    	A() : i(10) {};
    	void f() {}
    	void f() const {}
}
//两个f()也构成overload,因为实际上的参数分别是
//void f(A* this)
//void f(const A* this)
```



  

### 引用

引用是一个别名，它可以说完全是原变量，地址啊，值啊，都是，改变引用也会改变原来的值。

- 引用与指针的区别(实际上reference就是一种pointer)

  1. 不存在空引用。引用必须连接到一块合法的内存。
  2. 一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象。**即引用是不可以修改的**
  3. 引用必须声明时初始化,指针和普通变量一样.

  ```c++
  const int& x = z;	//不能通过x修改z, 即x是不能修改的.
  int i;				//变量
  int & a = i; 	//引用
  
  int & a;		//错误
  
  int* p;			//指针
  p = &a; 		
  
  int main(){
      int i = 1;
      int& a = i;
      int *p = &a;
      std::cout << i << '\n' << a << '\n' << p << '\n' << &i;
      return 0;
  }
  /*
  1
  1
  0x7ffc28b18a24
  0x7ffc28b18a24	地址是一样的
  */
  ```

- 引用可以作为返回值, 这样函数可以放在等号左边,被赋值.

  函数返回引用的时候,事实上返回了一个指向返回值的隐式指针, 但其实又可以说是引用

  ```c++
  #include <iostream>
   
  using namespace std;
   
  double vals[] = {10.1, 12.6, 33.1, 24.1, 50.0};
   
  double& setValues( int i )
  {
    return vals[i];   // 返回第 i 个元素的引用
  }
   
  // 要调用上面定义函数的主函数
  int main ()
  {
   
     cout << "改变前的值" << endl;
     for ( int i = 0; i < 5; i++ )
     {
         cout << "vals[" << i << "] = ";
         cout << vals[i] << endl;
     }
  ```

  返回引用时,要注意一点**作用域**,引用的对象不能超出作用域,所以局部对象是不能直接引用的,但是可以声明静态,返回静态变量.

  ```C++
  int& func() {
     int q;
     //! return q; // 在编译时发生错误
     static int x;
     return x;     // 安全，x 在函数作用域外依然是有效的
  }
  ```

### 容器vector

vector 是一个c++标准库,容器或者说广义数组,区别于一般的数组,可以储存本身,不用实现定义数组大小,redis内的string