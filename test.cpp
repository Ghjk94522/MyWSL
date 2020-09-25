#include<iostream>
#include<string>
using namespace std;

#define exp(s) printf("test s is : %s\n", s);
#define exp1(s) printf("test s is : %s\n", #s);
#define exp2(s) #s

int main(){
	exp("hello");
	exp1(hello);
	string str = exp2(bac);
	cout << str << " " << str.size() << endl;

	string str1 = exp2(asda  bas);
	cout << str1 << " " << str1.size() << endl;

	return 0;
}
