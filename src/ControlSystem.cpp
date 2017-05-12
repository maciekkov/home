#include "ControlSystem.h"

using namespace std;
ControlSystem::ControlSystem()
{
    this->_ptrMM = make_unique<MainMenu>();
    this->_ptrTH = make_unique<iThread>();

}
void ControlSystem::run()const
{
    unsigned int num;
    this->_ptrMM -> run() ;

    thread T1(&iThread::run,iThread());
    cout<<"Trwa uruchamianie...";
    Sleep(2000);

}
ControlSystem::~ControlSystem()
{
    //dtor
}
