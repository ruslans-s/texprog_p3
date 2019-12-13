#include "queue.h"

queue::queue()
{

}
bool queue::chekWeatherD() {
    if (WeatherDlist.count() != 0) {
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
    WeatherDlist[WeatherDlist.size()-1].~WeatherD();
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
void queue::tic(){
    if(WeatherDlist.count()>0){
for(int i=0;i<=WeatherDlist.size()-1;i++){
   WeatherDlist[i].tic();
}}}

WeatherD queue::getFirstWeatherD(){
    return WeatherDlist[0];
}


