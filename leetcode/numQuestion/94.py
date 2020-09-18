'''
给定一个二叉树，返回它的中序 遍历。

比如：
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]

'''

from typing import List

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.res = list()

# 递归算法
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        else:
            return self.inorderTraversal(root.left) + [root.val] + self.inorderTraversal(root.right)


# 迭代算法
    def inorderTraversal1(self, root: TreeNode) -> List[int]:
        pass