'''
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

作者：力扣 (LeetCode)
链接：https://leetcode-cn.com/leetbook/read/tencent/xxst6e/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''

from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        