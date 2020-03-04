#include<bits/stdc++.h>
using namespace std;

class BoxWithFixedHeight{
    const int height;
    int length;
    int width;
    int volume;
public:
    BoxWithFixedHeight(): height(10){
        width = 5;
        volume = 250;
    }
    BoxWithFixedHeight(int length = 5, int width = 5): height(10){
        volume = 250;
        if(length + width != 10){
            cout << "Error, the lateral area must be 200 square centimeters.\n";
            cout << "(length + width must be 10.\n)";
            exit(-1);
        }
    }
    int cal_volume();
    int set_length(int new_l);
    ~BoxWithFixedHeight(){};
};

int BoxWithFixedHeight:: cal_volume(){
    return volume;
}

int BoxWithFixedHeight:: set_length(int new_l){
    if(new_l == 5){
        cout << "The previous length is 5, check your input.\n";
        return -1;
    }
    else if(new_l <= 0 || new_l >= 10){
        cerr << "The new length is out of range.Check your input.(0 < x < 10)\n";
        return -1;
    }
    else{
        length = new_l;
        width = 10 - length;
        volume = length * width * 10;
        return 0;
    }
}
