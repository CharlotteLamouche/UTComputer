///
/// \class     PreferencesManager
/// \author    S.LOUINIS & C.LAMOUCHE
/// \version   1.0
/// \date      12 Juin 2016
/// \brief     Gestion de la conservation des paramètres de la calculatrice
///
/// \details   Cette classe permet de créer un fichier stockant les paramètres lors de la fermeture de la calculatrice pour les charger à sa prochaine ouverture.
///

#include "preferencesmanager.h"

PreferencesManager::PreferencesManager()
    : m_optionDictionary(NULL),m_stackDictionary(NULL)
{
    m_optionDictionary = new QMap<QString,QVariant>;
    m_stackDictionary = new QMap<QString,QVariant>;
    m_progDictionary = new QMap<QString,QVariant>;
    m_atomDictionary = new QMap<QString,QVariant>;
    /**
     * \brief    Constructeur
     * \details  Permet de construire des QMap afin de récupérer les paramètres voulus dans un fichier.ini (toutes les modifications se font sur ce fichier)
     */
}

PreferencesManager::~PreferencesManager()
{
    delete m_optionDictionary;
    delete m_stackDictionary;
    delete m_atomDictionary;
    delete m_progDictionary;
    /**
     * \brief    Destructeur
     */
}

PreferencesManager* PreferencesManager::m_singleton = NULL;


PreferencesManager* PreferencesManager::getInstance()
{

    if(m_singleton == NULL)
    {
        m_singleton = new PreferencesManager;
    }

    return m_singleton;
    /**
     * \brief    Obtenir l'instance
     * \details  Permet d'obtenir l'unique instance de PreferencesManager
     */
}

void PreferencesManager::freeInstance()
{
    delete m_singleton;
    /**
     * \brief    Supprimer l'instance
     * \details  Permet de libérer l'unique instance de PreferencesManager
     */
}

bool PreferencesManager::setValue(QString key,QVariant value, bool overwrite)
{
    if((overwrite)||(!m_optionDictionary->contains(key)))
    {
        QVariant oldValue;
        if(m_optionDictionary->contains(key))
        {
            oldValue = m_optionDictionary->value(key);
        }
        m_optionDictionary->insert(key,value);
        return true;
    }
    else
        return false;
    /**
     * \brief    Modifier la valeur des paramètres de la calculatrice
     * \details  Permet de modifier dans le QMap l'association clé-valeur
     * \param    key L'identificateur du QMap
     * \param    value La valeur associée à l'identificateur
     * \param    overwrite Un bool pour savoir si le QMap a été modifié
     * \return   Un bool, true si il a été modifié, false sinon
     */
}

bool PreferencesManager::setAtomValue(QString key,QVariant value, bool overwrite)
{
    if(!m_atomDictionary->contains(key))
    {
        if(!m_atomDictionary->contains("size"))
        {
            m_atomDictionary->insert("size",1);
        }
        else
        {
            int tmp = m_atomDictionary->value("size").toInt();
            tmp++;
            m_atomDictionary->remove("size");
            m_atomDictionary->insert("size",tmp);
        }
    }
    if((overwrite)||(!m_atomDictionary->contains(key)))
    {
        QVariant oldValue;
        if(m_atomDictionary->contains(key))
        {
            oldValue = m_atomDictionary->value(key);
        }
        m_atomDictionary->insert(key,value);
        return true;
    }
    else
        return false;
    /**
     * \brief    Modifier la valeur des atomes
     * \details  Permet de modifier dans le QMap l'association clé-valeur
     * \param    key L'identificateur du QMap
     * \param    value La valeur associée à l'identificateur
     * \param    overwrite Un bool pour savoir si le QMap a été modifié
     * \return   Un bool, true si il a été modifié, false sinon
     */
}

bool PreferencesManager::setProgValue(QString key,QVariant value, bool overwrite)
{
    if(!m_progDictionary->contains(key))
    {
        if(!m_progDictionary->contains("size"))
        {
            m_progDictionary->insert("size",1);
        }
        else
        {
            int tmp = m_progDictionary->value("size").toInt();
            tmp++;
            m_progDictionary->remove("size");
            m_progDictionary->insert("size",tmp);
        }
    }
    if((overwrite)||(!m_progDictionary->contains(key)))
    {
        QVariant oldValue;
        if(m_progDictionary->contains(key))
        {
            oldValue = m_progDictionary->value(key);
        }
        m_progDictionary->insert(key,value);
        return true;
    }
    else
        return false;
    /**
     * \brief    Modifier la valeur des programmes
     * \details  Permet de modifier dans le QMap l'association clé-valeur
     * \param    key L'identificateur du QMap
     * \param    value La valeur associée à l'identificateur
     * \param    overwrite Un bool pour savoir si le QMap a été modifié
     * \return   Un bool, true si il a été modifié, false sinon
     */
}

void PreferencesManager::removeAtomValue(QString key,QSettings & settings)
{
    if(!m_atomDictionary->contains(key))
        throw(ErrorHandler("La cle n existe pas"));
    else
    {
        int tmp = valueAtom("size",-1).toInt();
        tmp--;
        m_atomDictionary->remove("size");
        m_atomDictionary->insert("size",tmp);
        settings.remove(key);
        m_atomDictionary->remove(key);
        writeAtom(settings);
    }
    /**
     * \brief    Supprimer un atome
     * \details  Permet de supprimer la clé et la valeur de l'atome
     * \param    key L'identificateur du QMap
     * \param    settings Pour sauvegarder la suppression dans les paramètres
     */
}

void PreferencesManager::removeProgValue(QString key,QSettings & settings)
{
    if(!m_progDictionary->contains(key))
        throw(ErrorHandler("La cle n existe pas"));
    else
    {
        int tmp = valueProg("size",-1).toInt();
        tmp--;
        m_progDictionary->remove("size");
        m_progDictionary->insert("size",tmp);
        settings.remove(key);
        m_progDictionary->remove(key);
        writeProg(settings);
    }
    /**
     * \brief    Supprimer un programme
     * \details  Permet de supprimer la clé et la valeur du programme
     * \param    key L'identificateur du QMap
     * \param    settings Pour sauvegarder la suppression dans les paramètres
     */
}

bool PreferencesManager::setStackSettings(QString key,QVariant value, bool overwrite)
{
    if((overwrite)||(!m_stackDictionary->contains(key)))
    {
        QVariant oldValue;
        if(m_stackDictionary->contains(key))
        {
            oldValue = m_stackDictionary->value(key);
        }
        m_stackDictionary->insert(key,value);
        return true;
    }
    else
        return false;
    /**
     * \brief    Sauvegarder l'état de la pile
     * \details  Permet de sauvegarder les paramètres de la pile
     * \param    key L'identificateur du paramètre
     * \param    value La valeur associée à l'identificateur
     * \param    overwrite Un bool pour savoir si il a été modifié
     * \return   Un bool, true si il a été modifié, false sinon
     */
}

const QVariant PreferencesManager::value(QString key,QVariant defaultValue)
{
    if(m_optionDictionary->contains(key))
    {
        return m_optionDictionary->value(key);
    }
    else
    {
        return defaultValue;
    }
    /**
     * \brief    Obtenir la valeur du paramètre associée à une clé
     * \details  Permet de réccupérer le contenu d'une clé pour les paramètres
     * \param    key L'identificateur du paramètre
     * \param    defaultValue La valeur par défaut associée à l'identificateur
     * \return   La valeur associée
     */
}

const QVariant PreferencesManager::valueAtom(QString key,QVariant defaultValue)
{
    if(m_atomDictionary->contains(key))
    {
        return m_atomDictionary->value(key);
    }
    else
    {
        return defaultValue;
    }
    /**
     * \brief    Obtenir la valeur d'un atome associée à une clé
     * \details  Permet de réccupérer le contenu d'une clé pour les atomes
     * \param    key L'identificateur du paramètre
     * \param    defaultValue La valeur par défaut associée à l'identificateur
     * \return   La valeur associée
     */
}

const QVariant PreferencesManager::valueProg(QString key,QVariant defaultValue)
{
    if(m_progDictionary->contains(key))
    {
        return m_progDictionary->value(key);
    }
    else
    {
        return defaultValue;
    }
    /**
     * \brief    Obtenir la valeur d'un programme associée à une clé
     * \details  Permet de réccupérer le contenu d'une clé pour les programmes
     * \param    key L'identificateur du paramètre
     * \param    defaultValue La valeur par défaut associée à l'identificateur
     * \return   La valeur associée
     */
}

const QVariant PreferencesManager::valueStack(QString key,QVariant defaultValue)
{
    if(m_stackDictionary->contains(key))
    {
        return m_stackDictionary->value(key);
    }
    else
    {
        return defaultValue;
    }
    /**
     * \brief    Obtenir la valeur de la pile associée à une clé
     * \details  Permet de réccupérer le contenu d'une clé pour la pile
     * \param    key L'identificateur du paramètre
     * \param    defaultValue La valeur par défaut associée à l'identificateur
     * \return   La valeur associée
     */
}

void PreferencesManager::readSettings(QSettings & settings)
{
    settings.beginGroup("UTComputer/preferences");
    int size = settings.beginReadArray("preferenceMap");
    for (int i = 0; i < size; ++i)
    {
        settings.setArrayIndex(i);
        QString key = settings.value("key").toString();
        QVariant value = settings.value("value");
        m_optionDictionary->insert(key,value);
    }
    settings.endArray();
    settings.endGroup();
    /**
     * \brief    Lire les paramètres
     * \details  Permet de réccupérer les paramètres depuis le fichier de sauvegarde
     * \param    settings Le paramètre à lire
     */
}

void PreferencesManager::readAtom(QSettings & settings)
{
    settings.beginGroup("UTComputer/atom");
    int size = settings.beginReadArray("atomMap");
    for (int i = 0; i < size; ++i)
    {
        settings.setArrayIndex(i);
        QString key = settings.value("key").toString();
        QVariant value = settings.value("value");
        m_atomDictionary->insert(key,value);
    }
    settings.endArray();
    settings.endGroup();
    /**
     * \brief    Lire les atomes
     * \details  Permet de réccupérer les atomes depuis le fichier de sauvegarde
     * \param    settings L'atome à lire
     */
}

void PreferencesManager::readProg(QSettings & settings)
{
    settings.beginGroup("UTComputer/prog");
    int size = settings.beginReadArray("progMap");
    for (int i = 0; i < size; ++i)
    {
        settings.setArrayIndex(i);
        QString key = settings.value("key").toString();
        QVariant value = settings.value("value");
        m_progDictionary->insert(key,value);
    }
    settings.endArray();
    settings.endGroup();
    /**
     * \brief    Lire les programmes
     * \details  Permet de réccupérer les programmes depuis le fichier de sauvegarde
     * \param    settings Le programme à lire
     */
}

void PreferencesManager::writeSettings(QSettings & settings)
{
    settings.beginGroup("UTComputer/preferences");
    settings.beginWriteArray("preferenceMap");
    for (int i = 0; i < m_optionDictionary->size(); ++i)
    {
        settings.setArrayIndex(i);
        QString key = m_optionDictionary->keys().at(i);
        QVariant var = m_optionDictionary->value(key);
        settings.setValue("key", key);
        settings.setValue("value",var);
    }
    settings.endArray();
    settings.endGroup();
    settings.sync();
    /**
     * \brief    Ecrire les paramètres
     * \details  Permet de sauvegarder les paramètres sur le fichier de sauvegarde
     * \param    settings Le paramètre à sauvegarder
     */
}

void PreferencesManager::writeAtom(QSettings & settings)
{
    settings.beginGroup("UTComputer/atom");
    settings.beginWriteArray("atomMap");
    for (int i = 0; i < m_atomDictionary->size(); ++i)
    {
        settings.setArrayIndex(i);
        QString key = m_atomDictionary->keys().at(i);
        QVariant var = m_atomDictionary->value(key);
        settings.setValue("key", key);
        settings.setValue("value",var);
    }
    settings.endArray();
    settings.endGroup();
    settings.sync();
    /**
     * \brief    Ecrire les atomes
     * \details  Permet de sauvegarder les atomes sur le fichier de sauvegarde
     * \param    settings L'atome à sauvegarder
     */
}

void PreferencesManager::writeProg(QSettings & settings)
{
    settings.beginGroup("UTComputer/prog");
    settings.beginWriteArray("progMap");
    for (int i = 0; i < m_progDictionary->size(); ++i)
    {
        settings.setArrayIndex(i);
        QString key = m_progDictionary->keys().at(i);
        QVariant var = m_progDictionary->value(key);
        settings.setValue("key", key);
        settings.setValue("value",var);
    }
    settings.endArray();
    settings.endGroup();
    settings.sync();
    /**
     * \brief    Ecrire les programmes
     * \details  Permet de sauvegarder les programmes sur le fichier de sauvegarde
     * \param    settings Le programme à sauvegarder
     */
}

void PreferencesManager::writeStack(QSettings & settings)
{
    settings.beginGroup("UTComputer/stack");
    settings.beginWriteArray("stackMap");
    for (int i = 0; i < m_stackDictionary->size(); ++i)
    {
        settings.setArrayIndex(i);
        QString key = m_stackDictionary->keys().at(i);
        QVariant var = m_stackDictionary->value(key);
        settings.setValue("key", key);
        settings.setValue("value",var);
    }
    settings.endArray();
    settings.endGroup();
    settings.sync();
    /**
     * \brief    Ecrire les données de la pile
     * \details  Permet de sauvegarder la pile sur le fichier de sauvegarde
     * \param    settings La pile à sauvegarder
     */
}

void PreferencesManager::readStack(QSettings & settings)
{
    settings.beginGroup("UTComputer/stack");
    int size = settings.beginReadArray("stackMap");
    for (int i = 0; i < size; ++i)
    {
        settings.setArrayIndex(i);
        QString key = settings.value("key").toString();
        QVariant value = settings.value("value");
        m_stackDictionary->insert(key,value);
    }
    settings.endArray();
    settings.endGroup();
    /**
     * \brief    Lire la pile
     * \details  Permet de réccupérer les données de la pile depuis le fichier de sauvegarde
     * \param    settings La pile à lire
     */
}

void PreferencesManager::saveStack(Calculator* Calc,QSettings & settings)
{
    QVectorIterator<Literal*> it(*(Calc->getStack()));
    setStackSettings("size",Calc->getStack()->size(),true);
    for(int i=0;i<Calc->getStack()->size();i++)
    {
        Literal * temp = it.next();
        if(QString(typeid(*temp).name())==EXPRESSION_ID)
            setStackSettings(QString::number(i),temp->toString(),true);
        else
            setStackSettings(QString::number(i),temp->getValue(),true);
    }
    writeStack(settings);
    /**
     * \brief    Sauvegarder la pile
     * \details  Permet de réccupérer les données de la calculatrice
     * \param    Calc La calculatrice à sauvegarder
     * \param    settings Les paramètres à sauvegarder
     */
}

void PreferencesManager::loadStack(MainWindow* Wind,QSettings & settings)
{
    readStack(settings);
    for(int i=0;i<(valueStack("size",0).toInt());i++)
        Wind->expressionToPush(valueStack(QString::number(i),"0").toString());
    /**
     * \brief    Charger la pile
     * \details  Permet d'empiler les éléments sauvegardés
     * \param    Wind La MainWindow où se fait l'empilement
     * \param    settings Les paramètres à extraire
     */
}

QList<QString> PreferencesManager::listAtom()
{
   return m_atomDictionary->keys();
   /**
    * \brief    Liste d'atomes
    * \details  Forme une liste de littérales atomes
    * \return   La liste d'atome sauvegardée
    */
}

QList<QString> PreferencesManager::listProg()
{
   return m_progDictionary->keys();
   /**
    * \brief    Liste de programmes
    * \details  Forme une liste de littérales programmes
    * \return   La liste de programmes sauvegardée
    */
}
