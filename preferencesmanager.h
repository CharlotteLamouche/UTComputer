#ifndef PREFERENCESMANAGER_H
#define PREFERENCESMANAGER_H
#include "calculator.h"
#include "mainwindow.h"
#include <QSettings>
#include <QDir>
#include <QDebug>
#include <QMetaType>
#include <QVariant>
#include <QString>
#include <QMap>
#ifdef Q_OS_WIN
#define EXPRESSION_ID "class Expression"
#define COMPLEX_ID "class Complex"
#else
#define EXPRESSION_ID "10Expression"
#define COMPLEX_ID "7Complex"
#endif

class Calculator;
class MainWindow;
class PreferencesManager
{

public:
    static PreferencesManager* getInstance();
    void freeInstance();
    ~PreferencesManager();

    bool setValue(QString key,QVariant value, bool overwrite = true);
    const QVariant value(QString key,QVariant defaultValue);
    const QVariant valueProg(QString key,QVariant defaultValue);
    const QVariant valueAtom(QString key,QVariant defaultValue);
    void readSettings(QSettings & settings);
    void writeSettings(QSettings & settings);
    void writeProg(QSettings & settings);
    void writeAtom(QSettings & settings);
    void readProg(QSettings & settings);
    void readAtom(QSettings & settings);
    void saveStack(Calculator* Calc,QSettings & settings);
    void loadStack(MainWindow* Wind,QSettings & settings);
    bool setAtomValue(QString key,QVariant value, bool overwrite);
    bool setProgValue(QString key,QVariant value, bool overwrite);
    void removeAtomValue(QString key,QSettings & settings);
    void removeProgValue(QString key,QSettings & settings);
    QList<QString> listAtom();
    QList<QString> listProg();


private:
    PreferencesManager();
    bool setStackSettings(QString key,QVariant value, bool overwrite = true);
    void writeStack(QSettings & settings);
    void readStack(QSettings& settings);
    const QVariant valueStack(QString key,QVariant defaultValue);
    static PreferencesManager* m_singleton;
    QMap<QString,QVariant>* m_optionDictionary;
    QMap<QString,QVariant>* m_stackDictionary;
    QMap<QString,QVariant>* m_atomDictionary;
    QMap<QString,QVariant>* m_progDictionary;

};

#endif // PREFERENCESMANAGER_H
