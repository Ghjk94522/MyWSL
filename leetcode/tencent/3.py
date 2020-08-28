'''
找出给定字符串中的最长回文串
后一种方法一般不要求熟练掌握
'''

class Solution:
    # dp
    def longestPalindrome_dp(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        ans = ""
        for i in range(n):
            for j in range(n):
                l = j + 1
                if l >= len(s):
                    break
                if i == 0:
                    dp[j][l] = True
                elif i == 1:
                    dp[j][l] = (s[j] == s[l])
                else:
                    dp[j][l] = (dp[j+1][l-1] and s[j] == s[l])
                if dp[j][l] = and i + 1 > len(ans):
                    ans = s[i:j+1]
        return ans

    def
    
    # Manacher
    def expand(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return (right - left - 2) // 2

    def longestPalindrome_man(self, s: str) -> str:
        end, start = -1, 0
        s = '#' + '#'.join(list(s)) + '#'
        arm_len = []
        right = -1
        j = -1
        for i in range(len(s)):
            if right >= i:
                i_sym = 2 * j - i
                min_arm_len = min(arm_len[i_sym], right - i)
                cur_arm_len = self.expand(s, i - min_arm_len, i + min_arm_len)
            else:
                cur_arm_len = self.expand(s, i, i)
            arm_len.append(cur_arm_len)
            if i + cur_arm_len > right:
                j = i_sym
                right = i + cur_arm_len
            if 2 * cur_arm_len + 1 > end - start:
                start = i - cur_arm_len
                end = i + cur_arm_len
        return s[start+1 : end+1 : 2]