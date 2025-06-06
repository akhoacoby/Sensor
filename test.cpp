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

    auto jc = std::make_unique<GovernmentUser>("jeancharles", "pw123", "Jean", "Charles", "jc@gov.fr");
    auto steve = std::make_unique<ProviderUser>("stevenson", "pw456", "Steve", "Stevenson", "steve@provider.com");

    cout << "[LOGIN] Jean-Charles logs in: " << (jc->Verify_pw("pw123") ? "Fail" : "Success") << endl;
    cout << "[LOGIN] Stevenson logs in: " << (steve->Verify_pw("pw456") ? "Fail" : "Success") << endl;

    system.addUser(move(jc));
    //system.addUser(move(steve));

    string sensorId = "Sensor0";
    cout << "[CHECK] Analyzing Roubaix sensor (Sensor0):\n";
    system.analyzeSensor(sensorId);

    cout << "[COMPARE] Comparing similar sensors in Roubaix:\n";
    auto similarSensors = system.rankSimilarSensors(sensorId, "2019-06-01 12:00:00", "2019-06-01 18:00:00", "PM10");
    for (const auto& [sensor, similarity] : similarSensors) {
        cout << " - " << sensor.get_sensorID() << ": Similarity = " << similarity << endl;
    }

    // -------- Test 2: Stevenson changes password and compares stats --------
    printDivider("Test 2: Stevenson Changes Password and Analyzes Stats");

    steve->setPassword("newpass789");
    cout << "[PASSWORD] Password changed. Login with new password: " 
         << (steve->Verify_pw("newpass789") ? "Fail" : "Success") << endl;

    double todayStat = system.calculateMeanInArea(50.7, 3.2, 10, "2019-06-01 00:00:00", "2019-06-01 23:59:59", "PM10");
    double yesterdayStat = system.calculateMeanInArea(50.7, 3.2, 10, "2019-05-31 00:00:00", "2019-05-31 23:59:59", "PM10");

    cout << "[STATS] PM10 - Today: " << todayStat << ", Yesterday: " << yesterdayStat << endl;

    // -------- Test 3: Arnaud checks efficiency of air cleaners --------
    printDivider("Test 3: Arnaud checks sensors for Noisy (air cleaners)");

    auto arnaud = std::make_unique<ProviderUser>("arnaud", "airclean", "Arnaud", "Dupont", "arnaud@cleanair.com");
    //system.addUser(move(arnaud));

    vector<string> cleanerid = {"Cleaner0","Cleaner1"};
    for (const string& id : cleanerid) {
        cout << "[SENSOR TEST] Sensor " << id << " analysis:\n";
        system.calculateCleanerEfficiency(id, 100, "PM10");
    }

    // -------- Test 4: Jean-Charles detects fake sensor --------
    printDivider("Test 4: Detecting Fake Sensor in Montceau-Les-Mines");

    string fakeSensorId = "FakeSensor-001";
    bool reliable = system.evaluateSensorReliability(fakeSensorId, 5.0, "2019-06-01 00:00:00", "2019-06-01 23:59:59");

    if (!reliable) {
        cout << "[ALERT] Sensor " << fakeSensorId << " is UNRELIABLE. Marking user as unreliable.\n";
        //system.setUserAsUnreliable(fakeSensorId);  // suppose this function exists
    } else {
        cout << "[INFO] Sensor " << fakeSensorId << " seems reliable.\n";
    }

    return 0;
}
