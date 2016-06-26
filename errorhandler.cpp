///
/// \class     ErrorHandler
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Gestion des erreurs
///
/// \details   Cette classe permet de traiter les erreurs liées à une mauvaise uilisation de la calculatrice.
///

#include "errorhandler.h"

bool ErrorHandler::sound;

ErrorHandler::ErrorHandler(QString const& message):mess(message)
{
    /**
     * \brief    Constructeur
     * \param    message Le QString à afficher
     */
}

void ErrorHandler::alertUser()
{
    QMessageBox errBox;
    errBox.setText(mess);
    errBox.setIcon(QMessageBox::Warning);
    if(sound)
        QApplication::beep();
    errBox.exec();
    /**
     * \brief    Fonction qui définit le message d'erreur
     */
}

QString ErrorHandler::getError()const
{
    return mess;
    /**
     * \brief    Fonction qui récupère l'erreur
     * \return   Le message d'erreur qui est un QString
     */
}
