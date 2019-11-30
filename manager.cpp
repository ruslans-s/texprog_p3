#include "manager.h"

manager::manager(int newtimework,int ntact, QVector<int> newtimeworkEvm)
{
timework=newtimework;
tact=ntact;
EVMlist.resize(numberEVM);
for(int i=0;i<=EVMlist.size()-1;i++){
EVMlist[i].setsetting(newtimeworkEvm[i],tact);
}
ValveList.resize(3);
}
