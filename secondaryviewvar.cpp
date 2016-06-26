///
/// \class     SecondaryViewVar
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface vue secondaire variable
///
/// \details   Cette classe permet d'ajouter une nouvelle variable vide.
///

#include "ui_secondaryviewvar.h"
#include "secondaryviewvar.h"

SecondaryViewVar::SecondaryViewVar(QWidget *parent,PreferencesManager* pm) : QDialog(parent), ui(new Ui::SecondaryViewVar),pm(pm)
{
    ui->setupUi(this);
    /**
     * \brief    Constructeur
     * \details  Permet de construire une fenêtre de vue secondaire de variable
     * \param    parent Le QWidget parent
     */
}

SecondaryViewVar::~SecondaryViewVar()
{
    delete ui;
    /**
     * \brief    Destructeur
     */
}

void SecondaryViewVar::on_pushButtonAj_clicked()
{
    pm->setAtomValue(ui->lineEdit->text(),ui->lineEdit_2->text(),true);
    this->close();
    /**
     * \brief    Ajout d'une variable
     * \details  Permet d'ajouter l'association variable-valeur à la calculatrice
     */
}
