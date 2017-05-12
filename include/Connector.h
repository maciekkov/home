#ifndef CONNECTOR_H
#define CONNECTOR_H
#include <iostream>
#include <vector>
#include <string>

#include "SensorContainer.h"
using namespace std;
class Connector
{
    string key;
   unsigned int index;
    SensorContainer& refSC=SensorContainer::getInstance();
public:
    Connector(const string& key,unsigned int index);
    virtual ~Connector();
    void run()
    {
        auto  it=refSC.sensorMap.find(key);
        if(it!=refSC.sensorMap.end())
        {
            vector< shared_ptr<Sensor>>vec =it->second;
            cout<< vec[index]->getValue()<<endl;;
        }
    }
};

#endif // CONNECTOR_H
