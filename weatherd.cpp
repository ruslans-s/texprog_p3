#include "weatherd.h"

WeatherD::WeatherD()
{
waitingtime=0;
succes=false;
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
void WeatherD::setSucces(){
    succes=true;
}
