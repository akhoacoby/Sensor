<<<<<<< HEAD
/**
 * @name AirCleaner.h
 * @date 2025.05.14
 *
 */

#ifndef _AIRCLEANER_H
#define _AIRCLEANER_H
=======
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
>>>>>>> a53597cc86747c1d1e3e4fdc984b66ae8ea20064

#include <string>

#include "Time.h"

<<<<<<< HEAD
class AirCleaner
{
  private:
    std::string CleanerID;
    double latitude;
    double longitude;
    Time startTime;
    Time stopTime;
}
=======
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cleaner>
//
//
//------------------------------------------------------------------------

class Cleaner : public Cleaner
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
 
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Cleaner ( const Cleaner & unCleaner );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Cleaner ( );
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

private:
string cleanerId;
double latitude;
double longitude;
time_t startTime;
time_t stopTime;


};

//-------------------------------- Autres définitions dépendantes de <Cleaner>

#endif // Cleaner_H

>>>>>>> a53597cc86747c1d1e3e4fdc984b66ae8ea20064
