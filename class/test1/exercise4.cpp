#include <iostream>
#include <math.h>
using namespace std;

class Point {
	private:
		int x, y;
	public:
		//not const& Point
		double mydistance (const Point& p);
	Point(int _x, int _y) {
		this->x = _x;
		this->y = _y;
	}
	~Point() {
	}
};
double Point::mydistance(const Point& p) {
	return sqrt((p.x - this->x)*(p.x - this->x) + (p.y - this->y)*(p.y - this->y));
}
int main() {
	Point p1(1,2), p2(2,3);
	cout << p1.mydistance(p2) << endl;
}
