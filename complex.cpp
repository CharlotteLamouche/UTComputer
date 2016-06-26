///
/// \class     Complex
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Gestion des nombres complexes
///
/// \details   Cette classe hérite de la classe abstraite Literal et gère la manipulation des nombres complexes, et donc des réels, des rationnels et des entiers.
///

#include "complex.h"
#include <cmath>
#include <iostream>

Complex::Complex(Rational re,Rational im, typelit lit):pRe(re),pIm(im),type(lit)
{
    /**
     * \brief    Constructeur
     * \details  Crée un objet de type Complex
     * \param    re Un Rationnel correspondant à la partie réelle du Complex
     * \param    im Un Rationnel correspondant à la partie imaginaire du Complex
     * \param    lit Un typelit pour connaître le type de la Littérale rentrée
     */

}

Complex::Complex(double n1,double d1,double n2, double d2, typelit lit):Literal(),pRe(Rational(n1,d1)),pIm(Rational(n2,d2)),type(lit)
{
    /**
     * \brief    Constructeur
     * \details  Crée un objet de type Complex
     * \param    n1 Un double correspondant au numérateur de la partie réelle du Complex
     * \param    d1 Un double correspondant au dénominateur de la partie réelle du Complex
     * \param    n2 Un double correspondant au numérateur de la partie imaginaire du Complex
     * \param    d2 Un double correspondant au dénominateur de la partie imaginaire du Complex
     * \param    lit Un typelit pour connaître le type de la Littérale rentrée
     */

}

Rational Complex::getIm()const
{
    return pIm;
    /**
    * \brief    Obtenir la partie imaginaire
    * \return   La partie imaginaire du Complex
    */
}

Rational Complex::getRe()const
{
    return pRe;
    /**
     * \brief    Obtenir la partie réelle
     * \return   La partie réelle du Complex
     */
}

typelit Complex::getType()const
{
    return(type);
    /**
     * \brief    Connaître le type
     * \return   Un type énuméré : reel, entier, rationnel ou complexe
     */
}

void Complex::setType(typelit lit)
{
    type=lit;
    /**
     * \brief    Modifier le type
     * \param    lit Un typelit qui remplace l'ancienne valeur
     */
}

void Complex::setIm(Rational i)
{
    pIm = i;
    /**
     * \brief    Modifier la partie imaginaire
     * \param    i Un Rationnel qui remplace l'ancienne partie imaginaire
     */
}

void Complex::setRe(Rational r)
{
    pRe = r;
    /**
     * \brief    Modifier la partie réelle
     * \param    r Un Rationnel qui remplace l'ancienne partie réelle
     */
}
void Complex::setIm(double d)
{
    pIm.setNum(d);
    pIm.setDen(1);
    /**
     * \brief    Modifier la partie imaginaire
     * \param    d Un double qui remplace l'ancienne partie imaginaire (le numérateur)
     */
}
void Complex::setRe(double d)
{
    pRe.setNum(d);
    pRe.setDen(1);
    /**
     * \brief    Modifier la partie réelle
     * \param    d Un double qui remplace l'ancienne partie réelle (le numérateur)
     */
}


Literal* Complex::operator+(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex *sum = new Complex(0,1,0,1,this->getType());
    sum->setRe(this->getRe().operator +(aux->getRe()));
    sum->setIm(this->getIm().operator +(aux->getIm()));
    if(sum->getIm().getNum() !=0)
        sum->setType(complexe);
    else
    {
        if(sum->getIm().getNum() ==0) {
            if(sum->getRe().getDen()==1)
                sum->setType(entier);
            else
                sum->setType(rationnel);
        }
    }
    if(this->getType()==reel || l->getType()==reel) {
        Rational temp (sum->getRe().getNum()/sum->getRe().getDen(),1);
        sum->setRe(temp);
    }
    return sum;
    /**
     * \brief    Somme
     * \details  Surcharge de l'opérateur + pour sommer un Complex avec une Literal
     * \param    l La Literal à sommer au Complex
     * \return   Le résultat de la somme qui est une Literal
     */
}

Literal* Complex::operator-(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex *sous = new Complex(0,1,0,1,this->getType());
    sous->setRe(this->getRe().operator -(aux->getRe()));
    sous->setIm(this->getIm().operator -(aux->getIm()));
    if(sous->getIm().getNum() !=0)
        sous->setType(complexe);
    else
    {
        if(sous->getIm().getNum() ==0) {
        if(sous->getRe().getDen()==1)
            sous->setType(entier);
        else
            sous->setType(rationnel);
        }
    }
    if(this->getType()==reel || l->getType()==reel) {
        Rational temp (sous->getRe().getNum()/sous->getRe().getDen(),1);
        sous->setRe(temp);
    }
    return sous;
    /**
     * \brief    Différence
     * \details  Surcharge de l'opérateur - pour soustraire une Literal à un Complex
     * \param    l La Literal à soustraire au Complex
     * \return   Le résultat de différence qui est une Literal
     */
}

Literal* Complex::operator*(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex *mult = new Complex(0,1,0,1,this->getType());
    mult->setRe(this->getRe().operator *(aux->getRe()).operator -(this->getIm().operator *(aux->getIm())));
    mult->setIm(this->getIm().operator *(aux->getRe()).operator +(this->getRe().operator *(aux->getIm())));
    if(mult->getIm().getNum() !=0)
        mult->setType(complexe);
    else
    {
        if(mult->getIm().getNum() ==0) {
        if(mult->getRe().getDen()==1)
            mult->setType(entier);
        else
            mult->setType(rationnel);
        }
    }
    if(this->getType()==reel || l->getType()==reel) {
        Rational temp (mult->getRe().getNum()/mult->getRe().getDen(),1);
        mult->setRe(temp);
    }
    return mult;
    /**
     * \brief    Produit
     * \details  Surcharge de l'opérateur * pour multiplier un Complex avec une Literal
     * \param    l La Literal à multiplier au Complex
     * \return   Le résultat du produit qui est une Literal
     */
}

Literal* Complex::operator/(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex *div = new Complex(0,1,0,1,this->getType());
    Rational a = this->getRe();
    Rational b = this->getIm();
    Rational c = aux->getRe();
    Rational d = aux->getIm();
    div->setRe((a*c+b*d)/(c*c+d*d));
    div->setIm(((a*d-b*c)/(c*c+d*d)).neg());
    if(div->getIm().getNum() !=0)
        div->setType(complexe);
    else
    {
        if(div->getIm().getNum() ==0) {
        if(div->getRe().getDen()==1)
            div->setType(entier);
        else
            div->setType(rationnel);
        }
    }
    if(this->getType()==reel || l->getType()==reel) {
        Rational temp (div->getRe().getNum()/div->getRe().getDen(),1);
        div->setRe(temp);
    }
    return div;
    /**
     * \brief    Division
     * \details  Surcharge de l'opérateur / pour diviser un Complex par une Literal
     * \param    l La Literal à diviser au Complex
     * \return   Le résultat de la division qui est une Literal
     */
}


Literal* Complex::neg()
{
    Complex *c = new Complex(0,1,0,1,this->getType());
    Rational r = this->getRe();
    Rational i = this->getIm();
    c->setRe(r.neg());
    c->setIm(i.neg());
    return c;
    /**
     * \brief    Négatif
     * \details  Fonction opposé du Complex
     * \return   L'opposé du Complex qui est une Literal
     */
}

Literal* Complex::dollar(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    if(this->getType()==complexe || l->getType()==complexe)
        throw ErrorHandler("Opération non applicable sur un complexe");
    Complex *c = new Complex(this->getRe(),aux->getRe(),complexe);
    return c;
    /**
     * \brief    Dollar
     * \details  Permet de former un complexe avec deux Littérales (sauf complexes)
     * \param    l La Literal qui formera la partie imaginaire
     * \return   La nouvelle Littérale complexe créée
     */
}

Literal* Complex::num()
{
    if(this->getType()==complexe)
        throw ErrorHandler("Opération non applicable sur un complexe");
    if(this->getType()==reel)
        throw ErrorHandler("Opération non applicable sur un reel");
    Complex *c = new Complex(this->getRe().getNum(),1,0,1,entier);
    return c;
    /**
     * \brief    Fonction Num
     * \return   Le numérateur de la Littérale
     */
}

Literal* Complex::den()
{
    if(this->getType()==complexe)
        throw ErrorHandler("Opération non applicable sur un complexe");
    if(this->getType()==reel)
        throw ErrorHandler("Opération non applicable sur un reel");
    Complex *c = new Complex(this->getRe().getDen(),1,0,1,entier);
    return c;
    /**
     * \brief    Fonction Den
     * \return   Le dénominateur de la Littérale
     */
}

Literal* Complex::re()
{
    if(this->getType()==complexe)
    {
        Rational temp (0,1);
        Complex *c = new Complex(this->getRe(),temp,entier);
        if(c->getRe().getDen()!=1)
            c->setType(rationnel);
        if(c->getRe().getNum()!=floor(c->getRe().getNum()))
            c->setType(reel);
        return c;
    }
    else
        return this;
    /**
     * \brief    Fonction Re
     * \return   La partie réelle de la Littérale
     */
}

Literal* Complex::im()
{
    if(this->getType()==complexe)
    {
        Rational temp (0,1);
        Complex *c = new Complex(this->getIm(),temp,entier);
        if(c->getRe().getDen()!=1)
            c->setType(rationnel);
        if(c->getRe().getNum()!=floor(c->getRe().getNum()))
            c->setType(reel);
        return c;
    }
    else
    {
        Complex *c = new Complex(0,1,0,1,entier);
        return c;
    }
    /**
     * \brief    Fonction Im
     * \return   La partie imaginaire de la Littérale
     */
}

Literal* Complex::mod(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    if(this->getType()==entier && aux->getType()==entier)
    {
        int temp1 = int(this->getRe().getNum());
        int temp2 = int(aux->getRe().getNum());
        Complex *c = new Complex(temp1%temp2,1,0,1,entier);
        return c;
    }
    else
        throw ErrorHandler("Opération applicable uniquement sur deux entiers");
    /**
     * \brief    Modulo
     * \param    l La Literal à moduler
     * \return   La Literal résultante
     */
}

Literal* Complex::div(const Literal* l)
{
    const Complex *aux = (const Complex*)l;
    if(this->getType()==entier && aux->getType()==entier)
    {
        int temp1 = int(this->getRe().getNum());
        int temp2 = int(aux->getRe().getNum());
        if((temp2)==0)
            throw ErrorHandler("Erreur : division par 0 impossible");
        Complex *c = new Complex(temp1/temp2,1,0,1,entier);
        return c;
    }
    else
        throw ErrorHandler("Opération applicable uniquement sur deux entiers");
    /**
     * \brief    Division entière
     * \param    l La Literal à diviser
     * \return   La Literal résultante
     */
}

Literal* Complex::operator==(Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex* vrai = new Complex(1,1,0,1,entier);
    Complex* faux = new Complex(0,1,0,1,entier);
    if((this->getRe()==aux->getRe()) &&(this->getIm()==aux->getIm()))
        return vrai;
    else
        return faux;
    /**
     * \brief    Comparateur égal
     * \param    l La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Complex::operator<(Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex* vrai = new Complex(1,1,0,1,entier);
    Complex* faux = new Complex(0,1,0,1,entier);
    if((this->getRe()<aux->getRe()))
        return vrai;
    else
    {
        if((this->getRe()==aux->getRe()) && (this->getIm()<aux->getIm()))
            return vrai;
        else
            return faux;
    }
    /**
     * \brief    Comparateur inférieur strict
     * \param    l La Literal à comparer
     * \return   Un bool, true si la comparaison est vérifiée, false sinon
     */
}

Literal* Complex::operator<=(Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex* vrai = new Complex(1,1,0,1,entier);
    Complex* faux = new Complex(0,1,0,1,entier);
    if((this->getRe()<=aux->getRe()))
        return vrai;
    else
    {
        if((this->getRe()==aux->getRe()) && (this->getIm()<=aux->getIm()))
            return vrai;
        else
            return faux;
    }
    /**
     * \brief    Comparateur inférieur ou égal
     * \param    l La Literal à comparer
     * \return   Un bool, true si la comparaison est vérifiée, false sinon
     */
}

Literal* Complex::operator!=(Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex* vrai = new Complex(1,1,0,1,entier);
    Complex* faux = new Complex(0,1,0,1,entier);
    if((this->getRe()==aux->getRe()) &&(this->getIm()==aux->getIm()))
        return faux;
    else
        return vrai;
    /**
     * \brief    Comparateur différent
     * \param    l La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Complex::operator>(Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex* vrai = new Complex(1,1,0,1,entier);
    Complex* faux = new Complex(0,1,0,1,entier);
    if((this->getRe()<=aux->getRe()))
        return faux;
    else
    {
        if((this->getRe()==aux->getRe()) && (this->getIm()<=aux->getIm()))
            return faux;
        else
            return vrai;
    }
    /**
     * \brief    Comparateur supérieur strict
     * \param    l La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Complex::operator>=(Literal* l)
{
    const Complex *aux = (const Complex*)l;
    Complex* vrai = new Complex(1,1,0,1,entier);
    Complex* faux = new Complex(0,1,0,1,entier);
    if((this->getRe()<aux->getRe()))
        return faux;
    else
    {
        if((this->getRe()==aux->getRe()) && (this->getIm()<aux->getIm()))
            return faux;
        else
            return vrai;
    }
    /**
     * \brief    Comparateur supérieur ou égal
     * \param    l La Literal à comparer
     * \return   La Literal résultant de la comparaison
     */
}

Literal* Complex::oAnd(Literal* c)
{
    Complex *aux = (Complex*)c;
    Complex* faux = new Complex(0,1,0,1,entier);
    Complex* vrai = new Complex(1,1,0,1,entier);
    if(this->compToBool(faux) || aux->compToBool(faux))
        return faux;
    else
        return vrai;
    /**
     * \brief    Comparateur and
     * \param    c La Literal à comparer
     * \return   La littérale résultant du et logique
     */
}

Literal* Complex::oOr(Literal* c)
{
    Complex *aux = (Complex*)c;
    Complex* faux = new Complex(0,1,0,1,entier);
    Complex* vrai = new Complex(1,1,0,1,entier);
    if(this->compToBool(faux) && aux->compToBool(faux))
        return faux;
    else
        return vrai;
    /**
     * \brief    Comparateur or
     * \param    c La Literal à comparer
     * \return   La littérale résultant du ou logique
     */
}

Literal* Complex::oNot()
{
    Complex* faux = new Complex(0,1,0,1,entier);
    Complex* vrai = new Complex(1,1,0,1,entier);
    if(this->compToBool(faux))
        return vrai;
    else
        return faux;
    /**
     * \brief    Comparateur not
     * \return   La littérale résultant du non logique
     */
}

bool Complex::compToBool(Complex* l)
{
    if((this->getRe()==l->getRe()) &&(this->getIm()==l->getIm()))
        return 1;
    else
        return 0;
    /**
     * \brief    Tranformation en bool
     * \details  Permet de récupérer un bool pour les tests logiques
     * \param    c Le Complex à comparer
     * \return   Un bool, 1 si ils sont égaux, 0 sinon
     */
}

QString Complex::toString()const
{
    QString t;
    t+=(pRe.toString());
    if(getType()==complexe)
        t +=" + "+pIm.toString()+"i";
    return t;

    /**
     * \brief     Transforme le Complex en chaine de caractères
     * \return    Le Complex sous la forme d'un QString : pRe+pImi
     */
}

QString Complex::getValue() const
{
    QString t;
    t+=(pRe.getValue());
    if(getType()==complexe)
        t+="$"+pIm.getValue();
    return t;
    /**
     * \brief    Transforme le Complex en chaine de caractère
     * \return   Le Complex noté pRe$pIm sous la forme d'un QString : RE$IM
     */
}
