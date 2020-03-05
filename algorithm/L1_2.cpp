#include<bits/stdc++.h>
using namespace std;

/*
给定一个 int 数组 arr，元素按照升序排列且各不相同。另外有一个目标数 c，请你找出 arr 中所有的数对 a, b，使得 a + b = c。

输入
输入为三行，第一行为 arr 的元素个数，第二行为 arr，元素以空格分隔，第三行为目标数 c。

输出
所有符合条件的数对 a, b。a 和 b 以空格分开，每个数对占据一行。每行中 a  b，所有数对以它的第一个数（也就是 a 的值）升序排列。
*/

int main(){
    int n, c;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> c;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(a[i] + a[j] == c) cout << a[i] << " " << a[j] << "\n";
            if(a[i] + a[j] > c) break;
        }
        if(a[i] > c) break;
    }
    return 0;
}