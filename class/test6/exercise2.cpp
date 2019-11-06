#include <iostream>
#include <math.h>
using namespace std;

class Mypoint {
    protected:
        double x, y;
    public:
        Mypoint(): x(0), y(0) {}
        Mypoint(double x, double y) : x(x), y(y) {}
        double getX() const { return x;}
        double getY() const { return y;}
        double distance(const Mypoint& other) const {
            return sqrt( (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) );
        }
};

class ThreePoint : public Mypoint {
    protected:
        double z;
    public:
        ThreePoint(){ x = 0; y = 0; z = 0; }
        ThreePoint(double _x, double _y, double _z){ x = _x; y = _y; z = _z; }
        double getZ() const { return z; }
        double distance(const ThreePoint &other) const {
            return sqrt( (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z) );
        }
};

int main() {
    ThreePoint tpoint;
    ThreePoint tpoint1(10,30,22.5);
    cout << "distance  " << tpoint.distance(tpoint1) << endl;
    return 0;
}