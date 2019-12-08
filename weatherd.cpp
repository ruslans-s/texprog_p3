#include "weatherd.h"

WeatherD::WeatherD()
{

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
