#include<bits/stdc++.h>
#include"OJ_3_1.h"
// #define FOR_TEST
// #define ANOTHER_TEST
using namespace std;

Polynomial Polynomial:: operator + (const Polynomial& p) const{
    int tn = 0;
    (this->n > p.n) ? (tn = this->n) : (tn = p.n);
    double *tw = new double[tn];
    int i = 0;
    for( ; i < tn; i++){
        if(i < p.n && i < this->n)
            tw[i] = this->w[i] + p.w[i];
        else break;
    }
    if(i >= p.n){
        for( ; i < tn; i++) tw[i] = this->w[i];
    }
    else if(i >= this->n){
        for( ; i < tn; i++) tw[i] = p.w[i];
    }
    Polynomial res(tw, tn);
    return res;
}

Polynomial Polynomial:: operator + (int x) const{
    Polynomial res;
    if(n == 0){
        res.n = 1;
        res.w = new double[1];
        res.w[0] = x;
        return res;
    }
    else{
        res = *this;
        res.w[0] += x;
        return res;
    }
}

Polynomial Polynomial:: operator + (double x) const{
    Polynomial res;
    if(n == 0){
        res.n = 1;
        res.w = new double[1];
        res.w[0] = x;
        return res;
    }
    else{
        res = *this;
        res.w[0] += x;
        return res;
    }
}

Polynomial Polynomial:: operator * (const Polynomial& p) const{
    int tn = this->n + p.n - 1;
    double *tw = new double [tn];
    for(int i = 0; i < tn; i++) tw[i] = 0;
    for(int i = 0; i < this->n; i++){
        for(int j = 0; j < p.n; j++){
            tw[i+j] = tw[i+j] + this->w[i] * p.w[j];
        }
    }
    Polynomial res(tw, tn);
    return res;
}

Polynomial Polynomial:: operator ^ (int x) const{
    Polynomial res;
    if(x == 0) {
        res.n = 1;
        res.w = new double[1];
        res.w[0] = 1;
        return res;
    }
    else if(x == 1) {
        res = *this;
        return res;
    }
    else if(x < 0){
        cerr << "Wrong with ^ input.\n";
        exit(-1);
    }
    else{
        res = *this;
        for(int i = 2; i <= x; i++){
            res = res * *this;
        }
        return res;
    }
}

Polynomial Polynomial:: operator () (const Polynomial& p) const{
    int tn = (n-1) * (p.n-1) + 1;
    double *tw = new double [tn];
    Polynomial res;
    for(int i = 0; i < n; i++){
        Polynomial temps;
        temps = (p^i);
        Polynomial temp; temp = temps;
        for(int k = 1; k < w[i]; k++){
            temps = temps + temp;
        }
        if(w[i] == 0) res = res;
        else res = res + temps;
    }
    return res;
}

double Polynomial:: operator () (double x) const{
    double res = 0;
    for(int i = 0; i < n; i++){
        res += (w[i] * pow(x, i));
    }
    return res;
}

double Polynomial:: derivative(double x) const{
    double res = 0;
    for(int i = 1; i < n; i++){
        res += (w[i] * pow(x, i-1));
    }
    return res;
}

void Polynomial:: print(){
    printf("Debug : the polynomial is : \n\tf(x) = ");
    int i = 0;
    for( ; i < n-1; i++){
        printf("%f x^%d + ", w[i], i);
    }
    printf("%f x^%d\n", w[i], i);
}

#ifdef FOR_TEST

int main(){
    double sw[] = {12, 3, 4.5, 6, 789, 10.11};
    Polynomial test(sw, 6);
    test.print();
    double sw2[] = {98, 7.6, 5, 43.21, 0};
    Polynomial test2(sw2, 5);
    test2.print();
    Polynomial test3 = test + test2;
    test3.print();
    Polynomial test4 = test * test2;
    test4.print();
    Polynomial test5 = test(test2);
    test5.print();
    double res1 = test(2);
    cout << "res1 = " << res1 << "\n";
    double res2 = test.derivative(2);
    cout << "res2 = " << res2 << "\n";
    return 0;
}

#endif

#ifdef ANOTHER_TEST

int main(){
    double sw[] = {1,2,3};
    Polynomial test(sw, 3);
    double res1 = test(2);
    cout << "res1 = " << res1 << "\n";
    double res2 = test.derivative(2);
    cout << "res2 = " << res2 << "\n";
    return 0;
}

#endif