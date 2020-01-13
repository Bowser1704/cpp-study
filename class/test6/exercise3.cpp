#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
const double PI = 3.141592653589793238463;
using namespace std;

// using interface
// polymorphism
class Shape {
   protected:
    string name;
    double area;

   public:
    virtual void setArea() { area = 0; };
    virtual void setName() { name = "Shape"; }
    void PrintArea() {
        std::cout << name << ": " << area << endl;
    }
    static bool comp(const Shape &a, const Shape &b) {
        return a.area < b.area;
    }
};

class Triangle : public Shape {
   private:
    int x, y, z;

   public:
    Triangle(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
    virtual void setArea() {
        int p = (x + y + z) / 2;
        area = sqrt(p * (p - x) * (p - y) * (p - z));
    }
    virtual void setName() {
        name = "Triangle";
    }
};

class Circle : public Shape {
   private:
    int r;

   public:
    Circle(int _r) : r(_r) {}
    virtual void setArea() {
        area = PI * r * r;
    }
    virtual void setName() {
        name = "Circle";
    }
};

class Rectangle : public Shape {
   private:
    int x, y;

   public:
    Rectangle(int _x, int _y) : x(_x), y(_y) {}
    virtual void setArea() {
        area = x * y;
    }
    virtual void setName() {
        name = "Rectangle";
    }
};

int main() {
    vector<Shape> shapes;
    int n;
    char ch;
    cin >> n;
    Shape shape;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &ch);
        switch (ch) {
            case 'R': {
                int x, y;
                cin >> x >> y;
                Rectangle rectangle(x, y);
                shape = rectangle;
                break;
            }
            case 'T': {
                int x, y, z;
                cin >> x >> y >> z;
                Triangle triangle(x, y, z);
                shape = triangle;
                break;
            }
            case 'C': {
                int r;
                cin >> r;
                Circle circle(r);
                shape = circle;
                break;
            }
            default: {
                break;
            }
                shape.setArea();
                shape.setName();
                shapes.push_back(shape);
        }
    }
    std::cout << "\noutput:" << endl;
    std::sort(shapes.begin(), shapes.end(), Shape::comp);
    for (auto shape : shapes) {
        shape.PrintArea();
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