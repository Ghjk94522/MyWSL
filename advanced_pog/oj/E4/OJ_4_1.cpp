#include"OJ_4_1.h"
using namespace std;

double NormalTruck:: cost(int targetDistance, int weight){
    if(targetDistance > maxDis) return -1;
    return (double) targetDistance * weight;
}

double NormalTruck:: price(int targetDistance){
    if(targetDistance > maxDis) return -1;
    int res = 5 * targetDistance;
    if(res < 100) return 100.0;
    else return (double)res;
}

void NormalTruck:: transport(int targetDistance, int weight){
    totalIncome += price(targetDistance);
    totalCost += cost(targetDistance, weight);
}

double AdvancedTruck:: cost(int targetDistance, int weight){
    return (double)50 + targetDistance * weight;
}

double AdvancedTruck:: price(int targetDistance){
    int res = 8 * targetDistance;
    if(res < 150) return 150.0;
    else return (double)res;
}

void AdvancedTruck:: transport(int targetDistance, int weight){
    totalIncome += price(targetDistance);
    totalCost += cost(targetDistance, weight);
}

double LongDistanceTruck:: price(int targetDistance){
    double res = 8 * targetDistance;
    if(res < 150) res = 150.0;
    if(targetDistance < 30) res *= 1.1;
    else res *= 0.9;
    return res;
}

void LongDistanceTruck:: transport(int targetDistance, int weight){
    totalIncome += price(targetDistance);
    totalCost += cost(targetDistance, weight);
}

double LongDistanceTruck:: cost(int targetDistance, int weight){
    return (double)50 + targetDistance * weight;
}