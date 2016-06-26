#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QString>
#include <QSettings>
#include <QQueue>
#include "complex.h"
#include "stack.h"
#include "expression.h"
#include "preferencesmanager.h"
#ifdef Q_OS_WIN
#define EXPRESSION_ID "class Expression"
#define COMPLEX_ID "class Complex"
#else
#define EXPRESSION_ID "10Expression"
#define COMPLEX_ID "7Complex"
#endif

class PreferencesManager;
class Calculator
{

public:
    Calculator(PreferencesManager* ,QSettings*,QSettings*);
    unsigned int getNbShow();
    void setNbShow(unsigned int a);
    bool getBeep();
    void setBeep(bool b);
    bool getKeyboard();
    void setKeyboard(bool b);
    void push(Literal * l);
    Literal* pop();
    int stackNbElem();
    QStack<Literal*>* getStack();
    Literal* plus();
    Literal* moins();
    Literal* fois();
    Literal* divise();
    Literal* nega();
    Literal* num();
    Literal* den();
    Literal* re();
    Literal* im();
    Literal* dollar();
    Literal* mod();
    Literal* div();
    void sto();
    void forget();
    void swap();
    void dup();
    void drop();
    void undo();
    void redo();
    void loaded();
    Literal* opEgal();
    Literal* opInfStrict();
    Literal* opInfEgal();
    Literal* opDiff();
    Literal* opSupStrict();
    Literal* opSupEgal();
    void opAnd();
    void opOr();
    void opNot();
    Literal* lastOP();
    void lastARG();
    virtual ~Calculator();

private:
    QStack<Literal*> *pile;
    QStack<Literal*> *pilePrev;
    QStack<Literal*> *pileNext;
    PreferencesManager* prefMan;
    QSettings * satom;
    QSettings * sprog;
    bool bloaded;
    bool bundo;
    QString lastop;
    QQueue<Literal*> lastarg;
};
#endif // CALCULATOR_H
