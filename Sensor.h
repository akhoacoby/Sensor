<<<<<<< HEAD
/**
 * @name Sensor.h
 * @date 2025.05.14
 *
 */

#ifndef _SENSOR_H
#define _SENSOR_H
=======
/*************************************************************************
                           Sensor  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Sensor> (fichier Sensor.h) ----------------
#if ! defined ( Sensor_H )
#define Sensor_H
>>>>>>> a53597cc86747c1d1e3e4fdc984b66ae8ea20064

#include <string>
#include <vector>
#include <utility>

#include "Measurement.h"
#include "Time.h"

<<<<<<< HEAD
class Sensor
=======
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Sensor>
//
//
//------------------------------------------------------------------------

class Sensor : public Sensor
>>>>>>> a53597cc86747c1d1e3e4fdc984b66ae8ea20064
{
private:
    std::string sensorID;
    double latitude;
    double longitude;

public:
<<<<<<< HEAD
    std::pair<double, double> get_coord_gps();
    std::vector<Measurement> get_measurements(Time debut);
}
=======
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Sensor & operator = ( const Sensor & unSensor );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Sensor ( const Sensor & unSensor );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Sensor ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Sensor>

#endif // Sensor_H

>>>>>>> a53597cc86747c1d1e3e4fdc984b66ae8ea20064
