//search(type,start,end) O(no of cars of type) ordered by min cost
// follow up: order by distance
// book(car,start,end) O(1)
// drop(garage,car) O(1)
// garagestat(id,start,end)  O(1)

#include "CarManager.h"

int main() {
    CarManager cm=CarManager();
    User u1=User(1,"anirban"),u2=User(2,"writo");
    cm.addCarType("bike");cm.addCarType("sedan");cm.addCarType("suvx");
    vector<Garage> garages;
    garages.push_back(cm.addGarage(1,1));garages.push_back(cm.addGarage(1,-1));
    garages.push_back(cm.addGarage(-1,-1));garages.push_back(cm.addGarage(-1,1));
    // Add cars
    int carId=0;
    for(auto i=0;i<4;i++){
        for(auto j=0;j<3;j++){
            auto car=Car(carId++,j,rand()%500);
            cm.addCar(move(car),garages[i]);
        }
    }
    cm.garageStat();
    cout<<"====search result for : "<<1<<" "<<12<<" "<<13<<"============"<<endl;
    for(auto c:cm.search(1,11,13,1)){
        c.second.stat();
        if(cm.book(c.first,c.second,11,13,u1))break;
    }
    cout<<"search result for : "<<1<<" "<<12<<" "<<13<<endl;
    for(auto c:cm.search(1,10,12)){
        c.second.stat();
        if(cm.book(c.first,c.second,10,12,u2))break;
    }
    cm.garageStat();
}