///
/// \class     Literal
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Données manipulées par la calculatrice
///
/// \details   Cette classe abstraite gère la conversion de Literal en QString et centralise tous les types de littérale.
///

#include "literal.h"

QString Literal::getValue()const
{
    return this->toString();
    /**
     * \brief    Obtenir le contenu
     * \return   Un QString correspondant au contenu de la Literal
     */
}
