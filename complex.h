#ifndef COMPLEX_H
#define COMPLEX_H
#include <QString>
#include "rational.h"
#include "literal.h"
#include <typeinfo>


class Complex : public Literal
{

public:
    Complex(Rational re,Rational im, typelit lit);
    ~Complex(){}
    Complex(double n1,double d1,double n2, double d2, typelit lit);
    /*Accesseurs*/
    Rational getIm()const;
    Rational getRe()const;
    /*Mutateurs*/
    void setIm(Rational);
    void setRe(Rational);
    void setIm(double);
    void setRe(double);
    /*Type*/
    typelit getType()const;
    void setType(typelit lit);
    /*Opérateurs binaires*/
    Literal* operator+(const Literal*);
    Literal* operator-(const Literal*);
    Literal* operator*(const Literal*);
    Literal* operator/(const Literal*);
    Literal* dollar(const Literal*);
    Literal* mod(const Literal*);
    Literal* div(const Literal*);
    /*Opérateurs unaires*/
    Literal* neg();
    Literal* num();
    Literal* den();
    Literal* re();
    Literal* im();
    /*Opérateurs logiques*/
    Literal* operator==(Literal*);
    Literal* operator<(Literal*);
    Literal* operator<=(Literal*);
    Literal* operator!=( Literal*);
    Literal* operator>(Literal*);
    Literal* operator>=(Literal*);
    Literal* oAnd(Literal*);
    Literal* oOr(Literal*);
    Literal* oNot();
    /*--------------------*/
    bool compToBool(Complex*);
    QString toString()const;
    QString getValue()const;

private:
    Rational pRe;
    Rational pIm;
    typelit type;

};

#endif // COMPLEX_H
