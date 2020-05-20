#include"CarDatabase.h"
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void CarDatabase::read(){
    list.clear();
    ifstream in;
    in.open(path, ios::in);
    int n; in >> n;
    for(int i = 0; i < n; i++){
        string c, t;
        int d;
        CarRecord temp;
        in >> c >> d >> t;
        temp.set(c, d, t);
        list.push_back(temp);
    }
}

void CarDatabase::add(CarRecord cr){
    for(int i = 0; i < list.size(); i++){
        if(list[i] == cr){
            return;
        }
    }
    list.push_back(cr);
    ofstream out;
    out.open(path, ios::out|ios::trunc);
    out << list.size() << endl;
    for(int i = 0; i < list.size(); i++){
        out << list[i].getCar() << "\t" << list[i].getDate()
            << "\t" << list[i].getTime() << "\n";
    }
    out.close();
}

void CarDatabase::del(string car){
    for(int i = list.size()-1; i >= 0; i--){
        if(list[i].getCar() == car){
            list.erase(list.begin()+i);
        }
    }
    ofstream out;
    out.open(path, ios::out|ios::trunc);
    out << list.size() << endl;
    for(int i = 0; i < list.size(); i++){
        out << list[i].getCar() << "\t"
            << list[i].getDate() << "\t"
            << list[i].getTime() << "\n";
    }
    out.close();
}

void CarDatabase::del(int date){
    for(int i = list.size()-1; i >= 0; i--){
        if(list[i].getDate() == date){
            list.erase(list.begin()+i);
        }
    }
    ofstream out;
    out.open(path, ios::out|ios::trunc);
    out << list.size() << endl;
    for(int i = 0; i < list.size(); i++){
        out << list[i].getCar() << "\t"
            << list[i].getDate() << "\t"
            << list[i].getTime() << "\n";
    }
    out.close();
}

void CarDatabase::del(string car, int date){
    for(int i = list.size()-1; i >= 0; i--){
        if(list[i].getDate() == date && list[i].getCar() == car){
            list.erase(list.begin()+i);
        }
    }
    ofstream out;
    out.open(path, ios::out|ios::trunc);
    out << list.size() << endl;
    for(int i = 0; i < list.size(); i++){
        out << list[i].getCar() << "\t"
            << list[i].getDate() << "\t"
            << list[i].getTime() << "\n";
    }
    out.close();
}

void CarDatabase::del(string car, int date, string time){
    for(int i = list.size()-1; i >= 0; i--){
        if(list[i].getDate() == date && list[i].getCar() == car && list[i].getTime() == time){
            list.erase(list.begin()+i);
        }
    }
    ofstream out;
    out.open(path, ios::out|ios::trunc);
    out << list.size() << endl;
    for(int i = 0; i < list.size(); i++){
        out << list[i].getCar() << "\t"
            << list[i].getDate() << "\t"
            << list[i].getTime() << "\n";
    }
    out.close();
}

void time_s2i(CarRecord &c, int &h, int &m){
    string temp = "";
    int i = 0;
    for(; c.getTime()[i] != ':'; i++){
        temp += c.getTime()[i];
    }
    i++;
    h = stoi(temp);
    temp.clear();
    for(; c.getTime()[i]; i++){
        temp += c.getTime()[i];
    }
    m = stoi(temp);
}

void CarDatabase::del(int date, string time_start, string time_end){
    int s_h = 0, s_m = 0, e_h = 0, e_m = 0;
    string temp = "";
    int i = 0;
    for(; time_start[i] != ':'; i++){
        temp += time_start[i];
    }
    i++;
    s_h = stoi(temp);
    temp.clear();
    for(; time_start[i]; i++){
        temp += time_start[i];
    }
    s_m = stoi(temp);
    temp = "";
    i = 0;
    for(; time_end[i] != ':'; i++){
        temp += time_end[i];
    }
    i++;
    e_h = stoi(temp);
    temp.clear();
    for(; time_end[i]; i++){
        temp += time_end[i];
    }
    e_m = stoi(temp);

    for(int i = list.size()-1; i >= 0; i--){
        if(date == list[i].getDate()){
            int t_h = 0, t_m = 0;
            time_s2i(list[i], t_h, t_m);
            if(t_h <= s_h && t_m <= s_m && t_h >= e_h && t_m >= e_m)
                list.erase(list.begin()+i);
        }
    }
    ofstream out;
    out.open(path, ios::out|ios::trunc);
    out << list.size() << endl;
    for(int i = 0; i < list.size(); i++){
        out << list[i].getCar() << "\t"
            << list[i].getDate() << "\t"
            << list[i].getTime() << "\n";
    }
    out.close();
}

bool cmp(CarRecord a, CarRecord b){
    if(a.getDate() < b.getDate()) return true;
    else if (a.getDate() > b.getDate()) return false;
    else {
        int a_h = 0, b_h = 0;
        int a_m = 0, b_m = 0;
        time_s2i(a, a_h, a_m);
        time_s2i(b, b_h, b_m);
        if(a_h < b_h) return true;
        else if(a_h > b_h) return false;
        else{
            if(a_m < b_m) return true;
            else if(a_m > b_m) return false;
            else{
                if(a.getCar() < b.getCar()) return true;
                else return false;
            }
        }
    }
}

vector<CarRecord> CarDatabase::IndexRecordsByCar(string car){
    vector<CarRecord> res;
    for(int i = 0; i < list.size(); i++){
        if(list[i].getCar() == car) 
            res.push_back(list[i]);
    }
    sort(res.begin(), res.end(), cmp);
    return res;
}

vector<CarRecord> CarDatabase::IndexRecordsByDate(int dat){
    vector<CarRecord> res;
    for(int i = 0; i < list.size(); i++){
        if(list[i].getDate() == dat){
            for(int j = 0; j < res.size(); j++){
                if(res[j].getCar() == list[i].getCar()) {
                    if(false == cmp(list[i], res[j])) res[j] = list[i];
                }
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    return res;
}