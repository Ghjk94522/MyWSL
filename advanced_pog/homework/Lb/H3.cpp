#include <bits/stdc++.h>
using namespace std;

class Worker
{
    string id;
    string name;
    string number;
    string post;
    string address;

public:
    Worker(string i, string na, string nu, string p, string a)
    {
        id = i;
        name = na;
        number = nu;
        post = p;
        address = a;
    }
    friend ostream &operator<<(ostream &out, const Worker &a);
    string get_id() { return id; }
    void set_name(string s) { name = s; }
    void set_number(string s) { number = s; }
    void set_post(string s) { post = s; }
    void set_address(string s) { address = s; }
};

ostream &operator<<(ostream &out, const Worker &a)
{
    out << a.id << "\t" << a.name << "\t" << a.number << "\t" << a.post << "\t" << a.address;
    return out;
}

class AddressBook
{
    vector<Worker *> book;

public:
    AddressBook()
    {
        ifstream in;
        in.open("./database/workers.txt", ios::in);
        if (in.is_open())
        {
            while (!in.eof())
            {
                string temp;
                getline(in, temp);
                vector<string> l = diviStr(temp);
                Worker *p = new Worker(l[0], l[1], l[2], l[3], l[4]);
                book.push_back(p);
            }
        }
        in.close();
    }
    void NewBook();
    void add(Worker &worker);
    Worker search(string id);
    void modify(Worker &worker);
    friend vector<string> diviStr(string);
    ~AddressBook()
    {
        if (!book.empty())
        {
            ofstream out;
            out.open("./database/workers.txt", ios::out | ios::trunc);
            for (int i = 0; i < book.size(); i++)
            {
                out << *book[i] << "\n";
            }
            out.close();
        }
    }
};

vector<string> diviStr(string s)
{
    vector<string> result;
    string temp;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ')
            temp += s[i];
        else
        {
            result.push_back(temp);
            temp.clear();
        }
    }
    result.push_back(temp);
    return result;
}

void AddressBook::NewBook()
{
    ofstream out;
    // open a new book and if the book exists delete it
    out.open("./database/workers.txt", ios::out | ios::trunc);
    out.close();
    book.clear();
}

void AddressBook::add(Worker &worker)
{
    Worker *p = &worker;
    book.push_back(p);
}

Worker AddressBook::search(string id)
{
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i]->get_id() == id)
            return *book[i];
    }
}

void AddressBook::modify(Worker &worker)
{
    string tar = worker.get_id();
    for (int i = 0; i < book.size(); i++)
    {
        if (book[i]->get_id() == tar)
        {
            int flag = 0;
            cout << "Current status : " << *book[i] << "\n";
            cout << "Input 1 to modify name or 0 to skip : ";
            cin >> flag;
            if (flag = 1)
            {
                string temp;
                cin >> temp;
                book[i]->set_name(temp);
            }
            cout << "Input 1 to modify number or 0 to skip : ";
            cin >> flag;
            if (flag = 1)
            {
                string temp;
                cin >> temp;
                book[i]->set_number(temp);
            }
            cout << "Input 1 to modify post or 0 to skip : ";
            cin >> flag;
            if (flag = 1)
            {
                string temp;
                cin >> temp;
                book[i]->set_post(temp);
            }
            cout << "Input 1 to modify address or 0 to skip : ";
            cin >> flag;
            if (flag = 1)
            {
                string temp;
                cin >> temp;
                book[i]->set_address(temp);
            }
        }
    }
}

int main(){
    AddressBook test;
    // Initial the book and add some records
    printf("Initialize the addressBook : \n");
    printf("Input the num of the workers : ");
    int num; cin >> num;
    for(int i = 0; i < num; i++){
        cout << "ID : ";
        string id;
        cin >> id;
        cout << "Name : ";
        string name;
        cin >> name;
        cout << "Number : ";
        string number;
        cin >> number;
        cout << "Post : ";
        string post;
        cin >> post;
        cout << "Address : ";
        string add;
        cin >> add;
        Worker *p = new Worker(id, name, number, post, add);
        test.add(*p);
    }
    // test search function
    printf("Input the ID you wanna to search : ");
    string t; cin >> t;
    Worker res = test.search(t);
    // test modify function 
    test.modify(res);
    return 0;
}