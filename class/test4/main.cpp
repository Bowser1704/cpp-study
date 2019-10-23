#include "Rational.h"
#include <iostream>

int main()
{
    Rational test_1_2 = Rational(1, 2), test_2_3 = Rational(2, 3), test_4_6 = Rational(4, 6);
    cout << "test_1_2 " << test_1_2.getNumerator() << test_1_2.getDenominator() << endl;
    Rational test_7_6 = test_1_2.add(test_2_3);
    cout << "test_7_6 " << test_7_6.getNumerator() << test_7_6.getDenominator() << endl;
    Rational test2_7_6 = test_1_2 + test_2_3;
    cout << "test2_7_6 " << test2_7_6.getNumerator() << test2_7_6.getDenominator() << endl;
    Rational test_1_6 = test_2_3.subtract(test_1_2);
    cout << "test_1_6 " << test_1_6.getNumerator() << test_1_6.getDenominator() << endl;
    Rational test2_1_6 = test_2_3 - test_1_2;
    cout << "test2_1_6 " << test2_1_6.getNumerator() << test2_1_6.getDenominator() << endl;
    Rational test_1_3 = test_1_2 * test_2_3;
    cout << "test_1_3 " << test_1_3.getNumerator() << test_1_3.getDenominator() << endl;

    cout << "test_4_6 compareTo test_7_6 " << test_4_6.compareTo(test_7_6) << endl;
    cout << "test_4_6 equals test_2_3 " << test_4_6.equals(test_2_3) << endl;

    cout << "test_4_6 " << test_4_6.getNumerator() << test_4_6.getDenominator() << endl;
    cout << "test_4_6 intValue " << test_4_6.intValue() << endl;
    cout << "test_4_6 doubleValue " << test_4_6.doubleValue() << endl;
    cout << "test_4_6 stringValue " << test_4_6.toString() << endl;

    cout << "test_1_3 " << test_1_3[0] << " " << test_1_3[1] << endl;
    return 0;
}
