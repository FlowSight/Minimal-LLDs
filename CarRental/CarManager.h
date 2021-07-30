#include "Booking.h"


using carrental::cartype;

struct garageComp{
  bool operator() (Garage g1,Garage g2) const{
      return g1.getId()<g2.getId();
  }  
};

struct bookingComp{
  bool operator() (Booking b1,Booking b2) const{
      if(b1.st()==b1.st()){
          return b1.ed()==b2.ed()?b1.id()<b2.id():b1.ed()<b2.ed();
      }
      return b1.st()<b2.st();
  }  
};
class CarManager{
    public:
    CarManager(){garages.clear();bookings.clear();}
    // Just books car of 'type' from start to end. Regardless of location.
    // Ordered by price.
    vector<pair<Garage,Car>> search(int type,int st,int ed,int order=-1){
        vector<pair<Garage,Car>> ans;
        for(auto garage:garages){
            for(auto car:garage.search(type,st,ed)){
                ans.push_back({garage,car});
            }
        }
        if(order>0){
            switch(order){
                case 1:
                    sort(ans.begin(),ans.end(),[](auto e1,auto e2){
                        return e1.second.cost()<e2.second.cost();
                    });
                case 2:
                    sort(ans.begin(),ans.end(),[](auto e1,auto e2){
                        return e1.second.start()<e2.second.start();
                    });
                case 3:
                    sort(ans.begin(),ans.end(),[](auto e1,auto e2){
                        return e1.second.end()<e2.second.end();
                    });
            }
        }
        return ans;
    }
    
    Garage addGarage(int x,int y){
        auto garage=Garage(garages.size(),x,y);
        garages.insert(garage);
        return garage;
    }
    
    bool book(Garage garage,Car car,int st,int ed,User user){
        if(garages.find(garage)==garages.end())return false;
        auto b=Booking(bookings.size(),car,user,garage,st,ed);
        Garage it=*(garages.find(garage));garages.erase(it);
        bool ret=it.book(car,st,ed);garages.insert(it);
        if(ret){
            cout<<"Booking ";
            car.stat();
            cout<<"from "<<st<<" to "<<ed<<" for user: ";
            user.stat();
            bookings.insert(b);
        }
        return ret;
    }
    
    bool drop(Booking booking,Car car,Garage garage,int time){
        if(garages.find(garage)==garages.end())return false;
        if(bookings.find(booking)==bookings.end())return false;
        bookings.erase(booking);
        garage.drop(car,time);
        return true;
    }
    
    void garageStat(){
        for(auto g:garages){g.stat();cout<<endl;}
    }
    void addCar(Car car,Garage garage){
        if(garages.find(garage)==garages.end())return;
        Garage it=*(garages.find(garage));garages.erase(garage);
        it.addCar(move(car));garages.insert(it);
    }
    
    void addCarType(string type){
        if(cartype.find(type)!=cartype.end())return;
        cartype[type]=cartype.size();
    }
    private:
    set<Garage,garageComp> garages;
    set<Booking,bookingComp> bookings;
    
};