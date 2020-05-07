#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
using namespace std;

class ExceptionTest
{
    int prime[100];

public:
    double fraction(double a, double b);
    double logarithm(double a);
    void calPrime(const char *address);
    int getPrime(int i);
};

double ExceptionTest::fraction(double a, double b)
{
    if (b == 0.0)
    {
        cerr << "The parameter b cannot be 0, check it please.\n";
        exit(-1);
    }
    return a / b;
}

double ExceptionTest::logarithm(double a)
{
    if (a < 0)
    {
        cerr << "The parameter a cannot be less than 0.\n";
        exit(-1);
    }
    return log10(a);
}

void ExceptionTest::calPrime(const char *address)
{
    ofstream out;
    out.open(address, ios::out | ios::trunc);
    if (out.fail())
    {
        cerr << "Failed to open the file " << address << endl;
        exit(-1);
    }
    int count = 0;
    int start = 2;
    while (count < 100)
    {
        bool flag = true;
        for (int i = 2; i * i <= start; i++)
        {
            if (start % i == 0)
            {
                start++;
                flag == false;
                break;
            }
        }
        if (flag == false)
            continue;
        else
        {
            prime[count++] = start;
            start++;
        }
    }
    for (int i = 0; i < 100; i++)
    {
        out << prime[i] << endl;
    }
    out.close();
}

int ExceptionTest::getPrime(int i)
{
    if (i > 99 || i < 0)
    {
        cerr << "The parameter i must above 0 and less than 100.\n";
        exit(-1);
    }
    return prime[i];
}