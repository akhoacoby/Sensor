#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <map>

#include "System.h"
#include "Time.h"
#include "Sensor.h"
#include "Measurement.h"

using namespace std;

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


double pearsonCorrelation(const vector<double>& x, const vector<double>& y) {
    if (x.size() != y.size() || x.empty()) return 0.0;

    double meanX = accumulate(x.begin(), x.end(), 0.0) / x.size();
    double meanY = accumulate(y.begin(), y.end(), 0.0) / y.size();

    double numerator = 0.0;
    double denomX = 0.0;
    double denomY = 0.0;

    for (size_t i = 0; i < x.size(); ++i) {
        double dx = x[i] - meanX;
        double dy = y[i] - meanY;
        numerator += dx * dy;
        denomX += dx * dx;
        denomY += dy * dy;
    }

    if (denomX == 0.0 || denomY == 0.0) return 0.0;

    return numerator / sqrt(denomX * denomY);
}


vector<pair<Sensor, double>> System::rankSimilarSensors(const string& sensorId,
                                                        const string& start,
                                                        const string& end,
                                                        const string& timestamp,
                                                        string attributeId) {
    Time tStart(start);
    Time tEnd(end);
    vector<pair<Sensor, double>> rankedSensors;

    // Trouver le capteur de référence
    Sensor* refSensor = nullptr;
    for (Sensor& s : list_sensors) {
        if (s.get_sensorID() == sensorId) {
            refSensor = &s;
            break;
        }
    }
    if (!refSensor) return rankedSensors;

    // Récupérer les mesures de référence
    vector<Measurement> refMeasurements = refSensor->get_measurements(list_measurements, tStart);
    vector<double> refValues;

    for (const Measurement& m : refMeasurements) {
        if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attributeId) {
            refValues.push_back(m.getValue());
        }
    }

    // Comparer avec les autres capteurs
    for (const Sensor& s : list_sensors) {
        if (s.get_sensorID() == sensorId) continue;

        vector<Measurement> otherMeasurements = s.get_measurements(list_measurements, tStart);
        vector<double> otherValues;

        for (const Measurement& m : otherMeasurements) {
            if (m.getTimeStamp() <= tEnd && m.getAttribute_id() == attributeId) {
                otherValues.push_back(m.getValue());
            }
        }

        // Assurer une comparaison sur une base commune (même taille)
        size_t minSize = min(refValues.size(), otherValues.size());
        if (minSize < 10) continue; // trop peu de points en commun, skip

        vector<double> x(refValues.begin(), refValues.begin() + minSize);
        vector<double> y(otherValues.begin(), otherValues.begin() + minSize);

        double similarity = pearsonCorrelation(x, y);
        rankedSensors.push_back({s, similarity});
    }

    // Trier du plus similaire au moins similaire
    sort(rankedSensors.begin(), rankedSensors.end(),
        [](const pair<Sensor, double>& a, const pair<Sensor, double>& b) {
            return a.second > b.second;
        });

    return rankedSensors;
}

bool System::evaluateSensorReliability(const std::string & sensorId)
{
    // évaluation de fiabilité
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

