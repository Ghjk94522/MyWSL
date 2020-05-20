#ifndef __DATABASE_H__
#define __DATABASE_H__

#include<string>
#include<vector>
#include"CarRecord.h"

class CarDatabase{
    string path;
    vector<CarRecord> list;
public:
    CarDatabase(string filename) { path = filename; };
    void read();
    void add(CarRecord cr);
    void del(string car);
    void del(int date);

    void del(string car,int date);

    void del(string car,int date,string time);
    void del(int date,string time_start,string time_end);
    vector<CarRecord> IndexRecordsByCar(string car);
    vector<CarRecord> IndexRecordsByDate(int date);
    friend void time_s2i(CarRecord &c, int &h, int &m);
    friend bool cmp(CarRecord, CarRecord);
};

#endif