/*************************************************************************
                           Cleaner  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Cleaner> (fichier Cleaner.h) ----------------
#if ! defined ( Cleaner_H )
#define Cleaner_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <sstream>
#include "Time.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
std::string getCleanerId() const;

//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cleaner (const string& cleaner_str);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cleaner ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    string cleanerId;
    double latitude;
    double longitude;
    Time startTime;
    Time stopTime;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // Cleaner_H
