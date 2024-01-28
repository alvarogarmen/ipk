#include <iostream>

int ggT(int a, int b)
{
    if (0 > a)
    {
        a = -a;
    }
    if (0 > b)
    {
        b = -b;
    }
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
};

class Rational
{
private:
    int numerator;
    int denominator;

public:
    explicit Rational(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            this->numerator = 0;
            this->denominator = 1;
            std::cout << "Error: Division by zero" << std::endl;
        }
        else if (numerator < 0)
        {  // move the - to the denominator, siehe Aufgabestellung
            int t = ggT(numerator, denominator);

            this->numerator = -numerator / t;
            this->denominator = -denominator / t;
        }
        else  // if both are positive let them be
        {
            int t = ggT(numerator, denominator);
            this->numerator = numerator / t;
            this->denominator = denominator / t;
        }
    };
    Rational()
    {
        this->numerator = 0;
        this->denominator = 1;
    };
    int getNumerator() { return this->numerator; };

    int getDenominator() { return this->denominator; };

    Rational operator+(const Rational& b) const
    {
        int numerator = (this->numerator * b.denominator) + (b.numerator * this->denominator);
        int denominator = this->denominator * b.denominator;
        Rational c(numerator, denominator);
        return c;
    }

    Rational operator-(const Rational& b) const
    {
        int numerator = (this->numerator * b.denominator) - (b.numerator * this->denominator);
        int denominator = this->denominator * b.denominator;
        Rational c(numerator, denominator);
        return c;
    }

    Rational operator-()
    {
        Rational c(-this->numerator, this->denominator);
        return c;
    };

    Rational operator*(Rational b)
    {
        int numerator = this->numerator * b.numerator;
        int denominator = this->denominator * b.denominator;
        Rational c(numerator, denominator);
        return c;
    };

    Rational operator/(Rational b)
    {
        int numerator = this->numerator * b.denominator;
        int denominator = this->denominator * b.numerator;
        Rational c(numerator, denominator);
        return c;
    };

    double eval() { return this->numerator / this->denominator; };

    Rational operator=(Rational b)
    {
        Rational c;
        c.numerator = b.numerator;
        c.denominator = b.denominator;
        return c;
    };

    bool operator>(Rational b) { return (this->eval() > b.eval()); };
    bool operator<(Rational b) { return (this->eval() < b.eval()); };
    bool operator>=(Rational b) { return (this->eval() >= b.eval()); };
    bool operator<=(Rational b) { return (this->eval() <= b.eval()); };

    bool operator!=(Rational b) { return (this->eval() != b.eval()); };

    double operator+(double b) { return (this->eval() + b); };
    double operator-(double b) { return (this->eval() - b); };
    double operator*(double b) { return (this->eval() * b); };
    double operator/(double b) { return (this->eval() / b); };

    friend double operator+(double b, Rational& a) { return (a.eval() + b); };
    friend double operator-(double b, Rational& a) { return (a.eval() - b); };
    friend double operator*(double b, Rational& a) { return (a.eval() * b); };
    friend double operator/(double b, Rational& a) { return (a.eval() / b); };

    Rational operator+=(Rational& b)
    {
        Rational c;
        c = *this + b;
        return c;
    };
    Rational operator-=(Rational& b)
    {
        Rational c;
        c = *this - b;
        return c;
    };
    Rational operator*=(Rational& b)
    {
        Rational c;
        c = *this * b;
        return c;
    };
    Rational operator/=(Rational& b)
    {
        Rational c;
        c = *this / b;
        return c;
    };

    bool operator==(Rational b) { return (this->eval() == b.eval()); };

    explicit operator bool() const { return this->numerator != 0; }

    friend std::ostream& operator<<(std::ostream& os, const Rational& obj)
    {
        if (obj.denominator == 1)
        {
            os << obj.numerator;
            return os;
        }
        os << obj.numerator << " / " << obj.denominator;
        return os;
    }
};