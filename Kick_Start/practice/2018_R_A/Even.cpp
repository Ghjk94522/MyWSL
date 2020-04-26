#include<bits/stdc++.h>
#define ll long long
using namespace std;

// The function below is from the lecture and I just copy it
ll getPre(long long n){
    int cnt = 0;
    int num[20];
    do{
        num[cnt++] = n%10;
        n /= 10;
    } while(n);
    for(int i = cnt-1; i >= 0; i--){
        if(num[i]&1){
            num[i]--;
            for(int j = i - 1; j >= 0; j--){
                num[j] = 8;
            }
            break;
        }
    }
    ll ans = 0;
    for(int i = cnt-1; i >= 0; i--){
        ans = ans*10 + num[i];
    }
    return ans;
}

// This function is created by myself


int main(){

}

