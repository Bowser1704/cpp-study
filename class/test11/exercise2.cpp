#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

struct Rule1 {
    bool operator()(int a, int b) const {
        int x = a % 10, y = b % 10;
        if (x == y) return a > b;
        return x < y;
    }
};

struct Rule2 {
    bool operator()(Point& a, Point& b) const {
        int distanceA = sqrt(a.x * a.x + a.y * a.y), distanceB = sqrt(b.x * b.x + b.y * b.y);
        if (distanceA == distanceB) {
            if (a.x == b.x) return a.y < b.y;
            return a.x < b.x;
        }
        return distanceA < distanceB;
    }
};

int main() {
    int a[8] = {6, 5, 55, 23, 3, 9, 87, 10};
    sort(a, a + 8, Rule1());
    for (int i = 0; i < 8; i++)
        cout << a[i] << ",";
    cout << endl;
    Point ps[8] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, -1}, {1, 1}, {2, 0}, {-2, 0}};
    sort(ps, ps + 8, Rule2());
    for (int i = 0; i < 8; i++) {
        cout << "(" << ps[i].x << "," << ps[i].y << ")";
    }
    return 0;
}