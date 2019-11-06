#include <iostream>
#include <math.h>
#include <map>
const double PI  =3.141592653589793238463;
using namespace std;

// using interface, but shape doesn't have member variables'
// polymorphism
class Shape {
    public:
        virtual double getArea() {}
        virtual string getName() {return "Shape";}
};

class Triangle : public Shape {
    private:
        int x, y, z;
    public:
        Triangle(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
        int getCircumference() {return x+y+z;}
        virtual double getArea() {
            int p = getCircumference();
            return sqrt(p*(p-x)*(p-y)*(p-z));
        }
        virtual string getName() {return "Triangle";}
};

class Circle : public Shape {
    private:
        int r;
    public:
        Circle (int _r): r(_r) {}
        virtual double getArea() {
            return PI*r* r;
        }
        virtual string getName() {return "Circle";}
};

class Rectangle : public Shape {
    private:
        int x, y;
    public:
        Rectangle(int _x, int _y) : x(_x), y(_y) {}
        virtual double getArea() {
            return x*y;
        }
        virtual string getName() {return "Rectangle";}
};


int main() {
    map<string, double> shapes;
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n;i++) {
        char ch;
        scanf("%c", &ch);
        switch (ch) {
            case 'R':{
                int x,y;
                scanf("%d%d", &x,&y);
                Rectangle rectangle(x,y);
                shapes[rectangle.getName()] = rectangle.getArea();
            }
            case 'T':{
                int x,y,z;
                scanf("%d%d%d",&x,&y,&z);
                Triangle triangle(x,y,z);
                shapes[triangle.getName()] = triangle.getArea();
            }
            case 'C':{
                int r;
                scanf("%d",&r);
                Circle circle(r);
                shapes[circle.getName()] = circle.getArea();
            }
        }
    }
    cout << "\noutput:" << endl;
    for (auto shape=shapes.begin(); shape != shapes.end(); ++shape) {
        cout << shape->first << ":" << shape->second << endl;
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