#include<bits/stdc++.h>
using namespace std;

struct Point{
    int x;
    int y;
};

class Circle{
    Point o;
    int r;
public:
    bool PointInCircle(Point p);
    Circle(Point p, int R){
        o = p; r = R;
    }
    friend bool isTrue(Point &rstCenter, int iRadius, Point &p1, Point &p2);
};

bool Circle:: PointInCircle(Point p){
    int temp = (o.x - p.x) * (o.x - p.x) + (o.y - p.y) * (o.y - p.y);
    double d = pow(temp, 0.5);
    if(d >= r) return false;
    else return true;
}

bool isTrue(Point &rstCenter, int iRadius, Point &p1, Point &p2){
    Circle temp(rstCenter, iRadius);
    return temp.PointInCircle(p1) != temp.PointInCircle(p2);
}