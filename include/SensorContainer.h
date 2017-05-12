#ifndef SENSORCONTAINER_H
#define SENSORCONTAINER_H
#include "Sensor.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class SensorContainer
{
public:
    static SensorContainer& getInstance()
    {
        static SensorContainer instance;
        return instance;
    }
private:
    SensorContainer(){}
public:
     map<string,vector<shared_ptr<Sensor>>> sensorMap;
    SensorContainer(const SensorContainer&) = delete;
    void operator=(const SensorContainer&) = delete;
    void showList()const;
    void addNewSensor( const string& key,shared_ptr<Sensor> x);
    int getValue (const string& key,unsigned int& index);
    map<string,vector<shared_ptr<Sensor>>>& refToMap();
    bool getStan (const string& key,unsigned int& index);
    virtual ~SensorContainer(){}
};

#endif // SENSORCONTAINER_H
