///
/// \class     Parameters
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface paramètres
///
/// \details   Cette classe permet à l'utilisateur de gérer les paramètres de la calculatrice.
///

#include "parameters.h"
#include "ui_parameters.h"
#include "calculator.h"

Parameters::Parameters(QWidget *parent,Calculator* Calcp) :
    QDialog(parent),
    ui(new Ui::Parameters)
{

    ui->setupUi(this);
    Calc = Calcp;
    this->setMaximumHeight(210);
    this->setMinimumHeight(210);
    this->setMaximumWidth(405);
    this->setMinimumWidth(405);
    ui->spAffichage->setValue(Calc->getNbShow());
    ui->checkBoxBeep->setChecked(Calc->getBeep());
    if(Calc->getBeep()==true)
        {
            ErrorHandler::sound=1;
        }
        else
        {
            ErrorHandler::sound=0;
        }
    /**
     * \brief    Constructeur
     * \details  Permet de construire une fenêtre de paramètres
     * \param    parent Le QWidget parent
     * \param    Calcp Le Calculator
     */
}

Parameters::~Parameters()
{
    delete ui;
    /**
     * \brief    Destructeur
     */
}

void Parameters::on_pushButton_clicked()
{

    Calc->setNbShow(ui->spAffichage->text().toInt());
    if(ui->checkBoxBeep->isChecked())
        {
            ErrorHandler::sound=1;
            Calc->setBeep(true);
        }
        else
        {
            ErrorHandler::sound=0;
            Calc->setBeep(false);
        }
    this->close();
    /**
    * \brief    Interaction avec le bouton Enregistrer
    * \details  Enregistre et applique les nouveaux paramètres
    */
}
