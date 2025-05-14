using namespace std;
#include <iostream>
#include <ctime>
#include "System.h"

//----------------------------------------------------- Constructeur
System::System()
{
    
}

//----------------------------------------------------- Destructeur
System::~System()
{

}

//----------------------------------------------------- Méthodes

void System::loadData()
{
    //  Chargement des données
}

bool System::analyzeSensor(const std::string & sensorId)
{
    //  Analyse de capteur
}

double System::calculateMeanInArea(double lat, double lon, double rad,const std::string & start, const std::string & end,std::string attributeId)
{
    // calcul de moyenne
}

std::vector<pair<Sensor, int>> System::rankSimilarSensors(const std::string & sensorId,const std::string & start,
const std::string & end,const std::string & timestamp, std::string attributeId)
{
    //  classement des capteurs
    return;
}

bool System::evaluateSensorReliability(const std::string & sensorId)
{
    // évaluation de fiabilité
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

