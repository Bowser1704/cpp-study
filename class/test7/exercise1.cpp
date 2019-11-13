#include <iostream>
#include <math.h>
#include <stdlib.h>
const double PI = 3.141592653589793238463;
using namespace std;

class Shape
{
public:
    virtual double getArea(){ return 0;};
    virtual const char * getName() { return "Shape"; }
    virtual void PrintArea()
    {
        std::cout << this->getName() << ": " << this->getArea() << endl;
    }
    //结构体指针数组的排序
    static int comp(const void* a, const void* b) 
    {
        Shape* A = *(Shape**)a, *B = *(Shape**)b;
        if (A->getArea() == B->getArea())  return 0;
        if (A->getArea() < B->getArea()) return -1;
        if (A->getArea() > B->getArea()) return 1;
    }
};

class Triangle : public Shape
{
private:
    int x, y, z;

public:
    Triangle(int _x, int _y, int _z) : x(_x), y(_y), z(_z){}
    virtual double getArea()
    {
        int p = (x + y + z) / 2;
        return sqrt(p * (p - x) * (p - y) * (p - z));
    }
    virtual const char* getName()
    {
        return "Triangle";
    }
};

class Circle : public Shape
{
private:
    int r;

public:
    Circle(int _r) : r(_r){}
    virtual double getArea()
    {
        return PI * r * r;
    }
    virtual const char* getName()
    {
        return "Circle";
    }
};

class Rectangle : public Shape
{
private:
    int x, y;

public:
    Rectangle(int _x, int _y) : x(_x), y(_y){}
    virtual double getArea()
    {
        return x * y;
    }
    virtual const char* getName()
    {
        return "Rectangle";
    }
};

int main()
{
    //后面指针数组会改变/覆盖已经赋值的元素，也就是每一次赋值会赋值给所有的元素。因为说每一个元素指向的都是同一个地址.
    //如果在switch里面 Shape *shape 元素每次指向的都是同一个地址, 同样Rectangle也是一样.
    Shape *shapes[1000];
    int index = 0;
    int n;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &ch);
        switch (ch)
        {
        case 'R':
        {
            int x, y;
            cin >> x >> y;
            Rectangle * rectangle = new Rectangle(x, y);
            shapes[index++] = rectangle;
            break;
        }
        case 'T':
        {
            int x, y, z;
            cin >> x >> y >> z;
            Triangle *triangle =new Triangle(x, y, z);
            shapes[index++] = triangle;
            break;
        }
        case 'C':
        {
            int r;
            cin >> r;
            Circle *circle = new Circle(r);
            shapes[index++] = circle;
            //放进去之前是正常调用的。可以实现多态。
            break;
        }
        default:{
            cout << "ERROR" << endl;
            break;
        }
        }
    }
    std::cout << "\noutput:" << endl;
    qsort(shapes, index, sizeof(Shape), Shape::comp);
    for (int i = 0; i < index;i++) {
        shapes[i]->PrintArea();
    }
    return 0;
}
/*
sample input: 
3
R 3 5
C 9
T 3 4 5
*/