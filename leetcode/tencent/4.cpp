#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        long long int ans = 0;
        int flag = 0; // 用每一位分别存储状态信息，初始位0000（只用到四位）
        for (int i = 0; i < str.size(); i++)
        {
            if ((flag & 1) == 0 && str[i] == ' ')
                continue;
            flag |= 1; // 此时位0001，代表空字符判断结束
            if ((flag & 14) == 0 && (str[i] == '+' || str[i] == '-'))
            // 14=1110，3个1分别代表出现数字、符号位为“+”和符号位为“-”。显然需要这三位都为0才可以进行符号位判断
            {
                flag |= (str[i] == '-' ? 2 : 4);
                continue;
            }
            if (str[i] >= '0' && str[i] <= '9'){
                flag |= 8;
                ans = 10 * ans + str[i] - '0';
                if (ans > (long long)INT_MAX)
                    return (flag&2) == 2 ? INT_MIN : INT_MAX;
                continue;
            }
            break;
        }
        return (flag&2) == 2 ? -ans : ans;
    }
};