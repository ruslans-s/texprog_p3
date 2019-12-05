#include "queue.h"

queue::queue()
{

}
bool queue::chekWeatherD() {
    if (WeatherDlist.size() > 0) {
        return true;
    } else {
        return false;
    }
}
int queue::numberWeatherD() {
    return WeatherDlist.size();
}
void queue::addWeatherD() {
    WeatherDlist.resize(WeatherDlist.size()+1);

}
bool queue::removeWeatherD() {
    if (WeatherDlist.size() > 0) {
        WeatherDlist.pop_front();
        return true;
    }
    else {
        return false;
    }
}
void queue::tic(QVector<valve> ValveList){
for(int i=ValveList.size()-1;i>=0;i--){
    if(i=ValveList.size()-1){
        ValveList[i].chekwaittime(WeatherDlist[0].getwaitingtime());
    }
    ValveList[i].chekopened();
}
}
