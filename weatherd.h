#ifndef WEATHERD_H
#define WEATHERD_H


class WeatherD
{
protected:
    bool succes;
    int waitingtime;
public:
    WeatherD();
    bool cheksucces();
    void tic();
    int getwaitingtime();
    void setSucces();
  //  void setWaitTime();
};

#endif // WEATHERD_H
