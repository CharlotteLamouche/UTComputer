///
/// \class     Rational
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Gestion des nombres rationnels
///
/// \details   Cette classe permet de gérer la manipulation des nombres rationnels.
///

#include "rational.h"
#include <math.h>



Rational::Rational(double n,double d):num(n),den(d)
{
    /**
     * \brief    Constructeur
     * \details  Crée un objet de type Rational
     * \param    n Un double correspondant au numérateur du Rational
     * \param    d Un double correspondant au dénominateur du Rational
     */
}

double Rational::getNum()const
{
    return num;
    /**
    * \brief    Obtenir le numérateur
    * \return   Le numérateur du Rational
    */
}

double Rational::getDen()const
{
    return den;
    /**
    * \brief    Obtenir le dénominateur
    * \return   Le dénominateur du Rational
    */
}

int Rational::getType()const
{
    if(den==1)
        return 0;
    else
        return 1;
    /**
     * \brief    Connaître le type
     * \return   Un bool, 0 si c'est un entier, 1 si c'est un rationnel
     */
}

void Rational::setNum(double d)
{
    num = d;
    /**
     * \brief    Modifier le numérateur
     * \param    d Un double qui remplace l'ancien numérateur
     */
}

void Rational::setDen(double d)
{
    den = d;
    /**
     * \brief    Modifier le dénominateur
     * \param    d Un double qui remplace l'ancien dénominateur
     */
}

Rational Rational::operator+(const Rational& c)const
{
    double nA = getNum();
    double nB = c.getNum();
    double dA = getDen();
    double dB = c.getDen();
    Rational r(nA*dB+nB*dA,dA*dB);
    if (r.getType() == 1)
        r.simplify();
    return r;
    /**
     * \brief    Somme
     * \details  Surcharge de l'opérateur + pour sommer deux Rational
     * \param    c Le Rational à sommer
     * \return   Le résultat de la somme qui est un Rational
     */
}

Rational Rational::operator-(const Rational& c)const
{
    double nA = getNum();
    double nB = c.getNum();
    double dA = getDen();
    double dB = c.getDen();
    Rational r(nA*dB-nB*dA,dA*dB);
    if (r.getType() == 1)
        r.simplify();
    return r;
    /**
    * \brief    Différence
    * \details  Surcharge de l'opérateur - pout soustraire deux Rational
    * \param    c Le Rational à soustraire
    * \return   Le résultat de la différence qui est un Rational
    */
}
Rational Rational::operator*(const Rational& c)const
{
    double nA = getNum();
    double nB = c.getNum();
    double dA = getDen();
    double dB = c.getDen();
    Rational r(nA*nB,dA*dB);
    if (r.getType() == 1)
        r.simplify();
    return r;
    /**
    * \brief    Produit
    * \details  Surcharge de l'opérateur * pour multiplier deux Rational
    * \param    c Le Rational à multiplier
    * \return   Le résultat du produit qui est un Rational
    */
}

Rational Rational::operator/(const Rational& c)const
{
    double nA = getNum();
    double nB = c.getNum();
    if(nB==0)
        throw ErrorHandler("Erreur : Division par 0");
    double dA = getDen();
    double dB = c.getDen();
    Rational r(nA*dB,dA*nB);
    if (r.getType() == 1)
        r.simplify();
    return r;
    /**
    * \brief    Division
    * \details  Surcharge de l'opérateur / pour diviser deux Rational
    * \param    c Le Rational à diviser
    * \return   Le résultat de la division qui est un Rational
    */
}

Rational Rational::div(const Rational& c)const
{
    if(getType()!=0)
        throw "erreur s'applique uniquement sur entier";
    if(c.getType()!=0)
        throw "erreur s'applique uniquement sur entier";
    int nA = (int)(getNum());
    int nB = (int)(c.getNum());
    if(nB==0)
        throw ErrorHandler("Erreur : Division par 0");
    Rational r(nA/nB,1);
    if (r.getType() == 1)
        r.simplify();
    return r;
    /**
     * \brief    Division entière
     * \details  Division entière entre deux Rational
     * \param    c Le Rational à diviser
     * \return   Le résultat de la division entière qui est un Rational
     */
}

Rational Rational::mod(const Rational& c)const
{
    if(getType()!=0)
        throw "erreur s'applique uniquement sur entier";
    if(c.getType()!=0)
        throw "erreur s'applique uniquement sur entier";
    int nA = (int)(getNum());
    int nB = (int)(c.getNum());
    Rational r(nA%nB,1);
    if (r.getType() == 1)
        r.simplify();
    return r;
    /**
     * \brief    Modulo
     * \details  Reste de la division entière entre deux Rational
     * \param    c Le Rational à diviser
     * \return   Le reste de la division entière (modulo) qui est un Rational
     */
}

Rational Rational::neg() const
{
    return Rational(-num,den);
    /**
     * \brief    Négatif
     * \details  Fonction opposé du Rational
     * \return   L'opposé du Rational qui est un Rational
     */
}

Rational Rational::Im()const
{
    Rational res(0,1);
    return res;
    /**
     * \brief    Partie Imaginaire
     * \details  Fonction Im du Rational
     * \return   La partie imaginaire du Rational, donc 0
     */
}

Rational Rational::Re()const
{
    return (*this);
    /**
     * \brief    Partie Réelle
     * \details  Fonction Re du Rational
     * \return   La partie réelle du Rational, donc lui même
     */
}

bool Rational::operator==(const Rational& c)const
{
    if(getNum()==c.getNum() && getDen()==c.getDen())
        return 1;
    else
        return 0;
    /**
     * \brief    Comparaison
     * \details  Surcharge de l'opérateur == pour comparer deux Rational
     * \param    c Le Rational à comparer
     * \return   Un bool, 1 si les deux Rational sont égaux, 0 sinon
     */
}

bool Rational::operator<=(const Rational& c)const
{
    if(getNum()/getDen()<=c.getNum()/c.getDen())
        return 1;
    else
        return 0;
    /**
     * \brief    Comparaison
     * \details  Surcharge de l'opérateur <= pour comparer deux Rational
     * \param    c Le Rational à comparer
     * \return   Un bool, 1 si le Rational est inférieur ou égal au Rational passé en paramètre, 0 sinon
     */
}

bool Rational::operator<(const Rational& c)const
{
    if(getNum()/getDen()<c.getNum()/c.getDen())
        return 1;
    else
        return 0;
    /**
     * \brief    Comparaison
     * \details  Surcharge de l'opérateur < pour comparer deux Rational
     * \param    c Le Rational à comparer
     * \return   Un bool, 1 si le Rational est strictement inférieur au Rational passé en paramètre, 0 sinon
     */
}


int Rational::pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
    /**
     * \brief    PGCD de deux entiers
     * \param    a Un entier
     * \param    b Un entier
     * \return   Le PGCD des deux paramètres qui est un entier
     */
}

void Rational::simplify()
{
    double a,b;
    a = getNum();
    b = getDen();
    while(floor(a)!= a|| floor(b)!=b)
    {
        a*=10;
        b*=10;
    }
    int num = (int) a;
    int den = (int) b;
    int div=pgcd(num, den);
    if( div > 0){
        num/=div;
        den/=div;
        if ((num>0 && den<0) || (num<0 && den<0))
        {
            num*=-1;
            den*=-1;
        }
        Rational::num=num;
        Rational::den=den;
    }
    /**
     * \brief    Simplification d'une fraction
     */
}

QString Rational::toString() const
{
    QString t;
    t+=(QString::number(num));
    if (getType()==1 && den!=1)
        t+= " / " + QString::number(den);
    return t;
    /**
     * \brief     Transforme le Rational en chaine de caractères
     * \return    Le Rational sous la forme d'un QString (affiché dans la pile)
     */
}

QString Rational::getValue() const
{
    QString t;
    t+=(QString::number(num));
    if (getType()==1)
        t+= "/" + QString::number(den);
    return t;
    /**
     * \brief     Transforme le Rational en chaine de caractères
     * \return    Le Rational sous la forme d'un QString (rentré dans la calculatrice par l'utilisateur)
     */
}

