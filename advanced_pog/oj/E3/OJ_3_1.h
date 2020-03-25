#pragma once
#include<bits/stdc++.h>
using namespace std;

class Polynomial{
    double *w;
    int n;
public:
    Polynomial(){
        w = NULL;
        n = 0;
    }
    Polynomial(const Polynomial& p){
        n = p.n;
        w = new double[n];
        for(int i = 0; i < n; i++){
            w[i] = p.w[i];
        }
    }
    Polynomial(const double w[], const int n){
        this->n = n;
        this->w = new double[n];
        for(int i = 0; i < n; i++){
            this->w[i] = w[i];
        }
    }
    Polynomial operator ^(int x) const;
    Polynomial operator +(const Polynomial& p) const;
    Polynomial operator +(double x) const;
    Polynomial operator +(int x) const;
    Polynomial operator *(const Polynomial& p) const;
    Polynomial operator ()(const Polynomial& p) const;
    double operator ()(double x) const;
    double derivative(double x) const;
    void print();
};