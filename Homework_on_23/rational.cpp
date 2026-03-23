#include "rational.h"
#include <cmath>
#include <cstdlib>

long long Rational::gcd(long long a, long long b) const {
    a = llabs(a);
    b = llabs(b);
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Rational::normalize() {
    if (denominator == 0) {
        denominator = 1;
    }
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

void Rational::simplify() {
    normalize();
    if (numerator == 0) {
        denominator = 1;
        return;
    }
    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(long long num) : numerator(num), denominator(1) {}

Rational::Rational(long long num, long long den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        denominator = 1;
    }
    simplify();
}

Rational::Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {}

Rational Rational::operator+(const Rational& other) const {
    return Rational(
        numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator
    );
}

Rational Rational::operator-(const Rational& other) const {
    return Rational(
        numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator
    );
}

Rational Rational::operator*(const Rational& other) const {
    return Rational(
        numerator * other.numerator,
        denominator * other.denominator
    );
}

Rational Rational::operator/(const Rational& other) const {
    if (other.numerator == 0) {
        return Rational(0, 1);
    }
    return Rational(
        numerator * other.denominator,
        denominator * other.numerator
    );
}

bool Rational::operator==(const Rational& other) const {
    return (numerator == other.numerator && denominator == other.denominator);
}

bool Rational::operator!=(const Rational& other) const {
    return !(*this == other);
}

bool Rational::operator<(const Rational& other) const {
    return (numerator * other.denominator) < (other.numerator * denominator);
}

bool Rational::operator>(const Rational& other) const {
    return other < *this;
}

bool Rational::operator<=(const Rational& other) const {
    return !(*this > other);
}

bool Rational::operator>=(const Rational& other) const {
    return !(*this < other);
}

Rational& Rational::operator=(const Rational& other) {
    if (this != &other) {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

Rational& Rational::operator+=(const Rational& other) {
    *this = *this + other;
    return *this;
}

Rational& Rational::operator-=(const Rational& other) {
    *this = *this - other;
    return *this;
}

Rational& Rational::operator*=(const Rational& other) {
    *this = *this * other;
    return *this;
}

Rational& Rational::operator/=(const Rational& other) {
    *this = *this / other;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rational& r) {
    if (r.denominator == 1) {
        os << r.numerator;
    } else {
        os << r.numerator << "/" << r.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Rational& r) {
    long long num, den = 1;
    char slash;
    
    is >> num;
    if (is.peek() == '/') {
        is >> slash >> den;
    }
    
    r = Rational(num, den);
    return is;
}

double Rational::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}