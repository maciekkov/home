#include "iThread.h"

iThread::iThread()
{
    _ptrLog = make_shared<Log>();
}
void iThread::run()
{
    readConfigFile();
    while(true)
    {
        detection();
        if(isNewSensor())
        {
            writeConfigFile();
            showList();
        }
    }
}
void iThread::writeConfigFile()const
{
    ofstream file("SensorsConfigFile.txt",ios::out|ios::trunc);
    if(file.good())
    {
        file <<_ptrLog -> getTimeDate() << '\n';
        map<string,vector<shared_ptr<Sensor>>> & refMap=_ptrSC.refToMap();
        map<string,vector<shared_ptr<Sensor>>>::iterator it=refMap.begin();
        for(it; it!=refMap.end(); it++)
        {
            vector<shared_ptr<Sensor>> vec = it -> second;
            for(int i=0; i<vec.size(); i++)
            {
                file << " *" <<it -> first;
                file << " [" <<vec[i] -> getName();
                file << '\n';
            }
            file <<'\n';
        }
        file.close();
        _ptrLog -> writeLogFile( " Zaktualizowano plik Konfiguracyjny sieci czujników! ");
    }
}

void iThread::detection()
{
    string bufor,sensorName;
    ifstream file("newSensor.txt",ios::in);
    if(file.good())
    {
        file.seekg(0,file.end);
        int num = file.tellg();
        file.seekg(0,file.beg);
        if(num>1)
        {
            while(getline(file,bufor,' '))
            {
                system("cls");
                if(bufor=="temp"||
                        bufor=="hum"||
                        bufor=="light"||
                        bufor=="door"||
                        bufor=="win"||
                        bufor=="Co2"||
                        bufor=="onn/off"||
                        bufor=="move")
                {
                    cout<<"Wykryto nowy czujnik typu "<<bufor<< endl<<"Wprowadz dla niego nazwe: ";
                    cin.ignore(0);
                    getline(cin,sensorName);
                    _ptrSC.addNewSensor(bufor, make_shared<Sensor>(sensorName));
                    _ptrLog->writeLogFile("Dodano nowy czujnik typu: "+bufor);
                    newSensor = true;
                }
                else
                {
                    cout<<"Blad zly sensor"<<endl;
                    Sleep(1500);
                    _ptrLog->writeLogFile("Blad ---- Zly sensor"+bufor);
                }
            }
        }
        file.close();
        ofstream file("newSensor.txt",ios::out|ios::trunc);
        file.close();
    }
    else
    {
        cout<<"Blad detekcji sensora"<<endl;
        Sleep(1100);
        _ptrLog->writeLogFile("Blad detekcji sensora");
    }
}
void iThread::readConfigFile()
{
    bool temp;
    ifstream file("SensorsConfigFile.txt",ios::in);
    if(file.good())
    {
        string bufor,key2,timeBufor2,name2;
        while(getline(file,bufor,' '))
        {
            if(bufor[0]>=48 && bufor[0]<=57)
            {
                string timeBufor(bufor.begin()+1,bufor.end()-1);
                timeBufor2=timeBufor;
            }
            if(bufor[0]=='*')
            {
                string key(bufor.begin()+1,bufor.end());
                key2=key;
            }
            if(bufor[0]=='[')
            {
                string name(bufor.begin()+1,bufor.end()-1);
                name2=name;
                _ptrSC.addNewSensor(key2,make_shared<Sensor>(name2));
                this->loadConfig = true;
            }
        }
        _ptrLog->writeLogFile("Wczytano konfiguracje sieci czujników z dnia "+timeBufor2);
        file.close();
    }
    else
    {
        cout<<"Blad/Brak pliku konfiguracyjnego"<<endl;
        _ptrLog->writeLogFile("Nie znaleziono pliku konfiguracyjnego");
    }
}
void iThread::showList()const
{
    _ptrSC.showList();
    system("pause");
    system("cls");

    loadConfig=false;
    newSensor = false;
}
iThread::~iThread()
{
}
