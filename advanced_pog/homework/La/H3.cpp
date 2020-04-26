#include <bits/stdc++.h>
using namespace std;

class book
{
    string ID;
    string name;
    string author;
    int year;
    // int num;

public:
    book(string id, string n, string a, int y)
    {
        ID = id;
        name = n;
        author = a;
        year = y;
        // num = 0;
    }
    string getID() { return ID; }
    string getName() { return name; }
    string getAuthor() { return author; }
    int getYear() { return year; }
};

class machine
{
    vector<book *> shelf;
    static int tempId;

public:
    void addBook2(int num, string Name, string Author, int Year);
    bool deleteBook(string id);
    bool findBook(string Name);
    void sortByYear();
    void findByAuthor(string Author);
    friend bool sortbyyear(book *a, book *b);
};

void machine::addBook2(int num, string Name, string Author, int Year)
{
    for (int i = 0; i < num; i++)
    {
        book *p = new book(to_string(tempId), Name, Author, Year);
        shelf.push_back(p);
        tempId++;
    }
}

bool machine::deleteBook(string id)
{
    for (int i = 0; i < shelf.size(); i++)
    {
        if (shelf[i]->getID() == id)
        {
            shelf.erase(shelf.begin() + i);
            return true;
        }
    }
    return false;
}

bool machine::findBook(string Name)
{
    bool flag = false;
    for (int i = 0; i < shelf.size(); i++)
    {
        if (shelf[i]->getName == Name)
        {
            flag = true;
            printf("\tName : %s\tID : %s\tAuther : %s\tYear : %d\n", shelf[i]->getName().c_str(),
                   shelf[i]->getID().c_str(), shelf[i]->getAuthor().c_str(), shelf[i]->getYear());
        }
    }
    return flag;
}

bool sortbyyear(book *a, book *b)
{
    return a->getYear() > b->getYear();
}

void machine::sortByYear()
{
    sort(shelf.begin(), shelf.end(), sortbyyear);
    for (int i = 0; i < shelf.size(); i++)
    {
        printf("\tID : %s\tName : %s\tAuthor : %s\tYear : %d\n", shelf[i]->getID().c_str(),
               shelf[i]->getName().c_str(), shelf[i]->getAuthor().c_str(), shelf[i]->getYear());
    }
}

void machine::findByAuthor(string Author)
{
    int num = 0;
    for (int i = 0; i < shelf.size(); i++)
    {
        if (shelf[i]->getAuthor() == Author)
            num++;
    }
    printf("Author %s has %d books.\n", Author.c_str(), num);
}

#ifdef __DEBUG__

// initalize the static data
int machine::tempId = 0x10010;

int main()
{
    
}

#endif