#ifndef NATIONAL_CLASS
#define NATIONAL_CLASS
#include <string>
using namespace std;

class Rational {
    private:
        int numerator, denominator;
    public:
        Rational(int i, int j);
        Rational();
        int getNumerator();
        int getDenominator();
        const Rational add(const Rational& secondRational);
        const Rational subtract(const Rational& secondRational);
        const Rational multiply(const Rational& secondRational);
        const Rational divide(const Rational& secondRational);
        int compareTo(const Rational& secondRational);
        bool equals(const Rational& secondRational);
        int intValue();
        double doubleValue();
        string toString();
        const Rational operator+(const Rational& secondRational);
        const Rational operator-(const Rational& secondRational);
        const Rational operator*(const Rational& secondRational);
        const Rational operator/(const Rational& secondRational);
        int operator[](int index);
};

#endif