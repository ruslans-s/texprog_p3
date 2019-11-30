#ifndef VALVE_H
#define VALVE_H


class valve
{
protected:
    bool opened;
    int waittime;
public:
    valve();
    bool chekopened() {
        return opened;
    }
    void open() {
        opened = true;
    }
    void close() {
        opened = false;
    }
    void getwaittime(int nwaittime){
        waittime=nwaittime;
    }
    void chekwaittime(int wwaittime) {
    if (wwaittime>=waittime){
        opened= true;
    }
    }
};

#endif // VALVE_H
