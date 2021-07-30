#include "Car.h"

struct carComp{
  bool operator() (Car c1,Car c2) const {
      if(c1.cost()==c2.cost())return c1.id()<c2.id();
      return c1.cost()<c2.cost();
  }  
};
class Garage{
    public:
    Garage(int id,int x,int y){
        this->id=id;this->x=x;this->y=y;
        cars.clear();
    }
    
    bool book(Car car,int st,int ed){
        if(cars.find(car.type())==cars.end())return false;
        auto type=car.type();
        if(cars[type].find(car)==cars[type].end())return false;
        Car it=*(cars[type].find(car));cars[type].erase(it);
        auto ret=it.book(st,ed);cars[type].insert(it);
        return ret;
    }
    bool addCar(Car c){
        if(cars.find(c.type())!=cars.end() && 
           cars[c.type()].find(c)!=cars[c.type()].end())return false;
        cars[c.type()].insert(c);
        return true;
    }
    
    bool drop(Car car,int time){
        car.drop(time);
        cars[car.type()].insert(car);
        return true;
    }
    vector<Car> search(int type,int st,int ed){
        vector<Car> ans;
        if(cars.find(type)==cars.end())return ans;
        for(auto car:cars[type]){
            if(car.canBook(st,ed))ans.push_back(car);
        }
        return ans;
    }
    void changeCost(int type,int cost){
        for(auto car: cars[type]){
            car.changeCost(cost);
        }
    }
    void stat(){
        cout<<"garage: "<<id<<endl;
        for(auto c:cars){
            cout<<"========type of car: "<<c.first<<" =================";
            for(auto cc:c.second){
                cc.stat();
            }
        }
    }
    int getId(){return id;}
    private:
    int x,y,id;
    unordered_map<int,set<Car,carComp>> cars;
};