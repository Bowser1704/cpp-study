#include <iostream>
#include <math.h>
using namespace std;

class Circle{
    private:
        float r;
    public:
        Circle(float _r):r(_r){}
        ~Circle(){}
        float area() { return M_PI*r*r; }
};

double circle(Circle *circleArray[], int size) {
    double res=0; 
    for(int i=0; i<size;i++) {
        res+=circleArray[i]->area();
    }
}

int main() {
    //just for test
    Circle *array[3];
    for(int i=0;i<3;i++) {
        array[i] = new Circle(i);
    }
    cout << circle(array, 3);
    return 0;    
}