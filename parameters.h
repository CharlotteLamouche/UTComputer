#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "calculator.h"
#include <QDialog>

namespace Ui
{
    class Parameters;
}
class Calculator;
class Parameters : public QDialog
{
    Q_OBJECT

public:
    explicit Parameters(QWidget *parent = 0,Calculator* Calcp = nullptr);
    ~Parameters();

private:
    Ui::Parameters *ui;
    Calculator* Calc;

private slots:
    void on_pushButton_clicked();
};

#endif // PARAMETERS_H
