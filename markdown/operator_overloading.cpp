#include <iostream>
using namespace std;

class Time {
    private:
        int hours;
        int minutes;
    public:
        Time(): hours(0), minutes(0) {}
        Time(int h, int m) {
            hours = h;
            minutes = m;
        }
        void displayTime() {
            cout << "Hour:" << hours << "   Minutes:" << minutes << endl;
        }

        //重点重载前缀自增运算符 (++i)
        Time operator++ () {
            ++minutes;
            if (minutes >= 60) {
                ++hours;
                minutes -= 60;
            }
            return Time(hours, minutes);
        }
        //重载后缀自增运算符(i++)
        Time operator++ (int) {
            Time T(hours, minutes);
            ++minutes;
             if (minutes >= 60) {
                ++hours;
                minutes -= 60;
            }
            return T;
        }
};

int main() {
    Time T1(11, 59), T2(10, 40);
    ++T1;                    // T1 加 1
    T1.displayTime();        // 显示 T1
    ++T1;                    // T1 再加 1
    T1.displayTime();        // 显示 T1
 
    T2++;                    // T2 加 1
    T2.displayTime();        // 显示 T2
    T2++;                    // T2 再加 1
    T2.displayTime();        // 显示 T2
    return 0;
    }
