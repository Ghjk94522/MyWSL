#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp;
    vector<int> src;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        src.push_back(temp);
    }
    vector<int> res = src;
    vector<int> bak = src;
    sort(res.begin(), res.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (src[j] == res[i])
            {
                src[j] = -1;
                res[i] = j+1;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
    int avg = 0;
    for(int i = 0; i < n; i++){
        avg += bak[res[i]-1] * (n-i-1);
    }
    double final = (double)avg / (double)n;
    // cout << "\n" << final;
    printf("\n%.2f", final);
    return 0;
}