#include<bits/stdc++.h>
#include"Oj_2.h"
using namespace std;

class Administrator{
    vector<Athlete *> ath_list;
public:
    Administrator(){};
    void addAthlete(Athlete* athlete);
    int findAthleteByNationality(const char* nationality, Athlete** resultList, int maxNum) const;
    int findAthleteByVisitedPlace(const char* place, Athlete** resultList, int maxNum) const;
};