#ifndef RATIONAL_H
#define RATIONAL_H
#include <QString>
#include "errorhandler.h"

class Rational
{

public:
    Rational(double n,double d);
    /*Accesseurs*/
    double getNum()const;
    double getDen()const;
    /*Mutateurs*/
    void setNum(double d);
    void setDen(double d);
    /*Méthodes spécifiques*/
    void simplify();
    static int pgcd(int a, int b);
    int getType()const;
    /*Opérateurs binaires*/
    Rational operator+(const Rational&)const;
    Rational operator-(const Rational&)const;
    Rational operator*(const Rational&)const;
    Rational operator/(const Rational&)const;
    Rational div(const Rational&)const;
    Rational mod(const Rational&)const;
    /*Opérateurs unaires*/
    Rational neg() const;
    Rational Re()const;
    Rational Im()const;
    /*Opérateurs logiques*/
    bool operator==(const Rational&)const;
    bool operator<(const Rational&)const;
    bool operator<=(const Rational&)const;
    /*--------------------*/
    QString toString() const;
    QString getValue() const;

private:
    double num;
    double den;
    int typLit;

};



#endif // RATIONAL_H
