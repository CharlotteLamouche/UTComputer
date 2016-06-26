///
/// \class     MainWindow
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface graphique utilisateur
///
/// \details   Cette classe permet de gérer les interactions de l'utilisateur avec l'interface graphique.
///
#include "mainwindow.h"
#include <iostream>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    prefMan = PreferencesManager::getInstance();
    settings = new QSettings(PARAMETERS_FILE,QSettings::IniFormat);
    sstack = new QSettings(STACK_FILE,QSettings::IniFormat);
    satom = new QSettings(ATOM_FILE,QSettings::IniFormat);
    sprog = new QSettings(PROG_FILE,QSettings::IniFormat);
    prefMan->readSettings(*settings);
    prefMan->readAtom(*satom);
    prefMan->readProg(*sprog);
    Calc = new Calculator(prefMan,satom,sprog);
    ui->setupUi(this);
    ui->expression->setFocus();
    this->setMaximumHeight(579);
    this->setMinimumHeight(579);
    this->setMaximumWidth(570);
    this->setMinimumWidth(570);
    prefMan->loadStack(this,*sstack);
    if(Calc->getKeyboard())
    {
        ui->actionKeyboard->setChecked(true);
        on_actionKeyboard_triggered();
    }
    else
    {
        ui->actionKeyboard->setChecked(false);
        on_actionKeyboard_triggered();
    }
    Calc->loaded();
    /**
     * \brief    Constructeur
     * \details  Permet de construire la fenêtre principale de la calculatrice
     * \param    parent Le QWidget parent
     */
}

MainWindow::~MainWindow()
{
    prefMan->writeSettings(*settings);
    prefMan->saveStack(Calc,*sstack);
    prefMan->writeAtom(*satom);
    prefMan->writeProg(*sprog);
    prefMan->freeInstance();
    delete settings;
    delete ui;
    delete Calc;
    /**
     * \brief    Destructeur
     */
}

void MainWindow::on_b0_clicked()
{
    ui->expression->setText(ui->expression->text() + "0");
    /**
    * \brief    Interaction avec le bouton 0
    * \details  Ajoute 0 dans la zone de saisie
    */
}

void MainWindow::on_b1_clicked()
{
    ui->expression->setText(ui->expression->text() + "1");
    /**
    * \brief    Interaction avec le bouton 1
    * \details  Ajoute 1 dans la zone de saisie
    */
}

void MainWindow::on_b2_clicked()
{
    ui->expression->setText(ui->expression->text() + "2");
    /**
    * \brief    Interaction avec le bouton 2
    * \details  Ajoute 2 dans la zone de saisie
    */
}

void MainWindow::on_b3_clicked()
{
    ui->expression->setText(ui->expression->text() + "3");
    /**
    * \brief    Interaction avec le bouton 3
    * \details  Ajoute 3 dans la zone de saisie
    */
}

void MainWindow::on_b4_clicked()
{
    ui->expression->setText(ui->expression->text() + "4");
    /**
    * \brief    Interaction avec le bouton 4
    * \details  Ajoute 4 dans la zone de saisie
    */
}

void MainWindow::on_b5_clicked()
{
    ui->expression->setText(ui->expression->text() + "5");
    /**
    * \brief    Interaction avec le bouton 5
    * \details  Ajoute 5 dans la zone de saisie
    */
}

void MainWindow::on_b6_clicked()
{
    ui->expression->setText(ui->expression->text() + "6");
    /**
    * \brief    Interaction avec le bouton 6
    * \details  Ajoute 6 dans la zone de saisie
    */
}

void MainWindow::on_b7_clicked()
{
    ui->expression->setText(ui->expression->text() + "7");
    /**
    * \brief    Interaction avec le bouton 7
    * \details  Ajoute 7 dans la zone de saisie
    */
}

void MainWindow::on_b8_clicked()
{
    ui->expression->setText(ui->expression->text() + "8");
    /**
    * \brief    Interaction avec le bouton 8
    * \details  Ajoute 8 dans la zone de saisie
    */
}

void MainWindow::on_b9_clicked()
{
    ui->expression->setText(ui->expression->text() + "9");
    /**
    * \brief    Interaction avec le bouton 9
    * \details  Ajoute 9 dans la zone de saisie
    */
}

void MainWindow::on_bPlus_clicked()
{
    try
    {
        Literal *toPush = Calc->plus();
        Calc->push(toPush);
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton +
     * \details  Applique l'opération +
     */
}

void MainWindow::on_bMoins_clicked()
{
    try
    {
        Literal *toPush = Calc->moins();
        Calc->push(toPush);
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton -
     * \details  Applique l'opération -
     */
}

void MainWindow::on_bFois_clicked()
{
    try
    {
        Literal *toPush = Calc->fois();
        Calc->push(toPush);
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton *
     * \details  Applique l'opération *
     */
}

void MainWindow::on_bDivision_clicked()
{
    try
    {
        Literal *toPush = Calc->divise();
        if(toPush==nullptr)
        {}
        else
        {
            Calc->push(toPush);
            showStack();
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton /
     * \details  Applique l'opération /
     */
}

void MainWindow::on_bNeg_clicked()
{
    try
    {
        Literal *toPush = Calc->nega();
        Calc->push(toPush);
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton NEG
     * \details  Applique l'opération NEG
     */
}

void MainWindow::on_bGuillemet_clicked()
{
    ui->expression->setText(ui->expression->text() + "'");
    /**
     * \brief    Interaction avec le bouton '
     * \details  Ajoute ' dans la zone de saisie
     */
}

void MainWindow::on_bEspace_clicked()
{
    ui->expression->setText(ui->expression->text() + " ");
    /**
     * \brief    Interaction avec le bouton _
     * \details  Ajoute _ dans la zone de saisie
     */
}

void MainWindow::on_bPoint_clicked()
{
    ui->expression->setText(ui->expression->text() + ".");
    /**
     * \brief    Interaction avec le bouton .
     * \details  Ajoute . dans la zone de saisie
     */
}

void MainWindow::on_bVirgule_clicked()
{
    ui->expression->setText(ui->expression->text() + ",");
    /**
     * \brief    Interaction avec le bouton ,
     * \details  Ajoute , dans la zone de saisie
     */
}

void MainWindow::on_bDollar_clicked()
{
    try
    {
        Literal *toPush = Calc->dollar();
        if(toPush==nullptr)
        {}
        else
        {
            Calc->push(toPush);
            showStack();
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton $
     * \details  Applique l'opération $
     */
}

void MainWindow::expressionToPush(const QString& text)
{

    try
    {
        if(checkExpression(text))
        {
            if(isExpression(text))
            {
                Expression *toPush;
                QString temp = text;
                if(temp.at(1)!='[')
                {
                    temp.remove(' ');
                    toPush = new Expression(temp,expression);
                }
                else
                {
                    temp.remove(0,1);
                    temp.remove(temp.size()-1,1);
                    toPush = new Expression(temp,program);
                }
                Calc->push(toPush);
                showStack();
            }
            else if(isProgram(text) && text!="NEG" && text!="MOD" && text!="DIV" && text!="NUM" && text!="DEN" && text!="RE" && text!="IM" && text!="DUP" && text!="DROP" && text!="SWAP" && text!="FORGET" && text!="LASTOP" && text!="LASTARGS" && text!="STO" && text!="IFT" && text!="EDIT" && text!="CLEAR" && text!="EMPTY" && text!="EVAL" && text!="AND" && text!="OR" && text!="NOT")
            {
                QString temp = text;
                Expression *toPush = new Expression(temp,program);
                Calc->push(toPush);
                on_bEval_clicked();
                showStack();
            }
            else if(isAtom(text) && text!="NEG" && text!="MOD" && text!="DIV" && text!="NUM" && text!="DEN" && text!="RE" && text!="IM" && text!="DUP" && text!="DROP" && text!="SWAP" && text!="FORGET" && text!="LASTOP" && text!="LASTARGS" && text!="STO" && text!="IFT" && text!="EDIT" && text!="CLEAR" && text!="EMPTY" && text!="EVAL" && text!="AND" && text!="OR" && text!="NOT")
            {
                try
                {
                    Expression *toPush;
                    QString temp = prefMan->valueAtom(text,"ERREUR").toString();
                    QString temp2 = prefMan->valueProg(text,"ERREUR").toString();
                    if(temp == "ERREUR" && temp2 == "ERREUR")
                    {
                        toPush = new Expression("'"+text+"'",expression);
                        Calc->push(toPush);
                        showStack();
                    }
                    else
                    {
                        if(temp2=="ERREUR")
                            toPush = new Expression(QString("'"+temp+"'"),expression);
                        else
                            toPush = new Expression(QString("'"+temp2+"'"),program);
                        Calc->push(toPush);
                        on_bEval_clicked();
                        showStack();
                    }
                }
                catch(ErrorHandler & e)
                {
                    e.alertUser();
                }
            }
            else if(text == "+")
            {
                try
                {
                    on_bPlus_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
             else if(text == "-")
             {
                 try
                 {
                     on_bMoins_clicked();
                 }
                 catch(ErrorHandler& e)
                 {
                     e.alertUser();
                 }
             }
             else if(text == "*")
             {
                 try
                 {
                     on_bFois_clicked();
                 }
                 catch(ErrorHandler& e)
                 {
                     e.alertUser();
                 }
             }
             else if(text == "/")
             {
                 try
                 {
                     on_bDivision_clicked();
                 }
                 catch(ErrorHandler& e)
                 {
                     e.alertUser();
                 }
             }
            else if(text == "NEG")
            {
                try
                {
                    on_bNeg_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "$")
            {
                try
                {
                    on_bDollar_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "RE")
            {
                try
                {
                    on_bRe_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "IM")
            {
                try
                {
                    on_bIm_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "NUM")
            {
                try
                {
                    on_bNum_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "DEN")
            {
                try
                {
                    on_bDen_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "MOD")
            {
                try
                {
                    on_bMod_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "DIV")
            {
                try
                {
                    on_bDiv_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "STO")
            {
                try
                {
                    on_bSto_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "FORGET")
            {
                try
                {
                    on_bForget_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "EVAL")
            {
                try
                {
                    on_bEval_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "DUP")
            {
                try
                {
                    on_bDup_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "DROP")
            {
                try
                {
                    on_bDrop_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "SWAP")
            {
                try
                {
                    on_bSwap_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "LASTOP")
            {
                try
                {
                    on_bLastop_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "LASTARGS")
            {
                try
                {
                    on_bLastargs_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "IFT")
            {
                try
                {
                    on_bIft_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "EDIT")
            {
                try
                {
                    on_bEdit_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "CLEAR")
            {
                try
                {
                    on_bClear_clicked();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "AND")
            {
                try
                {
                    Calc->opAnd();
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "OR")
            {
                try
                {
                    Calc->opOr();
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "NOT")
            {
                try
                {
                    Calc->opNot();
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "=")
            {
                try
                {
                    Literal *toPush = Calc->opEgal();
                    Calc->push(toPush);
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "!=")
            {
                try
                {
                    Literal *toPush = Calc->opDiff();
                    Calc->push(toPush);
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "=<")
            {
                try
                {
                    Literal *toPush = Calc->opInfEgal();
                    Calc->push(toPush);
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == ">=")
            {
                try
                {
                    Literal *toPush = Calc->opSupEgal();
                    Calc->push(toPush);
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "<")
            {
                try
                {
                    Literal *toPush = Calc->opInfStrict();
                    Calc->push(toPush);
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == ">")
            {
                try
                {
                    Literal *toPush = Calc->opSupStrict();
                    Calc->push(toPush);
                    showStack();
                }
                catch(ErrorHandler& e)
                {
                    e.alertUser();
                }
            }
            else if(text == "(" || text == ")")
            {
                //vide
            }
            else
            {
                double ImNum = 0;
                double ReNum = 0;
                double ImDen = 1;
                double ReDen = 1;
                QStringList list2 = text.split("$");
                QStringList list3 = list2.at(0).split("/");
                QStringList list5 = text.split(".");

                if(list3.at(0).toDouble()==0 && list3.at(0)!="0")
                    throw ErrorHandler("Syntaxe incorrecte");
                 else
                    ReNum = list3.at(0).toDouble();

                 if(list3.count() > 1) {
                    if(list3.at(1).toDouble()==0 && list3.at(1)!="0")
                        throw ErrorHandler("Syntaxe incorrecte");
                     else
                        ReDen = list3.at(1).toDouble();
                 }

                 if(list2.count()> 1) {
                    QStringList list4 = list2.at(1).split("/");
                    if(list4.at(0).toDouble()==0 && list4.at(0)!="0")
                        throw ErrorHandler("Syntaxe incorrecte");
                    else
                        ImNum = list4.at(0).toDouble();

                    if(list4.count() > 1) {
                       if(list4.at(1).toDouble()==0 && list4.at(1)!="0")
                           throw ErrorHandler("Syntaxe incorrecte");
                       else
                           ImDen = list4.at(1).toDouble();
                     }
                 }
                 if(ReDen==0 || ImDen==0)
                      throw ErrorHandler("Nombre avec dénominateur nul impossible");
                 if(list2.count()> 1 && ImNum !=0) {
                    Complex *toPush = new Complex(ReNum,ReDen,ImNum,ImDen,complexe);
                    Calc->push(toPush);
                 }
                 else {
                     if(list3.count() > 1 && ReDen !=1) {
                        Complex *toPush = new Complex(ReNum,ReDen,ImNum,ImDen,rationnel);
                        Calc->push(toPush);
                     }
                     else {
                         if(list5.count() > 1) {
                            Complex *toPush = new Complex(ReNum,ReDen,ImNum,ImDen,reel);
                            Calc->push(toPush);
                         }
                         else {
                             Complex *toPush = new Complex(ReNum,ReDen,ImNum,ImDen,entier);
                             Calc->push(toPush);
                         }
                     }
                 }
                 showStack();
            }
            ui->expression->setText("");
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Ajout de l'élément à la pile
     * \details  Traite l'élément passé en paramètre et effectue l'opération associée
     * \param    text Le QString à traiter
     */
}

void MainWindow::on_bEgal_clicked()
{
    QString text(ui->expression->text());
    try
    {
        if(text=="")
            throw ErrorHandler("Expression invalide");
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    if(text!="")
    {
        if(!isExpression(text))
        {
            try
            {
                pushSplit(text);
            }
            catch(ErrorHandler& e)
            {
                e.alertUser();
            }
        }
        else
            expressionToPush(text);
    }
    /**
     * \brief    Interaction avec le bouton =
     * \details  Ajout de la zone de saisie à la pile
     */
}

void MainWindow::on_bClear_clicked()
{
    Calc->getStack()->clear();
    showStack();
    /**
     * \brief    Interaction avec le bouton CLEAR
     * \details  Vide la pile
     */
}


void MainWindow::on_bEval_clicked()
{
    try
    {
        if(Calc->getStack()->size()<1)
            throw(ErrorHandler("Operation impossible : nombre d'arguments insuffisant"));
        Literal *l = Calc->pop();
        if(QString(typeid(*l).name()) != EXPRESSION_ID)
        {
            Calc->push(l);
            throw(ErrorHandler("Cet opérateur ne peux pas s'appliquer sur ce type de litterale"));
        }
        Expression *e = (Expression*)l;
        if(e->getTypeExp()==expression)
        {
            QString temp = e->getValue();
            QString infixe = prefixe2infixe(temp);
            QStack<QString> res = infix2postfix(infixe);
            while(!res.isEmpty())
            {
                expressionToPush(res.pop());
            }
        }
        else
        {
            QString temp = e->getValue();
            pushSplit(temp);
        }
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton EVAL
     * \details  Evalue l'expression de la pile
     */
}

void MainWindow::on_bErase_clicked()
{
    QString t = ui->expression->text();
    t.remove(t.length()-1,1);
    ui->expression->setText(t);
    /**
     * \brief    Interaction avec le bouton <--
     * \details  Efface un caractère de la zone de saisie
     */
}

void MainWindow::on_bEmpty_clicked()
{
    ui->expression->setText("");
    /**
     * \brief    Interaction avec le bouton EMPTY
     * \details  Vide la zone de saisie
     */
}

void MainWindow::on_bRe_clicked()
{
    try
    {
        Literal *toPush = Calc->re();
        Calc->push(toPush);
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton RE
     * \details  Applique l'opération RE
     */
}

void MainWindow::on_bIm_clicked()
{
    try
    {
        Literal *toPush = Calc->im();
        Calc->push(toPush);
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton IM
     * \details  Applique l'opération IM
     */
}

void MainWindow::on_bNum_clicked()
{
    try
    {
        Literal *toPush = Calc->num();
        if(toPush==nullptr)
        {}
        else
        {
            Calc->push(toPush);
            showStack();
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton NUM
     * \details  Applique l'opération NUM
     */
}

void MainWindow::on_bDen_clicked()
{
    try
    {
        Literal *toPush = Calc->den();
        if(toPush==nullptr)
        {}
        else
        {
            Calc->push(toPush);
            showStack();
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton DEN
     * \details  Applique l'opération DEN
     */
}

void MainWindow::on_bMod_clicked()
{
    try
    {
        Literal *toPush = Calc->mod();
        if(toPush==nullptr)
        {}
        else
        {
            Calc->push(toPush);
            showStack();
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton MOD
     * \details  Applique l'opération MOD
     */
}

void MainWindow::on_bDiv_clicked()
{
    try
    {
        Literal *toPush = Calc->div();
        if(toPush==nullptr)
        {}
        else
        {
            Calc->push(toPush);
            showStack();
        }
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton DIV
     * \details  Applique l'opération DIV
     */
}

void MainWindow::on_bDup_clicked()
{
    try
    {
        Calc->dup();
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton DUP
     * \details  Applique l'opération DUP
     */
}

void MainWindow::on_bDrop_clicked()
{
    try
    {
        Calc->drop();
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton DROP
     * \details  Applique l'opération DROP
     */
}

void MainWindow::on_bSwap_clicked()
{
    try
    {
        Calc->swap();
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton SWAP
     * \details  Applique l'opération SWAP
     */
}

void MainWindow::on_bForget_clicked()
{
    try
    {
        Calc->forget();
        showStack();
    }
    catch(ErrorHandler& e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton FORGET
     * \details  Applique l'opération FORGET
     */
}

void MainWindow::on_bEdit_clicked()
{
    try
    {
        if(Calc->getStack()->isEmpty())
            throw ErrorHandler("Erreur la pile est vide");
        Literal *l = Calc->getStack()->top();
        if(QString(typeid(*l).name())!=EXPRESSION_ID)
            throw ErrorHandler("Edit ne peut s appliquer que sur un programme");
        else
        {
            Expression *e = (Expression*)l;
            Edit wind(this,prefMan,e);
            wind.exec();
            showStack();
        }
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }

    /**
     * \brief    Interaction avec le bouton EDIT
     * \details  Ouvre une fenêtre d'édition spacieuse
     */
}

void MainWindow::on_bLastop_clicked()
{
    try
    {
        Literal* toPush = Calc->lastOP();
        if(toPush!=nullptr)
        {
            Calc->push(toPush);
        }
        showStack();
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton LASTOP
     * \details  Applique l'opération LASTOP
     */
}

void MainWindow::on_bLastargs_clicked()
{
    try
    {
        Calc->lastARG();
        showStack();
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton LASTARGS
     * \details  Applique l'opération LASTARGS
     */
}

void MainWindow::on_bSto_clicked()
{

    try
    {
        if(!isAtom(Calc->getStack()->top()->getValue()))
            throw ErrorHandler("Erreur : l'identificateur n'est pas un atome autorisé");
        else
        {
            Calc->sto();
            showStack();
        }
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton STO
     * \details  Applique l'opération STO
     */
}

void MainWindow::on_bIft_clicked()
{
    try
    {
        if(Calc->stackNbElem()<2)
                throw ErrorHandler("Opération impossible : nombre d'argument insuffisant");
        else
        {
            Literal* l1 = Calc->pop();
            Literal* l2 = Calc->pop();
            Complex *aux = (Complex*)l2;
            Complex* faux = new Complex(0,1,0,1,entier);
            if(aux->compToBool(faux))
            {
                showStack();
            }
            else
            {
                Calc->push(l1);
                on_bEval_clicked();
                showStack();
            }
        }
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }

    /**
     * \brief    Interaction avec le bouton IFT
     * \details  Evalue le deuxième élément seulement si le premier est vrai
     */
}

void MainWindow::on_actionKeyboard_triggered()
{
    if(ui->actionKeyboard->isChecked())
        {
            this->setMinimumHeight(579);
            this->setMaximumHeight(579);
            Calc->setKeyboard(true);
        }
        else
        {
            this->setMinimumHeight(400);
            this->setMaximumHeight(400);
            Calc->setKeyboard(false);
        }
    /**
     * \brief    Interaction avec le bouton Keyboard
     * \details  Permet d'afficher ou non le clavier cliquable
     */

}

void MainWindow::on_actionOpen_help_triggered()
{
    Help wind(this);
    wind.exec();
    /**
     * \brief    Interaction avec le bouton Open help
     * \details  Ouvre une fenêtre avec un manuel d'utilisation
     */
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
    /**
     * \brief    Interaction avec le bouton Exit
     * \details  Ferme la calculatrice
     */
}

void MainWindow::on_actionUndo_triggered()
{
    try
    {
        Calc->undo();
        showStack();
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton Undo
     * \details  Applique l'opération Undo
     */
}

void MainWindow::on_actionRedo_triggered()
{
    try
    {
        Calc->redo();
        showStack();
    }
    catch(ErrorHandler & e)
    {
        e.alertUser();
    }
    /**
     * \brief    Interaction avec le bouton Redo
     * \details  Applique l'opération Redo
     */
}

void MainWindow::on_actionParameters_triggered()
{
    Parameters wind(this, Calc);
    wind.exec();
    showStack();
    /**
     * \brief    Interaction avec le bouton Settings
     * \details  Ouvre une fenêtre de gestion des paramètres
     */
}

void MainWindow::on_actionSecondary_view_triggered()
{
    SecondaryView wind(this,prefMan,satom,sprog);
    wind.exec();
    /**
     * \brief    Interaction avec le bouton Secondary view
     * \details  Ouvre une fenêtre de vue secondaire
     */
}

void MainWindow::addStackShow(Literal * l)
{
    ui->pile->addItem(l->toString());
    /**
     * \brief    Ajout d'un élément à l'affichage de la pile de calcul
     * \param    l La Literal à ajouter à la pile
     */
}

void MainWindow::showStack()
{
    ui->pile->clear();
    QVectorIterator<Literal*> it(*(Calc->getStack()));
    int notShown = Calc->getStack()->size()-Calc->getNbShow();
    for(int i = 0;i<notShown;i++)
        it.next();
    while(it.hasNext())
        addStackShow(it.next());
    /**
     * \brief    Affichage de la pile de calcul
     */
}

bool MainWindow::checkExpression(const QString& expToCheck)
{
        QStringList listCharAllowed;
        QStringList listStringAllowed;
        listCharAllowed.push_back("0");
        listCharAllowed.push_back("1");
        listCharAllowed.push_back("2");
        listCharAllowed.push_back("3");
        listCharAllowed.push_back("4");
        listCharAllowed.push_back("5");
        listCharAllowed.push_back("6");
        listCharAllowed.push_back("7");
        listCharAllowed.push_back("8");
        listCharAllowed.push_back("9");
        listCharAllowed.push_back("+");
        listCharAllowed.push_back("-");
        listCharAllowed.push_back("/");
        listCharAllowed.push_back("*");
        listCharAllowed.push_back("[");
        listCharAllowed.push_back("]");
        listCharAllowed.push_back("'[");
        listCharAllowed.push_back("]'");
        listStringAllowed.push_back("NEG");
        listCharAllowed.push_back("$");
        listCharAllowed.push_back(",");
        listCharAllowed.push_back(".");
        listStringAllowed.push_back("MOD");
        listStringAllowed.push_back("DIV");
        listStringAllowed.push_back("NUM");
        listStringAllowed.push_back("DEN");
        listStringAllowed.push_back("RE");
        listStringAllowed.push_back("IM");
        listStringAllowed.push_back("AND");
        listStringAllowed.push_back("OR");
        listStringAllowed.push_back("NOT");
        listStringAllowed.push_back("DUP");
        listStringAllowed.push_back("DROP");
        listStringAllowed.push_back("SWAP");
        listStringAllowed.push_back("LASTOP");
        listStringAllowed.push_back("LASTARG");
        listStringAllowed.push_back("EDIT");
        listCharAllowed.push_back("=");
        listStringAllowed.push_back("!=");
        listStringAllowed.push_back("=<");
        listStringAllowed.push_back(">=");
        listCharAllowed.push_back("<");
        listCharAllowed.push_back(">");
        listCharAllowed.push_back("(");
        listCharAllowed.push_back(")");
        listStringAllowed.push_back("STO");
        listStringAllowed.push_back("FORGET");
        listStringAllowed.push_back("IFT");
        listCharAllowed.push_back("[");
        listCharAllowed.push_back("]");
        listStringAllowed.push_back(" ");
        listCharAllowed.push_back(" ");
        if(!isExpression(expToCheck) && !isAtom(expToCheck) &&!isProgram(expToCheck))
        {
            bool space = false;
            for(int i = 0; i < expToCheck.count(); i++){
                if(expToCheck.at(i)== ' '){
                    if(space){
                        throw ErrorHandler("Expression invalide");
                        return false;
                    }
                    space = true;
                    }
                else
                    space = false;
            }

            QStringList t = split(expToCheck);
            foreach(QString s, t){
                if( s == "")
                {
                    throw ErrorHandler("Expression invalide");
                    return false;
                }
                if(!isExpression(s))
                {
                    bool ret=true;
                    foreach(QChar z, s)
                        if(!listCharAllowed.contains(z))
                            ret = false;
                    if(!listStringAllowed.contains(s) && !ret)
                    {
                        throw ErrorHandler("Expression invalide");
                        return false;
                    }
                }
                }
        }
        return true;
        /**
         * \brief     Vérification de la syntaxe
         * \details   Renvoie vrai si le QString passé en paramètre est syntaxiquement correct
         * \param     expToCheck Le QString à vérifier
         * \return    Un bool
         */
}

bool MainWindow::isExpression(const QString& text)
{

    if((text.at(0) == '\'') && (text.at(text.length()-1) == '\'') && (text.count('\'') == 2) && (text!="\'\'"))
    {
        return true;
    }
    else
        return false;
    /**
     * \brief     Vérification de l'expression
     * \details   Renvoie vrai si le QString passé en paramètre est une expression
     * \param     text Le QString à vérifier
     * \return    Un bool
     */

}

bool MainWindow::isProgram(const QString& text)
{

    if((text.at(0) == '[') && (text.at(text.length()-1) == ']'))
    {
        return true;
    }
    else
        return false;
    /**
     * \brief     Vérification de l'expression
     * \details   Renvoie vrai si le QString passé en paramètre est une expression
     * \param     text Le QString à vérifier
     * \return    Un bool
     */

}

bool MainWindow::isAtom(const QString& text)
{
    bool res;
    if(text.at(0).isUpper())
    {
        res = true;
        for(int i=1;i<text.length();i++)
            if(!text.at(i).isUpper() && !text.at(i).isDigit())
                res = false;
    }
    else
    {
        res = false;
    }
    if(text == "NEG" || text == "MOD" || text == "DIV" || text == "NUM" || text == "DEN" || text == "RE" || text == "IM" || text == "DUP" || text == "DROP" || text == "SWAP" || text == "FORGET" || text == "LASTOP" || text == "LASTARGS" || text == "STO" || text == "IFT" || text == "EDIT" || text == "CLEAR" || text == "EMPTY" || text == "EVAL" || text == "AND" || text == "OR" || text == "NOT")
        res = false;
    return res;
    /**
     * \brief     Vérification de l'expression
     * \details   Renvoie vrai si le QString passé en paramètre est un atome
     * \param     text Le QString à vérifier
     * \return    Un bool
     */
}

QStringList MainWindow::split(const QString& text)
{

    QString temp = text;
    temp.replace('\t',' ');
    temp.replace('\n',' ');
    QStringList list;
        if(temp.count('"') == 0)
            return temp.split(" ");
        else if(!isExpression(temp)){
            list = temp.split(" ");
            int i = 0;
            QStringList ret;
            bool inExpression = false;
            foreach(QString c, list){
                if( c.at(0)  == '"' || c.at(c.length()-1) == '"'){
                    if(!inExpression){
                        ret.push_back(c);
                        }
                    inExpression = !inExpression;
                    if(!inExpression){
                        QString t = ret.at(i);
                        ret.pop_back();
                        ret.push_back(t + " " + c);
                        i++;
                        }
                    }
                else if(inExpression){
                    QString t = ret.at(i);
                    ret.pop_back();
                    ret.push_back(t + " " + c);
                    }
                else if(!inExpression){
                    ret.push_back(c);
                    i++;
                    }
                }
            return ret;

    QStringList t;
    t.push_back(temp);
    return t;
    }
    return list;
    /**
     * \brief     Séparation des éléments du texte pour le traitement
     * \param     text Le QString à découper
     * \return    Une QStringList comprenant chaque élément du QString text
     */

}

void MainWindow::pushSplit(QString &text)
{
    if(!isProgram(text))
    {
        if(text == "")
            throw ErrorHandler("Expression invalide");
        QStringList tmp = split(text);
        QString tex;
        foreach (tex, tmp)
        {
            expressionToPush(tex);
        }
    }
    else
        expressionToPush(text);
    /**
     * \brief     Empilement des parties de l'expression
     * \details   Appelle split pour ensuite empiler les morceaux de l'expression initiale découpée
     * \param     text Le QString à entrer dans la pile
     */

}

QStack<QString> MainWindow::reverseQstack(QStack<QString> & stack)
{

    QStack<QString> res;
    while(!stack.isEmpty())
    {
        res.push(stack.pop());
    }
    return res;
    /**
     * \brief     Inversion de la pile
     * \details   Empile dans une nouvelle pile les éléments de l'ancienne pile dans le sens inverse
     * \param     stack L'ancienne pile à inverser
     * \return    La nouvelle pile
     */

}

int MainWindow::getWeight(QString ch)
{
   if(ch == "$")
      return 5;
   else if(ch == "AND" || ch == "OR" || ch == "NOT" || ch == "=" || ch == "!=" || ch == "=<" || ch == ">=" || ch == ">" || ch == "<")
      return 4;
   else if(ch == "DIV" || ch == "MOD" || ch == "NUM" || ch == "DEN" || ch == "IM" || ch == "RE" || ch == "NEG")
      return 3;
   else if(ch == "/" || ch == "*")
      return 2;
   else if(ch == "+" || ch == "-")
      return 1;
   else
      return 0;
   /**
    * \brief     Poids de priorité des opérandes et opérateurs
    * \details   Associe un poids de priorité à chaque élément pour gérer les priorités des notations infixe et préfixe
    * \param     ch La QString à analyser
    * \return    Un entier correspondant au poids de priorité de la chaîne de caractères
    */
}

QStack<QString> MainWindow::infix2postfix(QString & infix)
{
    QString ch;
    QStack<QString> postfix;
    QStack<QString> stack;
    int size = infix.size();
    for(int i = 0;i<infix.size();i++)
    {
        ch = infix.at(i);
        if(i+1<size)
        {
            while(infix.at(i+1) != '+' && infix.at(i+1) != '/' && infix.at(i+1) != '*' && infix.at(i+1) != '-' && infix.at(i+1) != '(' && infix.at(i+1) != ')' && infix.at(i+1) != ',' && infix.at(i) != '+' && infix.at(i) != '-' && infix.at(i) != '/' && infix.at(i) != '*' && infix.at(i) != '(' && infix.at(i) != ')' && infix.at(i) != ',')
            {
                ch.append(infix.at(i+1));
                i++;
                if(i+1>= size)
                    break;
            }
        }
        if (ch == "(")
        {
            stack.push(ch);
        }
        else if(ch == ")")
        {
            while(!stack.isEmpty() && stack.top()!="(")
            {
                postfix.push(stack.pop());
            }
        }
        else
        {
            if(getWeight(ch) == 0)
                postfix.push(ch);
            if(getWeight(ch) != 0)
            {
                while(!stack.isEmpty() && getWeight(stack.top()) >= getWeight(ch))
                {
                    postfix.push(stack.pop());
                }
                stack.push(ch);
            }
        }
    }
    while(!stack.isEmpty())
    {
        postfix.push(stack.pop());
    }
    return reverseQstack(postfix);
    /**
     * \brief     Passage notation infixe vers postfixe
     * \details   Permet de transformer un QString en notation infixe vers une pile de QString utilisant la notation postfixe
     * \param     infix La QString à tranformer en notation postfixe
     * \return    Une pile de QString en notation postfixe
     */
}


QString MainWindow::prefixe2infixe(QString & prefixe)
{
    QString infixe;
    QString tmp1,tmp2;
    QString ch;
    int count1,count2;
    int size = prefixe.size();
    for(int i = 0;i<prefixe.size();i++)
    {
        ch = prefixe.at(i);
        if(i+1<size)
        {
            while(prefixe.at(i+1) != '+' && prefixe.at(i+1) != '/' && prefixe.at(i+1) != '*' && prefixe.at(i+1) != '-' && prefixe.at(i+1) != '(' && prefixe.at(i+1) != ')' && prefixe.at(i+1) != ',' && prefixe.at(i) != '+' && prefixe.at(i) != '-' && prefixe.at(i) != '/' && prefixe.at(i) != '*' && prefixe.at(i) != '(' && prefixe.at(i) != ')' && prefixe.at(i) != ',')
            {
                ch.append(prefixe.at(i+1));
                i++;
                if(i+1>= size)
                    break;
            }
        }
        if(ch != "MOD" && ch != "DIV" && ch != "AND" && ch != "OR" && ch != "NOT" && ch != "!=" && ch != "=" && ch != "<" && ch != ">" && ch != "=<" && ch != ">=")
        {
            infixe.append(ch);
        }
        else
        {
            tmp1="";
            tmp2="";
            count1 = 1;
            count2 = 0;
            i+=2;
            while(prefixe.at(i)!=',')
            {
                tmp1.append(prefixe.at(i));
                i++;
            }
            i++;
            while(prefixe.at(i)!= ')' && (count2!=count1))
            {
                tmp2.append(prefixe.at(i));
                if(prefixe.at(i) == '(')
                    count1++;
                if(prefixe.at(i) == ')')
                    count2++;
                i++;
            }
            infixe.insert(infixe.size(),"("+tmp1+")");
            infixe.insert(infixe.size(),ch);
            infixe.insert(infixe.size(),"("+tmp2+")");

        }
    }
    return infixe;
    /**
     * \brief     Passage notation prefixe vers infixe
     * \details   Permet de transformer un QString en notation prefixe vers une pile de QString utilisant la notation infixe
     * \param     prefix La QString à tranformer en notation infixe
     * \return    Une pile de QString en notation infixe
     */
}
