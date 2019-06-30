//
// Created by bowser on 6/29/19.
//
#include <iostream>
#include <string>
using namespace std;

int main(){
    string user_first_name, user_last_name;
    cout << "please input first name:";
    cin >> user_first_name;
    cout << "please input last name:";
    cin >> user_last_name;
    cout << "your name:"
         << user_first_name+user_last_name;
    return 0;
}
