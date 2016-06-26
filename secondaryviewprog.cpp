///
/// \class     SecondaryViewProg
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface vue secondaire programme
///
/// \details   Cette classe permet d'ajouter un nouveau programme vide.
///

#include "secondaryviewprog.h"
#include "ui_secondaryviewprog.h"

SecondaryViewProg::SecondaryViewProg(QWidget *parent,PreferencesManager *pm) : QDialog(parent), ui(new Ui::SecondaryViewProg),pm(pm)
{
    ui->setupUi(this);
    /**
     * \brief    Constructeur
     * \details  Permet de construire une fenêtre de vue secondaire de programme
     * \param    parent Le QWidget parent
     */
}

SecondaryViewProg::~SecondaryViewProg()
{
    delete ui;
    /**
     * \brief    Destructeur
     */
}

void SecondaryViewProg::on_pushButtonAj_clicked()
{
    pm->setProgValue(ui->lineEdit->text(),"",true);
    this->close();
    /**
     * \brief    Ajout d'un programme
     * \details  Permet d'ajouter un programme vide à la calculatrice
     */
}
