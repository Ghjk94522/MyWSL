from typing import List

''' 
    Read the question first !
    Two ordered array !
    use morge sort !
'''

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums = nums1 + nums2
        nums = sorted(nums)
        if len(nums) % 2 == 0:
            return (nums[int(len(nums)/2)] + nums[int(len(nums)/2-1)]) / 2
        else:
            return nums[int(len(nums)//2)]


if __name__ == "__main__":
    s = Solution()
    s.findMedianSortedArrays([12, 34], [56, 78])