///
/// \class     Edit
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface edit
///
/// \details   Cette classe permet d'ouvrir une fenêtre d’édition spacieuse pour éditer un programme.
///

#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent,PreferencesManager *pm,Expression *e) :
    QDialog(parent),
    ui(new Ui::Edit),
    pm(pm),e(e)
{
    ui->setupUi(this);
    ui->expression->setFocus();
    this->setMaximumHeight(490);
    this->setMinimumHeight(490);
    this->setMaximumWidth(570);
    this->setMinimumWidth(570);
    ui->expression->setText(e->toString());
    /**
     * \brief    Constructeur
     * \param    parent Le QWidget parent
     */
}

Edit::~Edit()
{
    delete ui;
    /**
     * \brief    Destructeur
     */
}

void Edit::on_pushButton_clicked()
{
    QString temp = ui->expression->toPlainText();
    temp.remove(0,1);
    temp.remove(temp.size()-1,1);
    e->setExp(temp);
    temp=e->toString();
    temp.remove(0,1);
    temp.remove(temp.size()-1,1);
    e->setExp(temp);
    this->close();
    /**
    * \brief    Interaction avec le bouton Envoyer
    * \details  Ajoute ce qui a été saisi dans la pile
    */
}
