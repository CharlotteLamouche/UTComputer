#ifndef LITERAL_H
#define LITERAL_H
#include <QString>
#include <cmath>

typedef enum t{entier,rationnel,complexe,reel}typelit;

class Literal
{

public:
    virtual ~Literal(){}
    virtual QString toString()const=0;
    virtual QString getValue()const;
    virtual typelit getType()const{return entier;}
    virtual Literal* operator+(const Literal*) =0;
    virtual Literal* operator-(const Literal*) =0;
    virtual Literal* operator*(const Literal*) =0;
    virtual Literal* operator/(const Literal*) =0;
    virtual Literal* neg() =0;
    virtual Literal* num() =0;
    virtual Literal* den() =0;
    virtual Literal* dollar(const Literal*) =0;
    virtual Literal* re() =0;
    virtual Literal* im() =0;
    virtual Literal* mod(const Literal*) =0;
    virtual Literal* div(const Literal*) =0;
    virtual Literal* operator==(Literal*) =0;
    virtual Literal* operator<(Literal*) =0;
    virtual Literal* operator<=(Literal*) =0;
    virtual Literal* operator!=(Literal*) =0;
    virtual Literal* operator>(Literal*) =0;
    virtual Literal* operator>=(Literal*) =0;
    virtual Literal* oAnd(Literal*) =0;
    virtual Literal* oOr(Literal*) =0;
    virtual Literal* oNot() =0;

protected:
    Literal(){}

};

#endif // LITERAL_H
