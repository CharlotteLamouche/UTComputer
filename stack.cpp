///
/// \class     Stack
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Pile de calcul
///
/// \details   Cette classe gère la manipulation de la pile permettant le stockage des données.
///

#include "stack.h"

using namespace std;

QStack<Literal*>* Stack::uniqueInstance = nullptr;

QStack<Literal*>* Stack::getInstance()
{
    if (uniqueInstance == nullptr)
        uniqueInstance = new QStack<Literal*>;
    return uniqueInstance;
    /**
     * \brief    Constructeur
     * \details  Permet de construire une pile via son instance unique
     */
}

void Stack::freeInstance()
{
    if (uniqueInstance != nullptr)
        delete uniqueInstance;
    uniqueInstance = nullptr;
    /**
     * \brief    Libère l'instance
     * \details  Permet de libérer la pile en libérant son instance unique
     */
}



