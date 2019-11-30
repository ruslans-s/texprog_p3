#include "generator.h"

Generator::Generator(int newintensity, int newtact){
    intensity = newintensity;
    tact = newtact;
}
void Generator::tic(){
    bool r1= queue.addWeatherD(WeatherD);
    bool r2= queue.addWeatherD(WeatherD);
}
