#include<bits/stdc++.h>
using namespace std;

/*
题目描述
给出一串整型数 a1,a2,...,an;以及一个较小的常数 k，找出这串数的中位数m和最接近m的小于等于m的 k 个数，
以及最接近m的大于等于m的 k 个数。将这 2k+1 个数按升序排序后输出。中位数定义：如果数串的大小是偶数 2j，
中位数是从小到大排列的第 j 个数；如果数串的大小是奇数 2j+1，中位数是从小到大排列的第 j+1 个数。

输入
第一行是 k 的值和数串的长度 n。第二行是以空格隔开的 n 个整型数，最后一个数后面有空格。
按升序排列的 2k+1 个数，以空格分开，最后一个数后面没有空格。结果可能出现重复的数。

样例输入
2 10
7 2 5 7 2 10 7 7 13 15

输出
按升序排列的 2k+1 个数，以空格分开，最后一个数后面没有空格。结果可能出现重复的数。

样例输出
5 7 7 7 7
*/

int main(){
    int n, k;
    cin >> k >> n;
    vector<int> a;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    if(n%2 == 0){
        int ind = (n/2 - k - 1);
        for(int i = 0; i <= 2*k; i++)
            cout << a[ind++] << " ";
    }
    else{
        int ind = (n/2 - k);
        for(int i = 0; i <= 2*k; i++)
            cout << a[ind++] << ' ';
    }
    return 0;
}