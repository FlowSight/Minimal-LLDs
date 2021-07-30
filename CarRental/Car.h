#include"global.h"

namespace carrental{
  std::map<string,int> cartype;
}
class Car{
    public:
    Car(int id,int type,int cost):_id(id),_type(type),_start(-1),_end(-1),_cost(cost){}
    bool book(int st,int ed){
        if(!canBook(st,ed))return false;
        _start=st;_end=ed;
        return true;
    }
    
    bool drop(int time){
        if(time>=_start && time<=_end ){_start=-1,_end=-1;return true;}
        return false;
    }
    bool canBook(int st,int ed){
        return st>=_end || ed<=_start;
    }
    void changeCost(int cost){_cost=cost;}
    
    void stat(){
        cout<<"id: "<<_id<<" type: "<< _type<<" start: "<<_start<<" end: "<<_end<<" cost: "<<_cost<<endl;
    }
    int cost(){return _cost;}
    int type(){return _type;}
    int start(){return _start;}
    int end(){return _end;}
    int id(){return _id;}
    private:
    int _id,_type;
    int _start,_end,_cost;
};
