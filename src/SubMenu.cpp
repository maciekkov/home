#include "SubMenu.h"
#include <windows.h>
#include <limits>
using namespace std;

SubMenu::SubMenu(string name )
{
    this->_title = name;
    addFunction();
}
SubMenu::SubMenu(string name,int num)
{
    char c;
    this->_title=name;
    for(int i=0; i<num; i++)
    {
        system("cls");
        string title;
        cout<<"Podaj nazwe podpoziomu nr "<<i+1<<" :";
        cin.ignore();
        getline(cin,title);
        cout<<"Czy ma byc to koncowy element menu? t/n : " ;
        cin>>c;
        if(c=='t')
        {
            _nested.push_back(make_shared<SubMenu>(title));
        }
        else
        {
            int num;
            cout<<"Ile podpoziomow ma posiadac ten poziom? :" ;
            while(!cin >> num)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<"invalid input try again"<<endl;
                system("pause");
                system("cls");
            }
            _nested.push_back(make_shared<SubMenu>(title,num));
        }
    }
}
void SubMenu::addFunction()
{
    this->refSC.showList();
    string key;
    int index;
    cout<<"Podaj kategorie: ";
    cin>>key;
    cout<<"Podaj numer czujnika: ";
    cin>>index;
    this->_ptrCon=make_unique<Connector>(key,index);
}
void SubMenu::addNestedMenu()
{

}
SubMenu::~SubMenu()
{

}
