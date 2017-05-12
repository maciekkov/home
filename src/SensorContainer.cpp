#include "SensorContainer.h"
using namespace std;
void SensorContainer::addNewSensor( const string& key,shared_ptr<Sensor> x)
{
    this->sensorMap[key].push_back( x );
}
int SensorContainer::getValue (const string& key,unsigned int& index)
{

}
void SensorContainer::showList()const
{
   auto  it=sensorMap.begin();
    for(it;it!=sensorMap.end();it++)
    {
        cout<<"*  "<<it->first<<endl;
        vector< shared_ptr<Sensor>>vec =it->second;
        for(unsigned i =0;i<vec.size();i++)
        {
             cout<<"      "<<i+1<<"."<<   vec[i] ->getName() <<endl;
        }
    }
}
bool SensorContainer::getStan (const string& key,unsigned int& index)
{
    bool stan;
    auto p=sensorMap.find(key);
    if(p!=sensorMap.end())
    {
        vector<shared_ptr<Sensor>>vec=p->second;
         return vec[index]->getStan();
    }

}
 map<string,vector<shared_ptr<Sensor>>>& SensorContainer::refToMap()
{
    return this->sensorMap;
}


