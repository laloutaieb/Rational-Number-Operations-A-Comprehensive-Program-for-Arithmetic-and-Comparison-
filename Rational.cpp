#include "Rational.h"

void Rational::reduce() // ok 
{
    if (numerator % denominator == 0)
    {
        int x = (numerator / denominator);
        numerator = x;
        denominator = 1;
    }
    else
    {
        for (int i = denominator; i > 1; i--) // we begin by the denominator, for 
        {
            if (numerator % i == 0 && denominator % i == 0)
            {
                numerator /= i;
                denominator /= i;

            }
        }
    }
}

Rational Rational::operator*(const Rational& a) const // ok changer head 
{
    Rational b; 
    b.numerator = a.numerator * numerator ; 
    b.denominator = a.denominator * denominator;
    b.reduce(); 
    return b;
}

Rational::Rational() //ok
{
	numerator = 1; 
	denominator = 1; 
}

Rational::Rational(int a, int b) // ok 
{
	numerator = a;
    if(b>0)
	denominator = b;
    if (b == 0)
        denominator = 1; 
    if (b < 0)
    {
        b *= -1;
        a *= -1;
        denominator = b; 
        numerator = a; 
    }
}

Rational::Rational(const Rational& a) // ok 
{
	numerator = a.numerator; 
	denominator = a.denominator; 
}

void Rational::setDenominator(int x) // ok 
{
    //mehane = x;
    if (x == 0)
    {
        denominator = 1;
    } // if it's zero or negativ it's change in 1
    else if (x > 0)
        denominator = x;
    else if (x < 0)
    {
        denominator= -x;
        numerator = -numerator;
    }
}

void Rational::setNumerator(int x) //ok
{
    numerator = x;
}
int Rational::getNumerator() //ok
{
    return numerator;
}
int Rational::getDenominator() //ok
{
    return denominator;
}

void Rational::print() //ok
{
    if (denominator != 1)
        cout << numerator << '/' << denominator;
    else
        cout << numerator; 
}
 
Rational Rational::operator+(Rational r) //ok
{
    int x = numerator * r.denominator + r.numerator * denominator; 
	int y = denominator * r.denominator; 
    Rational a(x, y);
    a.reduce(); 
    return a; // dans le constructor il faut créé l'objet ? 
}

Rational Rational::operator-(Rational r) //ok
{
    // y a normalement un moyen de simplifier avec this 
    int x = numerator * r.denominator - r.numerator * denominator;
    int y = denominator * r.denominator;
    Rational a(x, y);
    a.reduce();
    return a;
}

Rational Rational::operator/(Rational a) // ok 
{
    // a/b / c/d = a/b * d/c 
    int x = numerator * a.denominator; 
    int y = denominator * a.numerator; 
    Rational b(x,y);
    b.reduce(); 
    return b; 
}

Rational Rational::operator++() //ok 
{
    numerator += denominator; 
    this->reduce(); 
    return *this; 
}   

Rational Rational::operator--()
{
    numerator -= denominator; 
    this->reduce();
    return *this; 
}

Rational Rational::operator--(int u)
{
    Rational temp = *this;
    numerator -= denominator;
    return temp;
}

Rational Rational::operator++(int u)
{
    Rational temp = *this;
    numerator += denominator;
    return temp;
}


bool Rational::operator>=(Rational a)
{
    double x = (double)numerator / denominator;
    double y = (double)a.numerator / a.denominator;
    if (x >= y)
        return 1;
    else
        return 0; 
}


bool Rational::operator<=(Rational a)
{
    double x = (double)numerator / denominator;
    double y = (double)a.numerator / a.denominator;
    if (x <= y)
        return 1;
    else
        return 0;
}

bool Rational::operator<(Rational a)
{
    double x = (double) numerator / denominator;
    double y = (double) a.numerator / a.denominator;
    if (x < y)
        return 1;
    else
        return 0;
}

bool Rational::operator>(Rational a)
{
    double x = (double) numerator / denominator;
    double y = (double) a.numerator / a.denominator;
    if (x > y)
        return 1;
    else
        return 0;
}


bool Rational::operator==(const Rational& num) const // pas claire pourquoi on met const dans les deux; 
{
    Rational temp1 = *this;
    Rational temp2 = num;
    temp1.reduce();
    temp2.reduce();
    return temp1.numerator == temp2.numerator &&
        temp1.denominator == temp2.denominator;
}

bool Rational::operator!=(const Rational& num) const
{
    Rational temp1 = *this; 
    Rational temp2 = num; 
    temp1.reduce();
    temp2.reduce();
    return temp1.numerator != temp2.numerator ||
        temp1.denominator != temp2.denominator;
}


//
//bool Rational::equal(Rational a)
//{//to check if its equal we need to chek the mone AND the mahane
//    if (a.denominator == denominator && a.numerator == numerator)
//        return true;
//    else
//        return false;
//}
//
//void Rational::reduction()
//{//to do the reduction we use the modulo % 
//    for (int i = denominator; i > 0; i--)
//    {
//        if (numerator % i == 0 && denominator % i == 0)
//        {
//            numerator /= i;
//            denominator /= i;
//        }
//    }
//}
//
//Rational Rational::add(Rational r)
//{//to add two fractions, they must have the same denominator.
//    Rational r3;
//    if (denominator != r.denominator)
//    {
//        int x = r.numerator * denominator;
//        int y = r.denominator * numerator;
//        r3.numerator = x + y;
//        r3.denominator = denominator * r.denominator;
//    }
//    else //the case they have the same denominator 
//    {
//        r3.numerator = (r.numerator + numerator);
//        r3.denominator = (r.denominator);
//    }
//    r3.reduction();
//    return r3;
//}
//
