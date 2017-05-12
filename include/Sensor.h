#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <string>
#include "Log.h"
#include <memory>
using namespace std;
class Sensor
{
private:
    string _name;
    int _value{25};
    bool stan{true};

    shared_ptr<Log>_ptrLog;
public:
    Sensor(const string & name)
    {
        this -> _ptrLog = make_shared<Log>();
        this -> _name = name;
    }
    void setValue()
    {
        int num;
        ifstream file("Temp.txt",ios::in);
        if(file.good())
        {
            file >> num;
            file.close();
            this -> _value=num;
        }
        else
        {
            cout<<"Blad odczytu temperatury"<<endl;
            this -> _ptrLog->writeLogFile("B³¹d odczytu pomiaru temperatury");
            this -> _value = -999;
        }
    }
    int getValue()
    {
        return this->_value;
    }
    string getName()
    {
        return this->_name;
    }
    bool getStan()
    {
        return this->stan;
    }
    virtual ~Sensor() {}
};
#endif // SENSOR_H
