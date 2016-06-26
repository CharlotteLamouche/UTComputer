///
/// \class     Expression
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Gestion des expressions
///
/// \details   Cette classe hérite de la classe abstraite Literal et gère la manipulation des expressions.
///

#include "expression.h"
#include <iostream>

Expression::Expression(const QString& e,typeExp ty):Literal(),ty(ty), exp(e)
{

    exp.remove(0,1);
    exp.remove(exp.length()-1,1);
    /**
    * \brief    Constructeur
    * \details  Permet de construire un objet de type Expression
    * \param    e Un QString
    */

}

typeExp Expression::getTypeExp()
{
    return ty;
    /**
     * \brief    Connaître le type d'entrée (expression ou program)
     * \return   Un type énuméré : expression ou program
     */
}

void Expression::setExp(QString s)
{
    exp = QString(s);
    /**
     * \brief    Modifier l'expression
     * \param    s Un QString qui remplace l'ancienne expression
     */
}

QString Expression::toString() const
{
    if(ty==expression)
    {
        QString temp = exp;
//        temp.replace('\t',' ');
//        temp.replace('\n',' ');
        if(exp.size()>50)
            return (QString("'"+temp.mid(0,46)+"...'"));
        return ('\''+temp+'\'');
    }
    else
    {
        QString temp = exp;
        temp.replace('\t',' ');
        temp.replace('\n',' ');
        if(temp.size()>50)
            return (QString("["+temp.mid(0,46)+"...]"));
        return ('['+temp+']');
    }
    /**
     * \brief    Obtenir l'expression dans un QString avec guillemets
     * \return   Un QString contenant l'expression
     */
}

QString Expression::getValue() const
{
    return (exp);
    /**
     * \brief    Obtenir l'expression dans un QString sans guillemets
     * \return   Un QString contenant l'expression
     */
}

Literal* Expression::operator+(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    if(keepParenthesis(1,tmp->getValue()))
    {
        tmp->insert(0,"(");
        tmp->insert(tmp->size(),")");
    }
    if(keepParenthesis(1,tmp2->getValue()))
    {
        tmp2->insert(0,"(");
        tmp2->insert(tmp2->size(),")");
    }
    res->insert(0,tmp->getValue());
    res->insert(res->size(),"+");
    res->insert(res->size(),tmp2->getValue());
    return res;
    /**
     * \brief    Somme
     * \details  Surcharge de l'opérateur + permettant de sommer une Expression avec une Literal
     * \param    c La Literal à sommer
     * \return   La Literal résultant de la somme
     */
}
Literal* Expression::operator-(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    if(keepParenthesis(1,tmp->getValue()))
    {
        tmp->insert(0,"(");
        tmp->insert(tmp->size(),")");
    }
    if(keepParenthesis(1,tmp2->getValue()))
    {
        tmp2->insert(0,"(");
        tmp2->insert(tmp2->size(),")");
    }
    res->insert(0,tmp->getValue());
    res->insert(res->size(),"-");
    res->insert(res->size(),tmp2->getValue());
    return res;
    /**
     * \brief    Différence
     * \details  Surcharge de l'opérateur - permettant de soustraire une Literal à une Expression
     * \param    c La Literal à soustraire
     * \return   La Literal résultant de la différence
     */
}

Literal* Expression::operator*(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    if(keepParenthesis(2,tmp->getValue()))
    {
        tmp->insert(0,"(");
        tmp->insert(tmp->size(),")");
    }
    if(keepParenthesis(2,tmp2->getValue()))
    {
        tmp2->insert(0,"(");
        tmp2->insert(tmp2->size(),")");
    }
    res->insert(0,tmp->getValue());
    res->insert(res->size(),"*");
    res->insert(res->size(),tmp2->getValue());
    return res;
    /**
     * \brief    Produit
     * \details  Surcharge de l'opérateur * permettant de multiplier une Expression avec une Literal
     * \param    c La Literal à multiplier
     * \return   La Literal résultant du produit
     */
}

Literal* Expression::operator/(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    if(keepParenthesis(2,tmp->getValue()))
    {
        tmp->insert(0,"(");
        tmp->insert(tmp->size(),")");
    }
    if(keepParenthesis(2,tmp2->getValue()))
    {
        tmp2->insert(0,"(");
        tmp2->insert(tmp2->size(),")");
    }
    res->insert(0,tmp->getValue());
    res->insert(res->size(),"/");
    res->insert(res->size(),tmp2->getValue());
    return res;
    /**
     * \brief    Division
     * \details  Surcharge de l'opérateur / permettant de diviser une Expression par une Literal
     * \param    c La Literal à diviser
     * \return   La Literal résultant de la division
     */
}

void Expression::insert(int i, const QString& s)
{
    exp.insert(i,s);
    /**
    * \brief    Insérer une chaine à l'indice i
    * \param    i Un int l'indice de l'insertion
    * \param    s La chaîne à insérer
    */
}

int Expression::size()
{
    return exp.size();
    /**
     * \brief    Taille de l'expression
     * \return   Un int indiquant la taille de l'expression
     */
}

Literal* Expression::num()
{
    Expression * res = new Expression("",expression);
    res->insert(0,"NUM(");
    res->insert(res->size(),exp);
    res->insert(res->size(),")");
    return res;
    /**
     * \brief    Numérateur
     * \details  Fonction num de l'Expression
     * \return   La Literal résultant du numérateur
     */
}

Literal* Expression::den()
{
    Expression * res = new Expression("",expression);
    res->insert(0,"DEN(");
    res->insert(res->size(),exp);
    res->insert(res->size(),")");
    return res;
    /**
     * \brief    Dénominateur
     * \details  Fonction den de l'Expression
     * \return   La Literal résultant du dénominateur
     */
}

Literal* Expression::neg()
{
    Expression * res = new Expression("",expression);
    res->insert(0,"NEG(");
    res->insert(res->size(),exp);
    res->insert(res->size(),")");
    return res;
    /**
     * \brief    Négatif
     * \details  Fonction neg de l'Expression
     * \return   La Literal résultant de la fonction négatif
     */
}
Literal* Expression::re()
{
    Expression * res = new Expression("",expression);
    res->insert(0,"RE(");
    res->insert(res->size(),exp);
    res->insert(res->size(),")");
    return res;
    /**
     * \brief    Partie réelle
     * \details  Fonction re de l'Expression
     * \return   La Literal résultant de la partie réelle
     */
}
Literal* Expression::im()
{
    Expression * res = new Expression("",expression);
    res->insert(0,"IM(");
    res->insert(res->size(),exp);
    res->insert(res->size(),")");
    return res;
    /**
     * \brief    Partie imaginaire
     * \details  Fonction im de l'Expression
     * \return   La Literal résultant de la partie imaginaire
     */
}

Literal* Expression::mod(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"MOD("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Modulo
     * \details  Fonction modulo de l'Expression par une Literal
     * \param    c La Literal modulo à l'Expression
     * \return   La Literal résultant du modulo
     */
}

Literal* Expression::div(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"DIV("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Division entière
     * \details  Fonction division entière de l'Expression par une Literal
     * \param    c La Literal divisée à l'Expression
     * \return   La Literal résultant de la division entière
     */
}

Literal* Expression::dollar(const Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    tmp->insert(0,"(");
    tmp->insert(tmp->size(),")");
    tmp2->insert(0,"(");
    tmp2->insert(tmp2->size(),")");
    res->insert(0,tmp->getValue());
    res->insert(res->size(),"$");
    res->insert(res->size(),tmp2->getValue());
    return res;
    /**
     * \brief    Dollar
     * \details  Fonction dollar de l'Expression par une Literal
     * \param    c La Literal qui formera la partie imaginaire
     * \return   La Literal résultante
     */
}

bool Expression::keepParenthesis(int prio,QString s)
{
    bool res = false;
    for(int i=0;i<s.size();i++)
    {
        if(s.at(i) == '(')
        {
            while(s.at(i)!=')' && i< s.size())
            {
                i++;
                if(i == s.size())
                    break;
            }
        }
        if(s.at(i) == '$')
            i++;
        if((s.at(i) == '+' || s.at(i) == '-') && prio!=1)
            res = true;

        if((s.at(i) == '*' || s.at(i) == '/') && prio!=2)
            res = true;
    }
    return res;
    /**
     * \brief    Conservation des parenthèses
     * \details  Permet de retirer les parenthèses inutiles dans une expression
     * \param    prio L'entier qui représente le poids de priorité
     * \param    s La chaîne à tester
     * \return   Un bool, vrai si il faut garder les parenthèse, faux sinon
     */
}

Literal* Expression::operator==(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"=("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction d'égalité
     * \details  Permet d'appliquer l'égalité sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::operator<(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"<("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction inférieur strict
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::operator<=(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"=<("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction inférieur ou égal
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::operator!=(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"!=("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction de différence
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::operator>(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,">("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction supérieur strict
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::operator>=(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,">=("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction supérieur ou égal
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::oAnd(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"AND("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction and
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::oOr(Literal* c)
{
    Expression * tmp = new Expression(this->toString(),expression);
    Expression * tmp2;
    if(QString(typeid(*c).name())==COMPLEX_ID)
    {
       tmp2 = new Expression("'"+c->toString()+"'",expression);

    }
    else
    {
        tmp2 = (Expression*)c;
    }
    Expression * res = new Expression("",expression);
    res->insert(0,"OR("+tmp->getValue()+","+tmp2->getValue()+")");
    return res;
    /**
     * \brief    Fonction or
     * \details  Permet d'appliquer la comparaison sur deux expressions
     * \param    c La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Expression::oNot()
{
    Expression * res = new Expression("",expression);
    res->insert(0,"NOT(");
    res->insert(res->size(),exp);
    res->insert(res->size(),")");
    return res;
    /**
     * \brief    Fonction not
     * \details  Permet d'appliquer le non logique
     * \return   La Literal résultant de not
     */
}
