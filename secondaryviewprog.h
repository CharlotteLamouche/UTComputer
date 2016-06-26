#ifndef SECONDARYVIEWPROG_H
#define SECONDARYVIEWPROG_H
#include "preferencesmanager.h"
#include <QDialog>
class PreferencesManager;

namespace Ui
{
    class SecondaryViewProg;
}

class SecondaryViewProg : public QDialog
{
    Q_OBJECT

public:
    explicit SecondaryViewProg(QWidget *parent = 0,PreferencesManager *pm = nullptr);
    ~SecondaryViewProg();

private:
    Ui::SecondaryViewProg *ui;
    PreferencesManager* pm;

private slots:
    void on_pushButtonAj_clicked();

};

#endif // SECONDARYVIEWPROG_H
