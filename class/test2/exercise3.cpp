//需要利用面向对象的思想。
//我的思路是，做成一个环，所有的学生组成一个环，有id(序号)， out(是否出列)， next(下面一个人的指针)。然后循环即可以。
#include <iostream>
using namespace std;

class Student {
    private:
        int id;
        Student* next;
        bool out;
    public:
        Student(int _id) : id(_id) {out = false;}
        Student(){}
        ~Student() {}
        Student* getNext() { return next; }
        void printId(){cout << id << endl;}
        void setNext(Student* _next) { next = _next; }
        bool isOut() { return out; }
        void setOut() { out = true; }
};

int main() {
    //n=10, w=1, s=2.
    int num=10, w=1, s=3;
    Student stus[num] ;
    for (int i=0; i<num; i++) {
        stus[i] = Student(i+1);
    }
    for (int i=0; i<num; i++) {
        if (i==num-1) stus[i].setNext(stus+0);
        else stus[i].setNext(stus+(i+1));
    }
    Student *current = stus+w-1;
    for (int i=0; i<num; i++) {
        int curr = 0;
        while(curr < s){
            if(!current->isOut()) {
                curr++;  
            }
            if(curr == s) {
                current->printId();
                current->setOut();
            }
            current = current->getNext();
            
        }
    }
}