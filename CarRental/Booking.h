#include "User.h"
#include "Garage.h"

class Booking{
    public:
    Booking(int id,Car c,User u,Garage g,int st,int ed):_id(id),_c(c),_st(st),_ed(ed),_u(u),_g(g){}
    int st(){return _st;}
    int ed(){return _ed;}
    int id(){return _id;}
  private:
  Car _c;
  int _id,_st,_ed;
  User _u;
  Garage _g;
    
};