#include "System.h"
#include "csvfile.h"
#include "sensors.h"

//----------------------------------------------------- Constructeur
System::System()
{
    
}

//----------------------------------------------------- Destructeur
System::~System()
{

}

//----------------------------------------------------- Méthodes

void System::loadData() {
    // Chargement des sensors
    Csvfile sensorFile("sensors.csv");
    for (const string& line : sensorFile.getLines()) {
        Sensor s(line);
        list_sensors.push_back(s);
    }

    // Chargement des measurments
    Csvfile measurementFile("measurements.csv");
    for (const string& line : measurementFile.getLines()) {
        Measurement m(line);
        list_measurements.push_back(m);
    }

    // Chargement des cleaners
    Csvfile cleanerFile("cleaners.csv");
    for (const string& line : cleanerFile.getLines()) {
        Cleaner c(line);
        list_cleaners.push_back(c);
    }

   
}


bool System::analyzeSensor(const std::string & sensorId)
{
    //  Analyse de capteur
}

double System::calculateMeanInArea(double lat, double lon, double rad,const std::string & start,
const std::string & end,std::string attributeId)
{
        Time tStart(start);
    Time tEnd(end);
    double total = 0.0;
    int count = 0;

    for (const Sensor& s : list_sensors) {
        double dist = sqrt(pow(s.get_lat() - lat, 2) + pow(s.get_long() - lon, 2));
        if (dist <= rad) {
            vector<Measurement> sensorMeasurements = s.get_measurements(list_measurements, tStart);
            for (const Measurement& m : sensorMeasurements) {
                if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attributeId) {
                    total += m.getValue();
                    count++;
                }
            }
        }
    }

    if (count == 0) return -1;
    return total / count;

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

