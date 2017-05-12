#ifndef SUBMENU_H
#define SUBMENU_H
#include <iostream>
#include <vector>
#include "Connector.h"
#include <memory>
#include "SensorContainer.h"
using namespace std;

class SubMenu
{
    string _title;
    SensorContainer&refSC=SensorContainer::getInstance();
public:
    vector<shared_ptr<SubMenu>>_nested;
    unique_ptr<Connector>_ptrCon;
    SubMenu(){}
    SubMenu(string name );
    SubMenu(string name,int num);
    void addFunction();
    void addNestedMenu();
    string getTitle()const{return _title;}
    virtual ~SubMenu();
};

#endif // SUBMENU_H
