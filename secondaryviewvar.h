#ifndef SECONDARYVIEWVAR_H
#define SECONDARYVIEWVAR_H
#include "preferencesmanager.h"
#include <QDialog>
class PreferencesManager;

namespace Ui {
class SecondaryViewVar;
}

class SecondaryViewVar : public QDialog
{
    Q_OBJECT

public:
    explicit SecondaryViewVar(QWidget *parent = 0,PreferencesManager *pm = nullptr);
    ~SecondaryViewVar();

private:
    Ui::SecondaryViewVar *ui;
    PreferencesManager* pm;

private slots:
    void on_pushButtonAj_clicked();

};

#endif // SECONDARYVIEWVAR_H
