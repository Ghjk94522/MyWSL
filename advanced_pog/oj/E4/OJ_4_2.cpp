#include"OJ_4_2.h"

void Manager:: addTruck(Truck* t){
    truck.push_back(t);
}

Truck* Manager:: transport(int targetDistance,int weight){
    Truck* res = truck[0];
    double cos = truck[0]->getTotalIncome();
    double pri = truck[0]->price(targetDistance);
    int id = truck[0]->getID();
    for(int i = 1; i < truck.size(); i++){
        if(truck[i]->price(targetDistance) < pri || \
        (truck[i]->price(targetDistance) == pri && truck[i]->getTotalIncome() < cos) || \
        (truck[i]->price(targetDistance) == pri && truck[i]->getTotalIncome() == cos && truck[i]->getID() < id)){
            res = truck[i];
            cos = truck[i]->getTotalIncome();
            pri = truck[i]->price(targetDistance);
            id = truck[i]->getID();
        }
    }
    totalIncome += res->price(targetDistance);
    totalCost += res->cost(targetDistance, weight);
    return res;
}

double Manager:: getAllIncome(){
    return totalIncome;
}

double Manager:: getAllCost(){
    return totalCost;
}