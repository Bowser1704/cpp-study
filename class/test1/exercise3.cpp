#include <iostream>
#include <math.h>
using namespace std;

class Ctriangle {
	private:
		int edge1, edge2, edge3;
	public:
		int circumference(){
			return edge1+edge2+edge3;
		}
		void area() {
			double p = this->circumference() / 2;
			double x = p*(p-edge1)*(p-edge2)*(p-edge3);
			cout << "area=" <<sqrt(x) << endl;
		}
	Ctriangle() {
		//just for test
		edge1=3;
		edge2=4;
		edge3=5;
	}
	~Ctriangle() {}
};

int main() {
	Ctriangle test;
	cout << "3 4 5" << endl;
	cout << "circumference= "<< test.circumference() << endl;
	test.area();
}
