/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Provider> (fichier Provider.h) ----------------
#if ! defined ( Provider_H )
#define Provider_H

//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Cleaner.h"
#include <string>
#include <unordered_map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Provider>
//
//
//------------------------------------------------------------------------

class Provider
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AddCleaner(const std::string & cleanerid);
    static Provider& GetOrCreate(std::string providerId,std::unordered_map<std::string, Provider>& providerMap);
    

//-------------------------------------------- Constructeurs - destructeur
Provider(std::string providerId);    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Provider ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    std::string providerId;
    std::vector<std::string> cleaners_own;
//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Provider>

#endif // Provider_H

