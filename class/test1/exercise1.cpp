#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main(int argc, char  *argv[]) {
	if (argc != 4) {
		cout << "error" << endl;
		return 0;
	}
	//int num1 = stoi(argv[1]);
	//int num2 = stoi(argv[2]);
	//ËÆºõ²»Ö§³Öcpp 11
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	if (!strcmp(argv[3], "+")) {
		cout << num1+num2 << endl; 
	}
	else if (!strcmp(argv[3], "-")) {
		cout << num1-num2 << endl;
	}
	else if (!strcmp(argv[3], "*")) {
		cout << num1*num2 << endl;
	}
	else if (!strcmp(argv[3], "/")) {
		if (num2 == 0) {
			cout << "Divided by zero" << endl;
		}
		cout << num1/num2 << endl;
	}
	else {
		cout << "Invaild operator" << endl;
	}
	return 0;
} 
