#ifndef ITHREAD_H
#define ITHREAD_H
#include <memory>
#include "Log.h"
#include "SensorContainer.h"
#include <windows.h>

using namespace std;

class iThread
{
private:
   shared_ptr<Log>_ptrLog;
   SensorContainer & _ptrSC = SensorContainer::getInstance();
   mutable bool newSensor{false};
   mutable bool loadConfig{false};
public:
    iThread();
    void run();
    void detection();
    void writeConfigFile()const;
    void readConfigFile();
    void showList()const;
    bool isNewSensor(){return newSensor;}
    virtual ~iThread();
};
#endif // ITHREAD_H
