from typing import List

'''
The first version but it changed the index of the origin array
'''
class Solution:
    def __init__(slef):
        pass
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted(nums)
        head = 0
        tail = len(nums)-1
        while(True):
            if nums[head] + nums[tail] == target:
                break
            elif nums[head] + nums[tail] > target:
                tail = tail - 1
            else:
                head = head + 1
        return [head, tail]

'''
The right version 
use a dict to simulate a hashmap
'''
class Solution:
    def __init__(slef):
        pass
    
    ''' This method can be improved by reduce loop to once '''
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, n in enumerate(nums):
            hashmap[n] = i
        for i, n in enumerate(nums):
            if hashmap.get(target-n) is not None and i != j:
                return [i, j]
    
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        for i, n in enumerate(nums):
            if target-n in hashmap:
                return [hashmap[target-n], i]
            else:
                hashmap[n] = i



if __name__ == "__main__":
    