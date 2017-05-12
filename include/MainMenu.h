#ifndef MAINMENU_H
#define MAINMENU_H
#include <iostream>
#include <vector>
#include <string>
#include "SubMenu.h"
#include "SensorContainer.h"
#include "windows.h"
#include "SensorContainer.h"
#include <fstream>
using namespace std;

class MainMenu
{
private:
    string name;

    SensorContainer&refSC=SensorContainer::getInstance();
    vector<shared_ptr<SubMenu>>_mainMenu;
    vector<string>_opcje{ "Dodaj nowy poziom Menu","Wyswietl drzewo menu","Pokaz wskazania czujnikow"};
public:
    MainMenu(){}
    MainMenu(string name);

    void run();
    void addNewGroup();
    void deleteMenuItem();
    void showMenu()const;
    void writeConfigFile();
    void readConfigFile();
    void showSensorValue()const;
    virtual ~MainMenu();
};

#endif // MAINMENU_H
