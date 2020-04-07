#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> test;
    for(int i = 1; i < 100; i = i*2) test.push_back(i);
    for(int i = 0; i < test.size(); i++) cout << test[i] << "\t";
    test.erase(test.end()-1);
    for(int i = 0; i < test.size(); i++) cout << test[i] << "\t";
    return 0;
}
