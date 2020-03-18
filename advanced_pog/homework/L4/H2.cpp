#include<bits/stdc++.h>
#define FOR_TEST
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
    void swap(int x, int y){
        x ^= y;
        y ^= x;
        x ^= y;
    }
    void swap(Date& x, Date& y){
        swap(x.year, y.year);
        swap(x.month, y.month);
        swap(x.day, y.day);
    }
    Date& operator ++ ();
    const Date operator ++(int);
    Date& operator -- ();
    const Date operator --(int);
    const Date operator - (int x);
    const Date operator + (int x);
    int operator - (Date d);
};


void Date:: output(string s){
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

const Date Date:: operator - (int x){
    Date temp = *this;
    temp.day -= x;
    if(x >= 1) return temp;
    // when day <= 0
    while(temp.day <= 0){
        temp.month--;
        int t = temp.year;
        if(temp.month = 0){
            temp.month = 12;
            temp.year--;
            t--;
        }
        temp.day = temp.day + ((t % 4 == 0 && t % 100 != 0) ? lm[temp.month] : nm[temp.month]);
    }
    return temp;
}

const Date Date:: operator + (int x){
    Date temp = *this;
    temp.day += x;
    int t = temp.year;
    if(t % 4 == 0 && t % 100 != 0){
        // the condition : leap year
        if(temp.day <= lm[temp.month]) return temp;
        while(temp.day > lm[temp.month]){
            temp.day -= lm[temp.month];
            temp.month++;
            if(temp.month == 13){
                temp.month = 1;
                temp.year++;
            }
        }
        return temp;
    }
    else{
        // the condition : normal year
        if(temp.day <= nm[temp.month]) return temp;
        while(temp.day > nm[temp.month]){
            temp.day-= nm[temp.month];
            temp.month++;
            if(temp.month == 13){
                temp.month = 1;
                temp.year++;
            }
        }
        return temp;
    }
}

int Date:: operator - (const Date x){
    Date t = *this, d = x;
    // make sure the t >= d
    if(year < d.year){
        swap(t, d);
    }
    else if(year == d.year && month < d.month){
        swap(t, d);
    }
    else if(year == d.year && month == d.month && day < d.day){
        swap(t, d);
    }

    // check if the year is the leap year
    // if leap year flag -> 1 else 0
    int flag = 0;
    if(t.year % 4 == 0 && t.year % 100 != 0) flag = 1;

    // calculate the year pay attention to leap year
    int res = 0;
    if(t.year == d.year) res += 0;
    else{
        // condition : t.year > d.year

        // process the day
        if(t.day >= d.day) res += (t.day - d.day);
        else{
            // condition : t.year > d.year but t.day < d.day
            t.month--;
            if(t.month == 0){
                t.year--;
                t.month = 1;
            }
            if(flag == 1)
                // condition : leap year
                t.day += lm[t.month];
            else 
                // condition : normal year
                t.day += nm[t.month];
            res += (t.day - d.day);
            // t.day -= d.day;
        }

        // process the month
        if(t.month >= d.month){
            if(flag == 1){
                // condition : leap year
                while(t.month > d.month){
                    res += lm[d.month];
                    d.month++;
                }
            }
            else{
                // condition : normal year
                while(t.month > d.month){
                    res += nm[d.month];
                    d.month++;
                }
            }
        }
        else{
            // condition : t.month < d.month
            t.year--;
            t.month += 12;
            if(flag == 0){
                while(t.month > d.month){
                    if(d.month > 12) res += nm[d.month%13 + 1];
                    else res += nm[d.month];
                    d.month++;
                }
            }
            else{
                while(t.month > d.month){
                    if(d.month > 12) res += lm[d.month%13 + 1];
                    else res += lm[d.month];
                    d.month++;
                }
            }
        }

        // process the year
        while(t.year > d.year){
            if(d.year % 4 == 0 && d.year % 100 != 0) res += 366;
            else res += 365;
            d.year++;
        }
        return res;
    }
    // condition : t.year = d.year and check month and day
    if(t.month == d.month) res += 0;
    else{
        // condiotion : t.year = d.year but t.month > d.month

        // process the day
        if(t.day >= d.day) res += (t.day - d.day);
        else{
            t.month--;
            if(t.month == 0) t.month = 12;
            if(flag == 1) t.day += lm[t.month];
            else t.day += nm[t.month];
            res += (t.day - d.day);
        }

        // process the month
        while(t.month > d.month){
            if(flag == 0) res += lm[d.month];
            else res += nm[d.month];
            d.month++;
        }
        return res;
    }
    // condition : t.month = d.month and check day
    res += (t.day - d.day);
    return res;
}


#ifdef FOR_TEST

int main(){
    // test all the overload operator and try to test 
    // the most conditions here
    Date test(2020, 3, 18);
    cout << "The object for test is "; test.output();
    test++;
    cout << "After the ++ the date becomes "; test.output();
    test--;
    cout << "After the -- the date becomes "; test.output();
    test = test + 10;
    cout << "After the + 10 the date becomes "; test.output(); 
    test = test -5;
    cout << "After the - 5 the date becomes "; test.output();
    Date test_2(2000, 2, 28);
    int res = test - test_2;
    cout << "The result of - is " << res << endl;
    return 0;
}

#endif