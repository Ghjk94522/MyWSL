#include"CarRecord.h"
#include<bits/stdc++.h>
using namespace std;

void CarRecord::set(string car, int date, string time){
    this->car = car;
    this->date = date;
    this->time = time;
}

string CarRecord::getCar(){
    return car;
}

int CarRecord::getDate(){
    return date;
}

string CarRecord::getTime(){
    return time;
}