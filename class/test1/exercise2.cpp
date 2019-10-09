#include <iostream>
using namespace std;

int array_transer(int *array, int row, int col) {
	//one-dimensional array instead of two-dimensional
	//only using one-dimension array, two-dimensional array is too complex, you will make a lot mistakes.
	int *temp_array =(int*) new int[row*col];
	for (int i=0; i<row; i++) {
		for (int j=0; j<col; j++) {
			*(temp_array+j*col+(col-i-1)) = *((int*)array+i*col+j);
		}
	}
	array = (int*)temp_array;
}

int main() {	
	int test_array[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
	array_transer((int*)test_array, 3, 3);
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cout << *((int*)test_array+i*3+j) << " ";
		}
		cout << endl;
	}
	return 0;
}
