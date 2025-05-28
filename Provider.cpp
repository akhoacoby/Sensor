/*************************************************************************
                           Provider  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Provider> (fichier Provider.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Provider.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Provider::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Provider::AddCleaner(const std::string& cleanerId)
{
    for (const std::string& id : cleaners_own)
    {
        if (id == cleanerId)
            return; // Already exists, skip
    }
    cleaners_own.push_back(cleanerId);
}

Provider& Provider::GetOrCreate(std::string providerId,
                                std::unordered_map<std::string, Provider>& providerMap)
{
    auto it = providerMap.find(providerId);
    if (it != providerMap.end())
    {
        return it->second;
    }
    
    // Not found: create new
    providerMap[providerId] = Provider(providerId);
    return providerMap[providerId];
}


//------------------------------------------------- Surcharge d'opérateurs
Provider & Provider::operator = ( const Provider & unProvider )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Provider::Provider ( const Provider & unProvider )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Provider>" << endl;
#endif
} //----- Fin de Provider (constructeur de copie)


Provider::Provider(std::string providerId)
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Provider>" << endl;
#endif
} //----- Fin de Provider


Provider::~Provider ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Provider>" << endl;
#endif
} //----- Fin de ~Provider


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

