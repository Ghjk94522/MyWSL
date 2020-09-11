'''

现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。

你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ones-and-zeroes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

例如：
输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
输出: 4

输入: Array = {"10", "0", "1"}, m = 1, n = 1
输出: 2

解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。

'''

'''
dp 记忆化 01背包
'''

class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        dp = [[0] * (n+1) for _ in range(m+1)]
        for s in strs:
            ones = s.count('1')
            zeros = s.count('0')
            for i in range(m, zero-1, -1):
                for j in range(n, ones-1, -1):
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones])
        return dp[-1][-1]