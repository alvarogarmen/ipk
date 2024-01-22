
class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    };
    Rational()
    {
        this->numerator = 0;
        this->denominator = 1;
    };

    Rational operator+(Rational b)
    {
        Rational c;
        c.numerator = this->numerator + b.numerator;
        c.denominator = this->denominator + b.denominator;
        return c;
    };

    Rational operator-(Rational b)
    {
        Rational c;
        c.numerator = this->numerator - b.numerator;
        c.denominator = this->denominator - b.denominator;
        return c;
    };
    Rational operator-()
    {
        Rational c;
        c.numerator = -this->numerator;
        c.denominator = -this->denominator;
        return c;
    };

    Rational operator*(Rational b)
    {
        Rational c;
        c.numerator = this->numerator * b.numerator;
        c.denominator = this->denominator * b.denominator;
        return c;
    };
    Rational operator/(Rational b)
    {
        Rational c;
        c.numerator = this->numerator / b.numerator;
        c.denominator = this->denominator / b.denominator;
        return c;
    };
};