#ifndef VALVE_H
#define VALVE_H


class valve
{
protected:
    bool opened;
    int waittime;
public:
    valve();
    bool chekopened();
    void open() ;
    void close();
    void getwaittime(int);
    void chekwaittime(int);

};

#endif // VALVE_H
