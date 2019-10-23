#include "Rational.h"

Rational::Rational()
{
    numerator = 0;
    denominator = 0;
}
Rational::Rational(int i, int j) : numerator(i), denominator(j)
{
    int k = (numerator > denominator) ? denominator : numerator;
    while (k > 1)
    {
        if (!(numerator % k || denominator % k))
        {
            numerator /= k;
            denominator /= k;
            k = (numerator > denominator) ? denominator : numerator;
        }
        k--;
    }
}
int Rational::getNumerator() { return numerator; }
int Rational::getDenominator() { return denominator; }
const Rational Rational::add(const Rational &secondRational)
{
    int tempNumerator = numerator * secondRational.denominator + secondRational.numerator * denominator;
    int tempDenominator = denominator * secondRational.denominator;
    return Rational(tempNumerator, tempDenominator);
}
const Rational Rational::subtract(const Rational &secondRational)
{
    return this->add(Rational(secondRational.numerator * -1, secondRational.denominator));
}
const Rational Rational::multiply(const Rational &secondRational)
{
    int tempNumerator = numerator * secondRational.numerator;
    int tempDenominator = denominator * secondRational.denominator;
    return Rational(tempNumerator, tempDenominator);
}
const Rational Rational::divide(const Rational &secondRational)
{
    return multiply(Rational{secondRational.denominator, secondRational.numerator});
}
int Rational::compareTo(const Rational &secondRational)
{
    Rational subRational = subtract(secondRational);
    if (subRational.denominator < 0 || subRational.numerator < 0)
        return -1;
    else if (subRational.denominator > 0 || subRational.numerator > 0)
        return 1;
    else
        return 0;
}
bool Rational::equals(const Rational &secondRational)
{
    return (numerator == secondRational.numerator && denominator == secondRational.denominator);
}
int Rational::intValue()
{
    return numerator / denominator;
}
double Rational::doubleValue()
{
    return 1.0 * numerator / denominator;
}
string Rational::toString()
{
    if (denominator == 1)
        return to_string(numerator);
    else
    {
        char buf[100];
        sprintf(buf, "%d / %d", numerator, denominator);
        return string(buf);
    }
}
const Rational Rational::operator+(const Rational &secondRational)
{
    int tempNumerator = numerator * secondRational.denominator + secondRational.numerator * denominator;
    int tempDenominator = denominator * secondRational.denominator;
    return Rational(tempNumerator, tempDenominator);
}
const Rational Rational::operator-(const Rational &secondRational)
{
    return *this + Rational(secondRational.numerator * -1, secondRational.denominator);
}
const Rational Rational::operator*(const Rational &secondRational)
{
    int tempNumerator = numerator * secondRational.numerator;
    int tempDenominator = denominator * secondRational.denominator;
    return Rational(tempNumerator, tempDenominator);
}
const Rational Rational::operator/(const Rational &secondRational)
{
    return *this * Rational(secondRational.denominator, secondRational.numerator);
}
int Rational::operator[](int index)
{
    if (index == 0)
        return numerator;
    if (index == 1)
        return denominator;
}