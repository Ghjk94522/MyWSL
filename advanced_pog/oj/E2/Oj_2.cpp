#include"Oj_2.h"
// #define FOR_TEST
using namespace std;

void Athlete:: addVisitedPlace(const char* place){
    string temp = place;
    city_list.push_back(temp);
}

bool Athlete:: checkVisitedPlace(const char* place) const{
    string temp = place;
    for(int i = 0; i < city_list.size(); i++){
        if(city_list[i] == temp) return true;
    }
    return false;
}

const char* Athlete:: getName() const{
    return name.c_str();
}


const char* Athlete:: getNationality() const{
    return nation.c_str();
}
const vector<string> Athlete:: getCityList() const{
    return city_list;
}


#ifdef FOR_TEST

int main(){
    Athlete *athlete = new Athlete("James", "America");
    athlete->addVisitedPlace("Tokyo");
    athlete->addVisitedPlace("Washington");
    cout << athlete->getName() << endl;
    cout << athlete->getNationality() << endl;
    bool check = athlete->checkVisitedPlace("Tokyo");
    cout << check << endl;
    return 0;
}

#endif