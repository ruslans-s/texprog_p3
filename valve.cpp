#include "valve.h"

valve::valve()
{
};
bool valve::chekopened() {
    return opened;
};
void valve::open() {
    opened = true;
};
void valve::close() {
    opened = false;
};
void valve::getwaittime(int nwaittime){
    waittime=nwaittime;
};
void valve::chekwaittime(int wwaittime) {
if (wwaittime>=waittime){
    opened= true;
}};
void valve::setTimeCheker(){
timeCheker=true;

};
