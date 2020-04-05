#include<bits/stdc++.h>
using namespace std;

class Student{
protected:
    string name;
    int poScore;
    int enScore;
public:
    Student(string s, int p, int e){
        name = s;
        poScore = p;
        enScore = e;
    }
    virtual int score(){
        double ave = (poScore + enScore) / 2.0;
        double gpa = ave / 20.0;
        printf("The average is : %f, and the gpa is : %f\n", ave, gpa);
        return ave;
    }
    const string get_name() const{ return name; }
};

class ComputerStudent: public Student{
protected:
    int adScore;
public:
    ComputerStudent(string s, int p, int e, int a): Student(s, p, e){ adScore = a; }
    virtual int score(){
        double ave = (poScore + enScore + adScore) / 3.0;
        double gpa = adScore / 20.0;
        printf("The average is : %f, and the gpa is : %f\n", ave, gpa);
        return ave;
    }
};

class AIStudent: public ComputerStudent{
protected:
    int maScore;
public:
    AIStudent(string s, int p, int e, int a, int m): ComputerStudent(s, p, e, a){ maScore = m; }
    int score(){
        double ave = (poScore + enScore + adScore + maScore) / 4.0;
        double gpa = maScore / 20.0;
        printf("The average is : %f, and the gpa is : %f\n", ave, gpa);
        return ave;
    }
};

void display(Student *stu){
    printf("The student %s's scores are : \n", stu->get_name().c_str());
    stu->score();
}

int main(){
    string nor = "Li Hua", com = "Li Lei", ai = "Han Meimei";
    int norp = 78, nore = 82;
    int comp = 83, come = 85, coma = 91;
    int aip = 87, aie = 89, aia = 93, aim = 97;
    Student normalStu(nor, norp, nore);
    ComputerStudent computerStu(com, comp, come, coma);
    AIStudent aiStu(ai, aip, aie, aia, aim);
    display(&normalStu);
    display(&computerStu);
    display(&aiStu);
    return 0;
}