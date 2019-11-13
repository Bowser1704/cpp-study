//encoding:utf-8
#include <iostream>
using namespace std;

class Employee
{
private:
    char *m_name;
    char *m_no;

public:
    Employee(char *name, char *no) : m_name(name), m_no(no) { cout << "Employee类的构造函数调用\n"; }
    virtual ~Employee()
    {
        cout << "Employee类的析构函数调用\n";
    }
    virtual void display() { cout << "姓名: " << m_name << "\n"
                          << "员工编号: " << m_no << endl; }
};

class Leader : public Employee
{
private:
    char *m_posdes;

public:
    Leader(char *name, char *no, char *posdes) : Employee(name, no), m_posdes(posdes) { cout << "Leader类的构造函数调用\n"; }
    virtual ~Leader()
    {
        cout << "Leader类的析构函数调用\n";
    }
    virtual void display()
    {
        Employee::display();
        cout << "职位描述：" << m_posdes << endl;
    }
};

int main()
{
    Employee *pe = new Leader("张三", "0001", "部门经理");
    pe->display();
    delete pe;
    return 0;
}