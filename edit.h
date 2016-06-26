#ifndef EDIT_H
#define EDIT_H
#include "preferencesmanager.h"
#include "expression.h"
#include <QDialog>
class PreferencesManager;
namespace Ui
{
    class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT

public:
    explicit Edit(QWidget *parent = 0,PreferencesManager * pm = nullptr,Expression *e = nullptr);
    ~Edit();

private:
    Ui::Edit *ui;
    PreferencesManager * pm;
    Expression * e;

private slots:
    void on_pushButton_clicked();
};

#endif // EDIT_H
