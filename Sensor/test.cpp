#include <iostream> 
#include <string>
#include <vector>
#include "System.h"
#include "Sensor.h"
#include "Measurement.h"
#include "GovernmentUser.h"
#include "ProviderUser.h"

using namespace std;

void printDivider(const string& title) {
    cout << "\n==== " << title << " ====\n";
}

int main() {
    System system;

    system.loadData();

    // -------- Test 1: Jean-Charles and Stevenson --------
    printDivider("Test 1: Jean-Charles and Stevenson Workflow");

    auto jc = new GovernmentUser("jeancharles", "pw123", "Jean", "Charles", "jc@gov.fr");
    auto steve = new ProviderUser("stevenson", "pw456", "Steve", "Stevenson", "steve@provider.com");

    system.createAccount(jc);
    system.createAccount(steve);

    cout << "[LOGIN] Jean-Charles logs in: " << (system.verifyLogin("jeancharles", "pw123") ? "Success" : "Fail") << endl;
    cout << "[LOGIN] Stevenson logs in: " << (system.verifyLogin("stevenson", "pw456") ? "Success" : "Fail") << endl;

    string sensorId = "Rbx-001";
    cout << "[CHECK] Analyzing Roubaix sensor (Rbx-001):\n";
    system.analyzeSensor(sensorId);

    cout << "[COMPARE] Comparing similar sensors in Roubaix:\n";
    auto similarSensors = system.rankSimilarSensors(sensorId, "2024-06-01 12:00:00", "2024-06-01 18:00:00", "PM10");
    for (const auto& [sensor, similarity] : similarSensors) {
        cout << " - " << sensor.get_sensorID() << ": Similarity = " << similarity << endl;
    }

    // -------- Test 2: Stevenson changes password and compares stats --------
    printDivider("Test 2: Stevenson Changes Password and Analyzes Stats");

    system.changePassword("stevenson", "pw456", "newpass789");
    cout << "[PASSWORD] Password changed. Login with new password: " 
         << (system.verifyLogin("stevenson", "newpass789") ? "Success" : "Fail") << endl;

    double todayStat = system.calculateMeanInArea(50.7, 3.2, 10, "2024-06-01 00:00:00", "2024-06-01 23:59:59", "PM10");
    double yesterdayStat = system.calculateMeanInArea(50.7, 3.2, 10, "2024-05-31 00:00:00", "2024-05-31 23:59:59", "PM10");

    cout << "[STATS] PM10 - Today: " << todayStat << ", Yesterday: " << yesterdayStat << endl;

    // -------- Test 3: Arnaud checks efficiency of air cleaners --------
    printDivider("Test 3: Arnaud checks sensors for Noisy (air cleaners)");

    auto arnaud = new ProviderUser("arnaud", "airclean", "Arnaud", "Dupont", "arnaud@cleanair.com");
    system.createAccount(arnaud);

    vector<string> noisySensors = {"Noisy-001", "Noisy-002", "Noisy-003"};
    for (const string& id : noisySensors) {
        cout << "[SENSOR TEST] Sensor " << id << " analysis:\n";
        system.analyzeSensor(id);
    }

    // -------- Test 4: Jean-Charles detects fake sensor --------
    printDivider("Test 4: Detecting Fake Sensor in Montceau-Les-Mines");

    string fakeSensorId = "FakeSensor-001";
    bool reliable = system.evaluateSensorReliability(fakeSensorId, 5.0, "2024-06-01 00:00:00", "2024-06-01 23:59:59");

    if (!reliable) {
        cout << "[ALERT] Sensor " << fakeSensorId << " is UNRELIABLE. Marking user as unreliable.\n";
        system.setUserAsUnreliable(fakeSensorId);  // suppose this function exists
    } else {
        cout << "[INFO] Sensor " << fakeSensorId << " seems reliable.\n";
    }

    // -------- Tests supplémentaires : chargement CSV et analyses --------
    printDivider("Additional Tests: Loading CSV and Basic Analysis");

    system.loadSensors("sensors.csv");
    system.loadAttributes("attributes.csv");
    system.loadMeasurements("measurements.csv");

    cout << "Loaded " << system.list_sensors.size() << " sensors from CSV." << endl;
    cout << "Loaded " << system.list_measurements.size() << " measurements from CSV." << endl;
    cout << "Loaded " << system.attributes.size() << " attributes from CSV." << endl;

    string testSensorId = "Sensor0";
    printDivider("Analyzing Sensor " + testSensorId);
    system.analyzeSensor(testSensorId);

    printDivider("Ranking Sensors Similar to " + testSensorId);
    auto ranked = system.rankSimilarSensors(testSensorId, "01/01/2019 00:00", "03/01/2019 23:59", "PM10");
    for (const auto& [sensor, score] : ranked) {
        cout << sensor.get_sensorID() << " - Similarity: " << score << endl;
    }

    printDivider("Evaluating Reliability for " + testSensorId);
    bool reliable2 = system.evaluateSensorReliability(testSensorId, 5.0, "01/01/2019 00:00", "03/01/2019 23:59");
    cout << "Sensor " << testSensorId << " is " << (reliable2 ? "RELIABLE" : "UNRELIABLE") << endl;

    return 0;
}
