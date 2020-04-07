#ifndef __MANAGER_H__
#define __MANAGER_H__

#include<bits/stdc++.h>
#include"OJ_4_1.h"
using namespace std;

class Manager{
    vector<Truck *> truck;
    double totalIncome;
    double totalCost;
public:
    void addTruck(Truck* t);
    Truck* transport(int targetDistance,int weight);
    double getAllIncome();
    double getAllCost();
};

#endif