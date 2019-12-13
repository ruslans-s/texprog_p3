#include "weatherd.h"

WeatherD::WeatherD()
{
waitingtime=0;
}
bool WeatherD::cheksucces(){
    return succes;
}
void WeatherD::tic(){
waitingtime++;
}
int WeatherD::getwaitingtime(){
return waitingtime;
}
