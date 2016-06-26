#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#define PARAMETERS_FILE "parameters.ini"
#define STACK_FILE "stack.ini"
#define ATOM_FILE "atom.ini"
#define PROG_FILE "prog.ini"

#include <QMainWindow>
#include "help.h"
#include "parameters.h"
#include "edit.h"
#include "secondaryview.h"
#include "calculator.h"
#ifdef Q_OS_WIN
#define EXPRESSION_ID "class Expression"
#define COMPLEX_ID "class Complex"
#else
#define EXPRESSION_ID "10Expression"
#define COMPLEX_ID "7Complex"
#endif

class PreferencesManager;
class Calculator;
namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void expressionToPush(const QString&);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Calculator* Calc;
    void addStackShow(Literal * l);
    bool checkInput(const QString& text);
    QStringList split(const QString& text);
    bool isExpression(const QString& text);
    bool isProgram(const QString& text);
    bool checkExpression(const QString& expToCheck);
    bool isAtom(const QString& text);
    void showStack();
    void pushSplit(QString & text);
    QStack<QString> reverseQstack(QStack<QString> & stack);
    QStack<QString> infix2postfix(QString & infix);
    int getWeight(QString ch);
    QString prefixe2infixe(QString & prefixe);
    PreferencesManager* prefMan;
    QSettings* settings;
    QSettings* sstack;
    QSettings* satom;
    QSettings* sprog;

private slots:
    void on_b0_clicked();
    void on_b1_clicked();
    void on_b2_clicked();
    void on_b3_clicked();
    void on_b4_clicked();
    void on_b5_clicked();
    void on_b6_clicked();
    void on_b7_clicked();
    void on_b8_clicked();
    void on_b9_clicked();
    void on_bPlus_clicked();
    void on_bMoins_clicked();
    void on_bFois_clicked();
    void on_bDivision_clicked();
    void on_bNeg_clicked();
    void on_bGuillemet_clicked();
    void on_bEspace_clicked();
    void on_bPoint_clicked();
    void on_bVirgule_clicked();
    void on_bDollar_clicked();
    void on_bEgal_clicked();
    void on_bClear_clicked();
    void on_bEval_clicked();
    void on_bErase_clicked();
    void on_bEmpty_clicked();
    void on_bRe_clicked();
    void on_bIm_clicked();
    void on_bNum_clicked();
    void on_bDen_clicked();
    void on_bMod_clicked();
    void on_bDiv_clicked();
    void on_bDup_clicked();
    void on_bDrop_clicked();
    void on_bSwap_clicked();
    void on_bForget_clicked();
    void on_bEdit_clicked();
    void on_bLastop_clicked();
    void on_bLastargs_clicked();
    void on_bSto_clicked();
    void on_bIft_clicked();
    void on_actionKeyboard_triggered();
    void on_actionOpen_help_triggered();
    void on_actionExit_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionParameters_triggered();
    void on_actionSecondary_view_triggered();

};

#endif // MAINWINDOW_H
