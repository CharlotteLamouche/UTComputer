#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "literal.h"
#include <QString>
#include <typeinfo>
#ifdef Q_OS_WIN
#define EXPRESSION_ID "class Expression"
#define COMPLEX_ID "class Complex"
#else
#define EXPRESSION_ID "10Expression"
#define COMPLEX_ID "7Complex"
#endif

typedef enum typeExp{expression,program}typeExp;
class Expression : public Literal
{

public:
    Expression(const QString& e,typeExp ty);
    typeExp getTypeExp();
    void setExp(QString s);
    QString toString() const;
    QString getValue() const;
    Literal* operator+(const Literal*);
    Literal* operator-(const Literal*);
    Literal* operator*(const Literal*);
    Literal* operator/(const Literal*);

    Literal* mod(const Literal*);
    Literal* div(const Literal*);
    Literal* dollar(const Literal*);

    Literal* num();
    Literal* den();
    Literal* re();
    Literal* im();
    Literal* neg();

    Literal* operator==(Literal*);
    Literal* operator<(Literal*);
    Literal* operator<=(Literal*);
    Literal* operator!=(Literal*);
    Literal* operator>(Literal*);
    Literal* operator>=(Literal*);
    Literal* oAnd(Literal*);
    Literal* oOr(Literal*);
    Literal* oNot();

private:
    void insert(int i, const QString& s);
    bool keepParenthesis(int prio,QString s);
    int size();
    typeExp ty;
    QString exp;

};

#endif // EXPRESSION_H
