#include <iostream>
#include <string>
#pragma once 
using namespace std;
class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(); //empty constructor 
    Rational(int a, int b); // constructor 
    Rational(const Rational& a); //copy constr
    void print(); // correction faite 
    void setDenominator(int x); //set d 
    void setNumerator(int x);//set n
    int getDenominator();// get d
    int getNumerator();//get
    void reduce(); 
    Rational operator*(const Rational& a) const ;
    Rational operator+(Rational a); 
    Rational operator-(Rational a);
    Rational operator/(Rational a); // verifier dans exemple si il veulent divise par chiffre ou fraction 
    Rational operator++();
    Rational operator++(int u); 
    Rational operator--(); 
    Rational operator--(int u);
    bool operator>=(Rational a); 
    bool operator<=(Rational a);
    bool operator<(Rational a); 
    bool operator>(Rational a);
    bool operator==(const Rational& num) const; // pas compirs pk const
    bool operator!=(const Rational& num) const; 
   

    /*bool equal(Rational a);
    void reduction();
    Rational add(Rational a);*/

};