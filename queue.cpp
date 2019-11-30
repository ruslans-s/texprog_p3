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
bool queue::addWeatherD(WeatherD newWeatherD) {
    WeatherDlist.push_back(newWeatherD);
    return true;
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
