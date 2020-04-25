#include <bits/stdc++.h>
#define __DEBUG__
using namespace std;

class zoo
{
    map<string, int> animalList;
    int aniTotal;
    int numTotal;

public:
    zoo()
    {
        aniTotal = 0;
        numTotal = 0;
    }
    bool addNewAnimal(string name, int num);
    bool deleteAnimal(string name);
    int findAnimal(string name);
    void zooStatus();
};

bool zoo::addNewAnimal(string name, int num)
{
    if (animalList.count(name))
    {
        printf("Animal %s has already existed.\n", name.c_str());
        return false;
    }
    else
    {
        animalList[name] = num;
        aniTotal++;
        numTotal += num;
        return true;
    }
}

bool zoo::deleteAnimal(string name){
    if(animalList.count(name)){
        numTotal -= animalList[name];
        animalList.erase(name);
        aniTotal--;
        return true;
    }
    else{
        printf("Animal %s doesn't exist.\n", name.c_str());
        return false;
    }
}

int zoo::findAnimal(string name){
    if(animalList.count(name)){
        return animalList[name];
    }
    else{
        return 0;
    }
}

void zoo::zooStatus(){
    printf("Kinds of animals : %d, total animals : %d\n", aniTotal, numTotal);
}

#ifdef __DEBUG__

int main(){
    zoo centerPark;
    centerPark.zooStatus();
    centerPark.addNewAnimal("monkey", 100);
    centerPark.zooStatus();
    centerPark.addNewAnimal("monkey", 20);
    centerPark.addNewAnimal("tiger", 32);
    int tigerNum = centerPark.findAnimal("tiger");
    cout << "tiger : " << tigerNum << endl;
    centerPark.zooStatus();
    centerPark.deleteAnimal("monky");
    centerPark.deleteAnimal("monkey");
    centerPark.zooStatus();
    return 0;
}

#endif