#ifndef SECONDARYVIEW_H
#define SECONDARYVIEW_H

#include <QDialog>
#include "ui_secondaryview.h"
#include "secondaryviewvar.h"
#include "secondaryviewprog.h"
#include "errorhandler.h"
#include "preferencesmanager.h"
#include <QSettings>
class PreferencesManager;

namespace Ui
{
    class SecondaryView;
}

class SecondaryView : public QDialog
{
    Q_OBJECT

public:
    explicit SecondaryView(QWidget *parent = 0,PreferencesManager* pm = nullptr,QSettings *settings = nullptr,QSettings *settings2 = nullptr);
    void initList();
    ~SecondaryView();

private:
    Ui::SecondaryView *ui;
    PreferencesManager* pm;
    QSettings *satom;
    QSettings *sprog;

private slots:
    void on_pushButtonquit_clicked();
    void on_pushButtonAjvar_clicked();
    void on_pushButtonAjprog_clicked();
    void on_pushButtonSupvar_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_pushButtonRefresh_clicked();
    void on_textEditvar_textChanged();
    void on_textEditprog_textChanged();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_pushButtonSupprof_clicked();
};

#endif // SECONDARYVIEW_H
