#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <QString>
#include <QMessageBox>
#include <QApplication>

class ErrorHandler
{

public:
    ErrorHandler(QString const& message);
    QString getError()const;
    void alertUser();
    static bool sound;
    virtual ~ErrorHandler(){}

private:
    QString mess;
};

#endif // ERRORHANDLER_H
