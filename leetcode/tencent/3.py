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
                k = j + i
                if k >= len(s):
                    break
                if i == 0:
                    dp[j][k] = True
                elif i == 1:
                    dp[j][k] = (s[j] == s[k])
                else:
                    dp[j][k] = (dp[j+1][k-1] and s[j] == s[k])
                if dp[j][k] and i + 1 > len(ans):
                    ans = s[j:k+1]
        return ans

    
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

    # the fastest method in answer of the leetcode
    def longestPalindrome_best(self, s: str) -> str:
        '''
        still need to be read and i don't understand the method
        '''
        if not s:
            return ""
        length = len(s)
        if length == 1 or s == s[::-1]:
            return s 
        max_len, start = 1, 0
        for i in range(1, length):
            even = s[i-max_len : i+1]
            odd = s[i-max_len-1 : i+1]
            if i - max_len >= 0 and even == even[::-1]:
                start = i - max_len
                max_len = max_len + 1
            if i - max_len - 1 >= 0 and odd == odd[::-1]:
                start = i - max_len - 1
                max_len += 2
        return s[start : start + max_len]



if __name__ == '__main__':
    s = Solution()
    ans = s.longestPalindrome_best("asb")
    print(ans)