#include<bits/stdc++.h>
using namespace std;

const int lm[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int nm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date{
    int year;
    int month; 
    int day;
public:
    Date(){
        year = 0; 
        month = 0;
        day = 0;
    }
    Date(int x, int y, int z){
        year = x;
        month = y;
        day = z;
    }
    void output(string s = "");
    bool is_31m(int m){
        if(m == 1 || m == 3 || m == 5 || m == 7)
            return true;
        if(m == 8 || m == 10 || m == 12)
            return true;
        if(m != 2) return false;
        if(m == 2){
            cerr << "Fre is being input, the process return and check\n";
            exit(-1);
        }
    }
    Date& operator ++ ();
    const Date operator ++(int);
    Date& operator -- ();
    const Date operator --(int);
    const Date operator - (int x);
};

void Date:: output(string s = ""){
    if(s == "" || s == "y-m-d"){
        printf("%d-%d-%d\n", year, month, day);
        return;
    }
    else if(s == "m-d-y"){
        printf("%d-%d-%d\n", month, day, year);
        return;
    }
    else if(s == "year-month-day"){
        printf("%d year\t%d month\t%d day\n", year, month, day);
        return;
    }
    else if(s == "y/m/d"){
        printf("%d/%d/%d\n", year, month, day);
        return;
    }
    else if(s == "m/d/y"){
        printf("%d/%d/%d\n", month, day, year);
        return;
    }
}

Date& Date:: operator ++(){
    day++;
    if(month == 2){
        if(year % 4 == 0 && year % 100 != 0){
            // condition : leap year
            if(day <= 29) return *this;
            else{
                month++;
                day = 1;
                return *this;
            }
        }
        else{
            // condition : normal year
            if(day <= 28) return *this;
            else{
                month++;
                day = 1;
                return *this;
            }
        }
    }
    else{
        // month not equal to Frebrary
        if(is_31m(month) == true){
            // month that has 31 days
            if(day <= 31) return *this;
            else{
                if(month == 12){
                    // pay attention to the year changement
                    year++;
                    month = 1;
                    day = 1;
                }
                else{
                    month++;
                    day = 1;
                }
                return *this;
            }
        }
        else{
            // month that has 30 days
            if(day <= 30) return *this;
            else{
                month++;
                day = 1;
                return *this;
            }
        }
    }
}

const Date Date:: operator ++(int){
    Date temp = *this;
    day++;
    if(month == 2){
        if(year % 4 == 0 && year % 100 != 0){
            // condition : leap year
            if(day <= 29) return temp;
            else{
                month++;
                day = 1;
                return temp;
            }
        }
        else{
            // condition : normal year
            if(day <= 28) return temp;
            else{
                month++;
                day = 1;
                return temp;
            }
        }
    }
    else{
        // month not equal to Frebrary
        if(is_31m(month) == true){
            // month that has 31 days
            if(day <= 31) return temp;
            else{
                if(month == 12){
                    // pay attention to the year changement
                    year++;
                    month = 1;
                    day = 1;
                }
                else{
                    month++;
                    day = 1;
                }
                return temp;
            }
        }
        else{
            // month that has 30 days
            if(day <= 30) return temp;
            else{
                month++;
                day = 1;
                return temp;
            }
        }
    }
}

Date& Date:: operator -- (){
    day--;
    if(day != 0) return *this;
    else{
        // change the month
        if(month == 3){
            // the pre-month is Frebrary
            if(year % 4 == 0 && year % 100 != 0){
                // the leap year
                month--;
                day = 29;
            }
            else{
                // the normal year
                month--;
                day = 28;
            }
            return *this;
        }
        else if(month == 1){
            year--;
            month = 12;
            day = 31;
            return *this;
        }
        else{
            month--;
            if(is_31m(month-1) == true){
                day = 31;
            }
            else day = 30;
            return *this;
        }
    }
}

const Date Date:: operator --(int){
    Date temp = *this;
    day--;
    if(day != 0) return temp;
    else{
        // change the month
        if(month == 3){
            // the pre-month is Frebrary
            if(year % 4 == 0 && year % 100 != 0){
                // the leap year
                month--;
                day = 29;
            }
            else{
                // the normal year
                month--;
                day = 28;
            }
            return temp;
        }
        else if(month == 1){
            year--;
            month = 12;
            day = 31;
        }
        else{
            month--;
            if(is_31m(month-1) == true){
                day = 31;
            }
            else day = 30;
        }
        return temp;
    }
}

const Date Date::operator - (int x){
    Date temp = *this;
    temp.day -= x;
    if(x >= 1) return temp;
    else{
        
    }
}