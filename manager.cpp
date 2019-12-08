#include "manager.h"

manager::manager(){
}
void manager::settings(int newtimework,int ntact, QVector<int> newtimeworkEvm)
{

timework=newtimework;
tact=ntact;
//timeworkevm=newtimeworkEvm;
//EVMlist.resize(2);
for(int i=0;i<=newtimeworkEvm.size()-1;i++){
   EVMlist.resize(EVMlist.size()+1);
   EVMlist[i].setsetting(newtimeworkEvm[i],tact);
}
ValveList.resize(3);
}

