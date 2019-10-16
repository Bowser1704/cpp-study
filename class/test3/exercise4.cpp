#include <iostream>
using namespace std;
const float eps = 1e-7;

class Rectangle {
    private:
        float length, width;
    public:
        Rectangle(float length, float width):length(length),width(width) {}
        Rectangle() {length=0.0; width=0.0; }
        float getArea() {return length*width;}
};

class RectangleSet {
    private:
        Rectangle* set[100];
        int count;
    public:
        RectangleSet(int count):count(count) {}
        RectangleSet() {count=0;}
        ~RectangleSet() {delete[] *set;}
        void addRectangle(float x, float y) {
            set[count++] = new Rectangle(x,y);
        }
        int getCount() {return count;}
        float getAllArea() {
            float res;
            for(int i = 0; i<count; i++) {
                res += set[i]->getArea();
            }
            return res;
        }
};

int main() {
    RectangleSet set;
    for(int i = 0; i<10; i++) {
        set.addRectangle(i+1,i+1);
    }
    cout << set.getCount() << endl;
    cout << set.getAllArea() << endl;
}