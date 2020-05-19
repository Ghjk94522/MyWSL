#ifndef __CAR_H__
#define __CAR_H__

#include<string>
using namespace std;

class CarRecord{
    string car;
    int date;
    string time;
public:
    CarRecord();
    void set(string car,int date,string time);
    string getCar();
    int getDate();
    string getTime();
    bool operator == (CarRecord& a){ return (this->car== a.car) && (this->date == a.date) && (this->time == a.time); }
};

#endif