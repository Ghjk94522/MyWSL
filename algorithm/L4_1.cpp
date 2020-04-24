#include <bits/stdc++.h>
// #define __DEBUG__
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> src;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        src.push_back(temp);
    }
    sort(src.begin(), src.end());
    int res = 0;
    for (int i = 0; i < src.size() - 2; i++)
    {
        int j = i + 1;
        int k = src.size() - 1;
        while (j != k)
        {
            if (src[i] + src[j] + src[k] == t)
            {
                ++res;
                j++;
                k--;
            }
            else if (src[i] + src[j] + src[k] < t)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
#ifdef __DEBUG__
    for (int i = 0; i < n; i++)
        cout << src[i] << "\t";
    cout << endl;
#endif
    cout << res << endl;
    return 0;
}