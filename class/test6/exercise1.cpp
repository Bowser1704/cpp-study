#include <iostream>
const double PI  =3.141592653589793238463;
using namespace std;

class Shape {
    public:
        virtual double area(){};
};

class Rectangle : public Shape {
    private:
        double x, y;
    public:
        Rectangle(double _x, double _y) : x(_x), y(_y) { }
        virtual double area() const { 
            return x * y;
        }
        bool operator==(const Rectangle &other)   {return x == other.x && y == other.y;}
};

class Circle : public Shape {
    private:
        double r;
    public:
        Circle(double _r): r(_r) {}
        virtual double area() const {
            return PI * r * r;
        }
};

int main() {
    Rectangle rectangle(4,5);
    Circle circle(4);
    // Shape s1 = Circle(8);
    // cout << s1.area() << endl;
    // return 8, polymorphism isn't implemented'
    cout << rectangle.area() << endl;
    cout << circle.area() << endl;
    return 0;
}