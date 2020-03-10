#include<bits/stdc++.h>
#pragma once
using namespace std;

class Athlete{
    string name;
    string nation;
    vector<string> city_list;
public:
    Athlete(const char* name, const char* nationality){
        this->name = name;
        nation = nationality;
    }
    void addVisitedPlace(const char* place);
    bool checkVisitedPlace(const char* place) const;
    const char* getName() const;
    const char* getNationality() const;
    const vector<string> getCityList() const;
};
