#include "MainMenu.h"
#include <limits>
using namespace std;
MainMenu::MainMenu(string name)
{
    this->name = "Main Menu";
    this ->_mainMenu.push_back(make_shared<SubMenu>(name));
}
void MainMenu::run()
{
    unsigned int choice;
    while(choice!=0)
    {
        system("cls");
        if(_mainMenu.size()==0)
        {
            cout<< 1 <<" "<<this-> _opcje[0]<<endl;
            cout<<"Wybierz opcje: ";
        }
        else
        {
            for(int i=0; i<_opcje.size(); i++)
            {
                cout<<endl<<i+1<<"."<<_opcje[i] ;
            }
            cout<<"Wybierz opcje: ";
        }
        while(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Ivalid input, try again"<<endl;
            system("pause");
            system("cls");
            cout<<"Wybierz opcje: ";

        }
        switch(choice)
        {
        case 1:
            addNewGroup();
            break;
        case 2:
            showMenu();
            break;
        case 3:
            showSensorValue();
            break;
        default:
            break;
        }
    }
}
void MainMenu::showSensorValue()const
{
    for(unsigned int i=0; i<this->_mainMenu.size(); i++)
    {
        cout<<i<<" "<<this->_mainMenu[i]->getTitle()<<endl;
    }
    int index;
    cout<<"Podaj numer kategorii: ";
    cin>>index;
    for(int i=0; i<this->_mainMenu[index]->_nested.size(); i++)
    {
        _mainMenu[index]->_nested[i]->_ptrCon->run();
        cout<<endl;
        system("pause");
    }
}
void MainMenu::addNewGroup()
{
    system("cls");
    char c;
    string title;
    cout<<"Podaj nazwe nowego poziomu: " ;
    cin.ignore( );
    getline(cin,title);
    cout<<"Czy ma byc to koncowy element menu? t/n" ;
    cin>>c;
    while( (c!='t'&&    c!='n'))
    {
        cout<<"invalid input try again"<<endl;
        system("pause");
        system("cls");
        cout<<"Czy ma byc to koncowy element menu? t/n" ;
        cin>>c;
    }
    if(c=='t')
    {
        this->_mainMenu.push_back(make_shared<SubMenu>(title ));
    }
    else
    {
        int num=0;
        cout<<"Ile podpoziomow ma posiadac ten poziom? "<<endl;
        while(!(cin >> num))
        {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"invalid input try again"<<endl;
            system("pause");
            system("cls");
            cout<<"Ile podpoziomow ma posiadac ten poziom? "<<endl;
        }
        _mainMenu.push_back(make_shared<SubMenu>(title,num));
    }
}
void MainMenu::deleteMenuItem()
{

}
void MainMenu::showMenu()const
{

    cout<<"                                "<<this->name<<endl;
    for(int i=0; i<_mainMenu.size(); i++)
    {
        cout<<"|"<<endl;
        cout<<" -";
        cout<< i+1<<" "<<_mainMenu[i]->getTitle()<<endl;

        for(int k=0; k<_mainMenu[i]->_nested.size(); k++)
        {
            cout<<"    |"<<endl;
            cout<<"     -"<<_mainMenu[i]->_nested[k]->getTitle()<<endl;

            if(_mainMenu[i]->_nested[k]->_nested.size()>0)
                for(int m=0; m<_mainMenu[i]->_nested[k]->_nested.size(); m++)
                {
                    cout<<"         |"<<endl;
                    cout<<"          -"<<_mainMenu[i]->_nested[k]->_nested[m]->getTitle()<<endl;
                }
        }
    }
    system("pause");
}
void MainMenu::writeConfigFile()
{
//    ofstream file("MenuCOnfigFile.txt",ios::out);
//    if(file.good())
//    {
//         for(int k=0; k<_mainMenu[i]->_nested.size(); k++)
//        {
//
//           file<<_mainMenu[i]->_nested[k]->getTitle()<<endl;
//            if(_mainMenu[i]->_nested[k]->_nested.size()>0)
//                for(int m=0; m<_mainMenu[i]->_nested[k]->_nested.size(); m++)
//                {
//                    cout<<"         |"<<endl;
//                    cout<<"          -"<<_mainMenu[i]->_nested[k]->_nested[m]->getTitle()<<endl;
//                }
//        file.close();
//    }
//    else
//    {
//        cout<<"Blad pliku nie udalo sie zaladowac konfiguracji";
//    }
}
void readConfigFile()
{

}
MainMenu::~MainMenu()
{
    //dtor
}
