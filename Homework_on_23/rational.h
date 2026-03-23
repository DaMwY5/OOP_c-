#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
private:
    long long numerator;
    long long denominator;

    void simplify();
    long long gcd(long long a, long long b) const;
    void normalize();

public:
    Rational();
    Rational(long long num);
    Rational(long long num, long long den);
    Rational(const Rational& other);

    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    bool operator==(const Rational& other) const;
    bool operator!=(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator>(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>=(const Rational& other) const;

    Rational& operator=(const Rational& other);
    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    friend std::ostream& operator<<(std::ostream& os, const Rational& r);
    friend std::istream& operator>>(std::istream& is, Rational& r);

    double toDouble() const;
};

#endif