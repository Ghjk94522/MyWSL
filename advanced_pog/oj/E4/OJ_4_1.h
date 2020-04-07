#ifndef __TRUCK_H__
#define __TRUCK_H__

class Truck{
    int idNum;
protected:
    double totalCost;
    double totalIncome;
public:
    Truck(int id){
        idNum = id;
        totalCost = 0;
        totalIncome = 0;
        }
    virtual double cost(int targetDistance, int weight) = 0;
    virtual double price(int targetDistance) = 0;
    virtual void transport(int targetDistance, int weight) = 0;
    double getTotalCost() const { return totalCost; }
    double getTotalIncome() const { return totalIncome; }
    int getID() const{ return idNum; }
};

class NormalTruck: public Truck{
    int maxDis;
public:
    NormalTruck(int id, int maxDistance): Truck(id){ 
        maxDis = maxDistance;
    }
    double cost(int targetDistance, int weight);
    double price(int targetDistance);
    void transport(int targetDistance, int weight);
};

class AdvancedTruck: public Truck{
public:
    AdvancedTruck(int id): Truck(id){}
    double cost(int targetDistance, int weight);
    double price(int targetDistance);
    void transport(int targetDistance, int weight);
};

class LongDistanceTruck: public Truck{
public:
    LongDistanceTruck(int id): Truck(id){}
    double cost(int targetDistance, int weight);
    double price(int targetDistance);
    void transport(int targetDistance, int weight);
};

#endif