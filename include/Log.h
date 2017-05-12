#ifndef LOG_H
#define LOG_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

class Log
{
    int Day,Month,Year;
    int Hours,Minuts,Seconds;
    time_t rawTime;
    struct tm * timeInfo;
public:
    Log();
    string getTime();
    string getDate();
    string getTimeDate();
    template<class T>
    string ToString(const T &e);
    void writeLogFile(const string& s);
    void getTimeNow();
};
template<class T>
string Log::ToString(const T &e)
{
    std::stringstream ss;
    ss<<e;
    return ss.str();
}
#endif // LOG_H
