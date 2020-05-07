#include <bits/stdc++.h>
using namespace std;

class Web
{
    string name;
    int age;
    string number;

public:
    void inputName();
    void inputAge();
    void inputPhone();
    void uploadFile();
    void enroll();
};

void Web::inputName()
{
    string n;
    cin >> n;
    name = n;
}

void Web::inputAge()
{
    int a;
    cin >> a;
    if (a > 18 || a < 11)
    {
        throw(a);
    }
    age = a;
}

void Web::inputPhone()
{
    string n;
    cin >> n;
    bool flag = true;
    for (int i = 0; n[i]; i++)
    {
        if (n[i] >= '0' && n[i] <= '9' || n[i] == '-')
        {
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag == false)
    {
        throw(n);
    }
    number = n;
}

void Web::uploadFile()
{
    cout << "Input the article file path : ";
    string addr;
    cin >> addr;
    ifstream in;
    in.open(addr, ios::in);
    if (in.fail())
    {
        throw(addr);
    }
    vector<string> article;
    string temp;
    while (getline(in, temp))
    {
        article.push_back(temp);
        temp = "";
    }
    in.close();
    cout << "Input the new file path : ";
    cin >> addr;
    ofstream out;
    out.open(addr, ios::out | ios::trunc);
    out << "Name : " << name << "\t"
        << "Age : " << age << "\n"
        << "Number : " << number << "\n\n\tArticle : \n";
    for (int i = 0; i < article.size(); i++)
    {
        out << article[i] << "\n";
    }
    out.close();
}

void Web::enroll()
{
    cout << "Input your name : ";
    inputName();
    cout << "Input your age : ";
    try
    {
        inputAge();
    }
    catch (int age)
    {
        cerr << "Parameter age is out of range.\n";
        exit(-1);
    }
L1:
    try
    {
        inputPhone();
    }
    catch (string s)
    {
        cerr << "The parameter number is wrong and please input again. (The number can only contain 0-9 and '-'\n";
        goto L1;
    }
L2:
    try
    {
        uploadFile();
    }
    catch (string s)
    {
        cerr << "The aritcle path is wrong please check and input again.\n";
        goto L2;
    }
}

int main(){
    
}