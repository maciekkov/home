#include "Log.h"

using namespace std;

Log::Log()
{
    time(&rawTime);
    timeInfo = localtime(&rawTime);
    Day= timeInfo ->tm_mday;
    Month = timeInfo ->tm_mon +1;
    Year = 1900 +timeInfo->tm_year;
    Minuts = timeInfo ->tm_min;
    Hours = timeInfo ->tm_hour;
    Seconds = timeInfo ->tm_sec;
}
string Log::getTime()
{
    return string(Hours<10?"0":"")+ToString(Hours)+":"+
           string(Minuts<10?"0":"")+ToString(Minuts)+":"+
           string(Seconds<10?"0":"")+ToString(Seconds);
}
string Log::getDate()
{
    return string(Day<10?"0":"")+ToString(Day)+"-"+
           string(Month<10?"0":"")+ToString(Month)+"-"+
           string(Year<10?"0":"")+ToString(Year);
}
string Log::getTimeDate()
{
    return string(getTime()+"  "+getDate());
}
void Log::getTimeNow()
{
    cout<<Log().getTime();
}
void Log::writeLogFile(const string& s)
{
        ofstream file("LogFile.txt",ios::app);
         file<<"["<<Log().getTimeDate()<<"]"<<s<<endl<<endl;
        file.close();

}

