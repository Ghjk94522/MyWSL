#include"Oj_2_2.h"
#define FOR_TEST
using namespace std;

void Administrator:: addAthlete(Athlete* athlete){
    ath_list.push_back(athlete);
}

int Administrator:: findAthleteByNationality(const char* nationality, Athlete** resultList, int maxNum) const{
    int res = 0;
    for(int i = 0; i < ath_list.size(); i++){
        string temp = ath_list[i]->getNationality();
        if(temp == nationality){
            resultList[res++] = ath_list[i];
        }
        if(res > maxNum) break;
    }
    return res;
}

int Administrator:: findAthleteByVisitedPlace(const char* place, Athlete** resultList, int maxNum) const{
    int res = 0;
    for(int i = 0; i < ath_list.size(); i++){
        vector<string> temp = ath_list[i]->getCityList();
        for(int j = 0; j < temp.size(); j++){
            if(temp[j] == place){
                resultList[res++] = ath_list[i];
                break;
            }
        }
        if(res > maxNum) break;
    }
    return res;
}

#ifdef FOR_TEST

int main(){
    Administrator *admin = new Administrator;
    Athlete *athlete = new Athlete("James", "America");
    athlete->addVisitedPlace("Tokyo");
    athlete->addVisitedPlace("Washington");
    admin->addAthlete(athlete);
    const int MAXATH = 100;
    Athlete *resultList[MAXATH];
    int resultNum = admin->findAthleteByNationality("America", resultList, MAXATH);
    cout << resultNum << endl;
    for(int i = 0; i < resultNum; i++){
        cout << resultList[i]->getName() << endl;
    }
    return 0;
}

#endif