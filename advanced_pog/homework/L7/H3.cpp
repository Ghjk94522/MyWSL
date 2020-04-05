#include<bits/stdc++.h>
using namespace std;

class Animal{
    string name;
    double weight;
public:
    Animal(string s, double w){ name = s; weight = w; }
    virtual void sound() = 0;
    void show(){
        printf("Animal's name : %s\tWeight : %f\n", name.c_str(), weight);
    }
};

class Dog: public Animal{
public:
    Dog(string n, double w): Animal(n, w){}
    void sound(){
        cout << "woof woof woof!\n";
    }
};

class Cat: public Animal{
public:
    Cat(string n, double w): Animal(n, w){}
    void sound(){
        cout << "mew~\n";
    }
};

class Cow: public Animal{
public:
    Cow(string n, double w): Animal(n, w){}
    void sound(){
        cout << "mooooooooo\n";
    }
};

int main(){
    string d = "snoopy", ca = "kitty", co = "redBull";
    double dw = 5.0, caw = 2.5, cowe = 1001.2;
    Dog dog(d, dw);
    Cat cat(ca, caw);
    Cow cow(co, cowe);
    dog.show();
    printf("And its' sound is : ");
    dog.sound();
    cat.show();
    printf("And its' sound is : ");
    cat.sound();
    cow.show();
    printf("And its' sound is : ");
    cow.sound();
    return 0;
}