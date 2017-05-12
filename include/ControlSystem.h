#ifndef CONTROLSYSTEM_H
#define CONTROLSYSTEM_H
#include <iostream>
#include <thread>
#include "iThread.h"
#include "MainMenu.h"
#include <memory>
using namespace std;

class ControlSystem
{
private:
    thread T1;
    unique_ptr<MainMenu>_ptrMM;
    unique_ptr<iThread>_ptrTH;

    public:
        ControlSystem();
        void run()const;
        virtual ~ControlSystem();

};

#endif // CONTROLSYSTEM_H
