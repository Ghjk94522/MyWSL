#include<bits/stdc++.h>
using namespace std;

int main(){
	long long src[2000005] = { 0 };
	int m, n;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> src[i];
	for(int i = 0; i < m; i++) {
		int temp; cin >> temp;
		cout << src[temp] << endl;
	}
	return 0;
}
