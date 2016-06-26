///
/// \class     SecondaryView
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Interface vue secondaire
///
/// \details   Cette classe permet de gérer la gestion et l'édition de variables et de programmes.
///

#include "secondaryview.h"

SecondaryView::SecondaryView(QWidget *parent,PreferencesManager * pm,QSettings * settings,QSettings * settings2) :
    QDialog(parent),
    ui(new Ui::SecondaryView),
    pm(pm),
    satom(settings),
    sprog(settings2)
{
    ui->setupUi(this);
    this->setMaximumHeight(638);
    this->setMinimumHeight(638);
    this->setMaximumWidth(595);
    this->setMinimumWidth(595);
    initList();

    ui->pushButtonquit->setFocus();
    /**
     * \brief    Constructeur
     * \details  Permet de construire une fenêtre de vue secondaire
     * \param    parent Le QWidget parent
     */
}

SecondaryView::~SecondaryView()
{
    delete ui;
    /**
     * \brief    Destructeur
     */
}

void SecondaryView::on_pushButtonquit_clicked()
{
    this->close();
    /**
    * \brief    Interaction avec le bouton Quitter
    * \details  Ferme la fenêtre de vue secondaire
    */
}

void SecondaryView::on_pushButtonAjvar_clicked()
{
    SecondaryViewVar wind(this,pm);
    wind.exec();
    /**
    * \brief    Interaction avec le bouton Ajouter de la partie variable
    * \details  Ajoute le nouvel atome
    */
}

void SecondaryView::on_pushButtonAjprog_clicked()
{
    SecondaryViewProg wind(this,pm);
    wind.exec();
    /**
    * \brief    Interaction avec le bouton Ajouter de la partie programme
    * \details  Ajoute le nouveau programme
    */
}

void SecondaryView::on_comboBox_currentIndexChanged(const QString &arg1)
{
    ui->textEditvar->setText(pm->valueAtom(arg1,"").toString());
    /**
    * \brief    Affiche la valeur de l'atome de la liste dans la fenêtre d'édition
    * \param    arg1 L'atome que l'on veut éditer
    */
}

void SecondaryView::initList()
{
    QList<QString> list = pm->listAtom();
    for(int i = 0;(i<list.size()-1);i++)
    {
        if(ui->comboBox->findText(list.at(i))==-1)
            ui->comboBox->insertItem(i,list.at(i));
    }
    QList<QString> list2 = pm->listProg();
    for(int i = 0;(i<list2.size()-1);i++)
    {
        if(ui->comboBox_2->findText(list2.at(i))==-1)
            ui->comboBox_2->insertItem(i,list2.at(i));
    }
    /**
    * \brief    Initialisation des listes d'atomes et de programmes
    * \details  Affiche les atoms et programmes dans leurs listes déroulantes respectives
    */
}

void SecondaryView::on_pushButtonRefresh_clicked()
{
    initList();
    /**
    * \brief    Initialisation des listes d'atomes et de programmes
    * \details  Permet de rafraîchir les listes si on veut éditer un atome ou un programme après l'avoir entré via une des vues secondaires
    */
}


void SecondaryView::on_textEditvar_textChanged()
{
    pm->setAtomValue(ui->comboBox->currentText(),ui->textEditvar->toPlainText(),true);
    /**
    * \brief    Edition des variables
    * \details  Permet d'éditer la valeur d'une variable
    */
}

void SecondaryView::on_textEditprog_textChanged()
{
    pm->setProgValue(ui->comboBox_2->currentText(),ui->textEditprog->toPlainText(),true);
    /**
    * \brief    Edition des programmes
    * \details  Permet d'éditer le contenu d'un programme
    */
}

void SecondaryView::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->textEditprog->setText(pm->valueProg(arg1,"").toString());
    /**
    * \brief    Affiche le contenu du programme de la liste dans la fenêtre d'édition
    * \param    arg1 Le programme que l'on veut éditer
    */

}

void SecondaryView::on_pushButtonSupprof_clicked()
{
    pm->removeProgValue(ui->comboBox_2->currentText(),*sprog);
    ui->comboBox_2->clear();
    initList();
    /**
    * \brief    Supprime le programme
    */
}

void SecondaryView::on_pushButtonSupvar_clicked()
{
    pm->removeAtomValue(ui->comboBox->currentText(),*satom);
    ui->comboBox->clear();
    initList();
    /**
    * \brief    Supprime l'atome
    */
}
