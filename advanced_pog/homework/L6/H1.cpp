#include<bits/stdc++.h>
using namespace std;

class Car{
public:
    void drive(float fRadian, float fSpeed, float fDeltaTime){
        printf("Driving...\nRadion : %f\nSpeed : %f\nDeltaTime : %f\n", fRadian, fSpeed, fDeltaTime);
    }
};

class AutopilotCar: public Car{
public:
    void autoDrive(){
        printf("autoDriving...\n");
    }
};

class UpgradeAutopilotCar: protected Car{
public:
    void autoDrive(){
        printf("autoDriving...\n");
    }
    void optimizedDrive(float fRadian, float fSpeed, float fDeltaTime){
        srand(time(NULL));
        fRadian += rand()%5;
        fSpeed -= rand()%10;
        fDeltaTime -= rand()%3;
        drive(fRadian, fSpeed, fDeltaTime);
    }
};

class PerfactCar : private Car{
public :
    void autoDrive(){
        printf("autoDriving...\n");
    }
};

int main(){
    AutopilotCar testCar;
    cout << "Mode : auto \n";
    testCar.autoDrive();
    cout << "Mode : drive, input the status: ";
    float r, s, d;
    cin >> r >> s >> d;
    testCar.drive(r, s, d);

    UpgradeAutopilotCar testUpCar;
    testUpCar.optimizedDrive(r, s, d);

    PerfactCar testPerCar;
    testPerCar.autoDrive();

    return 0;
}