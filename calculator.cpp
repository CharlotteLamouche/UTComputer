///
/// \class     Calculator
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Gestion de la calculatrice
///
/// \details   Cette classe permet de gérer le fonctionnement de la calculatrice ainsi que ses options d'affichage et de calcul.
///

#include "calculator.h"
#include <iostream>

Calculator::Calculator(PreferencesManager* pm,QSettings * satom,QSettings * sprog):prefMan(pm),satom(satom),sprog(sprog)
{
    pile = Stack::getInstance();
    pilePrev = new QStack<Literal*>;
    pileNext = new QStack<Literal*>;
    bloaded = false;
    bundo = false;
    ErrorHandler::sound = getBeep();
    lastop = "";
    /**
     * \brief    Constructeur
     * \details  Permet de construire un objet de type Calculator
     * \param    pm Un objet de PreferencesManager afin de récupérer les paramètres de la dernière utilisation
     */
}

void Calculator::loaded()
{
    bloaded = true;
    /**
     * \brief    Change la valeur de bloaded à true
     */
}

Calculator::~Calculator()
{
    delete pilePrev;
    delete pileNext;
    Stack::freeInstance();
    /**
     * \brief    Destructeur
     */
}

unsigned int Calculator::getNbShow()
{
    return prefMan->value("nb_show",4).toInt();
    /**
    * \brief    Obtenir le nombre d'éléments à montrer choisit par l'utilisateur
    * \return   Le nombre d'éléments à montrer
    */
}

void Calculator::setNbShow(unsigned int a)
{
    prefMan->setValue("nb_show",a);
    /**
     * \brief    Modifier le nombre d'éléments à montrer dans la pile
     * \param    a Un entier qui remplace l'ancienne valeur
     */
}

bool Calculator::getBeep()
{
    return prefMan->value("beep",true).toBool();
    /**
    * \brief    Savoir si le signal sonore est activé ou non
    * \return   Un bool
    */
}

void Calculator::setBeep(bool b)
{
    prefMan->setValue("beep",b);
    /**
     * \brief    Modifie l'état du signal sonore
     * \param    b Un bool qui remplace l'ancienne valeur
     */
}

bool Calculator::getKeyboard()
{
    return prefMan->value("keyboard",true).toBool();
    /**
    * \brief    Savoir si le clavier est affiché ou non
    * \return   Un bool
    */
}

void Calculator::setKeyboard(bool b)
{
    prefMan->setValue("keyboard", b);
    /**
    * \brief    Modifie l'état du clavier
    * \return   Un bool b qui remplace l'ancienne valeur
    */
}


void Calculator::undo()
{
    if(bloaded)
    {
        *pileNext = *pile;
        *pile = *pilePrev;
        bundo = true;
    }
    /**
    * \brief    Interaction avec le bouton Undo
    * \details  Rétabli l'état du calculateur avant la dernière opération
    */
}

void Calculator::redo()
{
    if(bundo)
    {
        *pile = *pileNext;
        bundo = false;
    }
    else
        throw ErrorHandler("Pas d'action à rétablir");
    /**
    * \brief    Interaction avec le bouton Redo
    * \details  Annule la dernière opération Undo
    */
}

void Calculator::push(Literal * l)
{
   *pilePrev = *pile;
   pile->push(l);
   /**
   * \brief    Met la littérale dans la pile
   * \param    l La Littérale à entrer
   */
}

int Calculator::stackNbElem()
{
    return pile->size();
    /**
     * \brief    Obtenir le nombre d'éléments dans la pile
     * \return   Un entier correspondant au nombre d'éléments
     */
}

QStack<Literal*>* Calculator::getStack()
{
    return pile;
    /**
     * \brief    Obtenir la pile
     * \return   Une QStack de Literal (une pile de littérales)
     */
}

Literal* Calculator::pop()
{
    if(pile->isEmpty())
        throw(ErrorHandler("Erreur pas assez d'éléments dans la pile"));
    else
        return(pile->pop());
    /**
     * \brief    Dépile le dernier élément
     * \return   La Littérale dépilée
     */
}

Literal* Calculator::plus()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "plus";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator +(l1);
    }
    /**
     * \brief     Fonction d'addition de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::moins()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "moins";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator -(l1);
    }
    /**
     * \brief     Fonction de soustraction de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::fois()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "fois";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator *(l1);
    }
    /**
     * \brief     Fonction de multiplication de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::divise()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "divise";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         try
         {
            return l2->operator /(l1);
         }
         catch (ErrorHandler& e)
         {
             e.alertUser();
             pile->push(l2);
             pile->push(l1);
             return nullptr;
         }
    }
    /**
     * \brief     Fonction de division de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::nega()
{
    if(this->stackNbElem() < 1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         lastop = "nega";
         lastarg.enqueue(l1);
         return l1->neg();
    }
    /**
     * \brief     Fonction d'opposé de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::num()
{
    if(this->stackNbElem() < 1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         lastop = "num";
         lastarg.enqueue(l1);
         try
         {
            return l1->num();
         }
         catch (ErrorHandler& e)
         {
             e.alertUser();
             pile->push(l1);
             return nullptr;
         }
    }
    /**
     * \brief     Fonction num de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::den()
{
    if(this->stackNbElem() < 1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         lastop = "den";
         lastarg.enqueue(l1);
         try
         {
            return l1->den();
         }
         catch (ErrorHandler& e)
         {
             e.alertUser();
             pile->push(l1);
             return nullptr;
         }
    }
    /**
     * \brief     Fonction den de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::re()
{
    if(this->stackNbElem() < 1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         lastop = "re";
         lastarg.enqueue(l1);
         return l1->re();
    }
    /**
     * \brief     Fonction re de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::im()
{
    if(this->stackNbElem() < 1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         lastop = "im";
         lastarg.enqueue(l1);
         return l1->im();
    }
    /**
     * \brief     Fonction im de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::dollar()
{
    if(this->getStack()->size() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "dollar";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         try
         {
            return l2->dollar(l1);
         }
         catch (ErrorHandler& e)
         {
             e.alertUser();
             pile->push(l2);
             pile->push(l1);
             return nullptr;
         }
    }
    /**
     * \brief     Fonction dollar de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::mod()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "mod";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         try
         {
            return l2->mod(l1);
         }
         catch (ErrorHandler& e)
         {
             e.alertUser();
             pile->push(l2);
             pile->push(l1);
             return nullptr;
         }
    }
    /**
     * \brief     Fonction mod de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::div()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "div";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         try
         {
            return l2->div(l1);
         }
         catch (ErrorHandler& e)
         {
             e.alertUser();
             pile->push(l2);
             pile->push(l1);
             return nullptr;
         }
    }
    /**
     * \brief     Fonction div de la calculatrice
     * \return    La Littérale résultante
     */
}

void Calculator::swap()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
        Literal* l1 = pile->pop();
        Literal* l2 = pile->pop();
        pile->push(l1);
        pile->push(l2);
        lastarg.enqueue(l2);
        lastarg.enqueue(l1);
        lastop = "swap";
    }
    /**
     * \brief     Fonction swap de la calculatrice
     * \details   Echange les deux dernières Littérales empilées
     */
}

void Calculator::sto()
{
    if(this->getStack()->size()<2)
        throw ErrorHandler("Erreur nombre d'arguments insuffisants");
    Literal * l1 = pile->pop();
    Literal * l2 = pile->pop();
    Expression *e = (Expression*)l2;
    lastop = "sto";
    lastarg.enqueue(l2);
    lastarg.enqueue(l1);
    if(QString(typeid(*l2).name())==EXPRESSION_ID && e->getValue().at(0)=='[')
        prefMan->setProgValue(l1->getValue(),l2->getValue(),true);
    else
        prefMan->setAtomValue(l1->getValue(),l2->getValue(),true);
    /**
     * \brief     Fonction sto de la calculatrice
     * \details   Associe un atome ou un programme à un contenu
     */

}

void Calculator::forget()
{
    if(this->getStack()->size()<1)
        throw ErrorHandler("Erreur nombre d'arguments insuffisants");
    Literal * l1 = pile->pop();
    Expression *e = (Expression*)l1;
    lastop = "forget";
    lastarg.enqueue(l1);
    if(QString(typeid(*l1).name())==EXPRESSION_ID && e->getTypeExp()==program)
        prefMan->removeProgValue(l1->toString(),*sprog);
    else
        prefMan->removeAtomValue(l1->getValue(),*satom);
    /**
     * \brief     Fonction forget de la calculatrice
     * \details   Supprime un atome ou un programme
     */
}

Literal* Calculator::opEgal()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "opEgal";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator ==(l1);
    }
    /**
     * \brief     Fonction d'égalité de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::opDiff()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "opDiff";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator !=(l1);
    }
    /**
     * \brief     Fonction de différence de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::opInfStrict()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "opInfStrict";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator <(l1);
    }
    /**
     * \brief     Fonction inférieur strict de la calculatrice
     * \return    La Littérale résultante
     */
}

void Calculator::dup()
{
    try
    {
        if(this->getStack()->isEmpty())
            throw ErrorHandler("Erreur la pile est vide");
        else
        {
            Literal* l = this->pop();
            lastarg.enqueue(l);
            lastop = "dup";
            this->push(l);
            this->push(l);
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief     Fonction dup de la calculatrice
     * \details   Duplique la dernière littérale empilée
     */
}
void Calculator::drop()
{
    try
    {
        if (this->getStack()->size()<1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
        Literal* l = this->pop();
        lastarg.enqueue(l);
        lastop = "drop";
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief     Fonction drop de la calculatrice
     * \details   Dépile la dernière littéral empilée
     */
}
Literal* Calculator::opSupEgal()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "opSupEgal";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator >=(l1);
    }
    /**
     * \brief     Fonction supérieur ou égal de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::opInfEgal()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "opInfEgal";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator <=(l1);
    }
    /**
     * \brief     Fonction inférieur ou égal de la calculatrice
     * \return    La Littérale résultante
     */
}

Literal* Calculator::opSupStrict()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         if(QString(typeid(*l2).name())==COMPLEX_ID && QString(typeid(*l1).name())==EXPRESSION_ID)
             l2 = new Expression("'"+l2->getValue()+"'",expression);
         lastop = "opSupStrict";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         return l2->operator >(l1);
    }
    /**
     * \brief     Fonction superieur strict de la calculatrice
     * \return    La Littérale résultante
     */
}

void Calculator::opAnd()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
         Literal * l1 = pile->pop();
         Literal * l2 = pile->pop();
         lastop = "opAnd";
         lastarg.enqueue(l2);
         lastarg.enqueue(l1);
         pile->push(l2->oAnd(l1));
    }
    /**
     * \brief     Fonction and
     * \details   Push 1 si la comparaison est vérifiée, 0 sinon
     */
}

void Calculator::opOr()
{
    if(this->stackNbElem() < 2)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
        Literal * l1 = pile->pop();
        Literal * l2 = pile->pop();
        lastop = "opOr";
        lastarg.enqueue(l2);
        lastarg.enqueue(l1);
        pile->push(l2->oOr(l1));
    }
    /**
     * \brief     Fonction or
     * \details   Push 1 si la comparaison est vérifiée, 0 sinon
     */
}

void Calculator::opNot()
{
    if(this->stackNbElem() < 1)
            throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
    else
    {
        Literal * l = pile->pop();
        lastop = "opNot";
        lastarg.enqueue(l);
        pile->push(l->oNot());
    }
    /**
     * \brief     Fonction not
     * \details   Push 1 si la littérale est fausse, 0 si elle est vraie
     */
}

Literal* Calculator::lastOP()
{
    if(lastop == "")
        throw ErrorHandler("Erreur pas de dernier operateur");
    else if(lastop == "plus")
        return this->plus();
    else if(lastop == "moins")
        return this->moins();
    else if(lastop == "fois")
        return this->fois();
    else if(lastop == "divise")
        return this->divise();
    else if(lastop == "nega")
        return this->nega();
    else if(lastop == "num")
        return this->num();
    else if(lastop == "den")
        return this->den();
    else if(lastop == "re")
        return this->re();
    else if(lastop == "im")
        return this->im();
    else if(lastop == "dollar")
        return this->dollar();
    else if(lastop == "mod")
        return this->mod();
    else if(lastop == "div")
        return this->div();
    else if(lastop == "sto")
        this->sto();
    else if(lastop == "forget")
        this->forget();
    else if(lastop == "swap")
        this->swap();
    else if(lastop == "undo")
        this->undo();
    else if(lastop == "redo")
        this->redo();
    else if(lastop == "opEgal")
        return this->opEgal();
    else if(lastop == "opInfStrict")
        return this->opInfStrict();
    else if(lastop == "opInfEgal")
        return this->opInfEgal();
    else if(lastop == "opDiff")
        return this->opDiff();
    else if(lastop == "opSupStrict")
        return this->opSupStrict();
    else if(lastop == "opSupEgal")
        return this->opSupEgal();
    else if(lastop == "opAnd")
        this->opAnd();
    else if(lastop == "opOr")
        this->opOr();
    else if(lastop == "opNot")
        this->opNot();
    else if(lastop == "lastArg")
        this->lastARG();
    else if(lastop == "dup")
        this->dup();
    else if(lastop == "drop")
        this->drop();
    return nullptr;

    /**
     * \brief     Fonction lastop de la calculatrice
     * \details   Applique le dernier opérateur utilisé
     */
}

void Calculator::lastARG()
{
    if(lastarg.isEmpty())
        throw ErrorHandler("Erreur pas de derniers arguments");
    else if(lastop == "plus" || lastop == "moins" || lastop == "divise" || lastop == "fois" || lastop == "dollar" || lastop == "mod" || lastop == "div" || lastop == "sto" || lastop == "swap" || lastop == "opInfStrict" || lastop == "opSupStrict" || lastop == "opInfEgal" || lastop == "opSupEgal" || lastop == "opDiff" || lastop == "opEgal" || lastop == "opAnd" || lastop == "opOr" || lastop == "opNot")
    {
        this->push(lastarg.dequeue());
        this->push(lastarg.dequeue());
    }

    else if(lastop == "nega" || lastop == "num" || lastop == "den" || lastop == "re" || lastop == "im" || lastop == "forget" || lastop == "div" || lastop == "dup" || lastop == "drop")
    {
        this->push(lastarg.dequeue());
    }
    /**
     * \brief     Fonction lastargs de la calculatrice
     * \details   Empile les littérales utilisées pour la dernière opération
     */
}

