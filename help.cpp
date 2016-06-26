///
/// \class     Help
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface d'aide
///
/// \details   Cette classe permet à l'utilisateur d'avoir, dans une nouvelle fenêtre, un manuel d'utilisation de la calculatrice.
///

#include "help.h"
#include "ui_help.h"

Help::Help(QWidget *parent) : QDialog(parent), ui(new Ui::Help)
{
    ui->setupUi(this);
    this->setMaximumHeight(690);
    this->setMinimumHeight(690);
    this->setMaximumWidth(590);
    this->setMinimumWidth(590);
    /**
     * \brief    Constructeur
     * \details  Permet de construire une fenêtre d'aide
     * \param    parent Le QWidget parent
     */
}

Help::~Help()
{
    delete ui;
    /**
     * \brief    Destructeur
     */
}

void Help::on_bOkHelp_clicked()
{
    this->close();
    /**
    * \brief    Interaction avec le bouton OK
    * \details  Ferme la fenêtre d'aide
    */
}
